#include <iostream>
#include <unordered_map>
#include <vector>
#include <thread>

// Базовый класс для команд
class Command
{
public:
    virtual ~Command() = default;
    virtual void execute() = 0; // Метод для выполнения команды
    virtual void undo() = 0; // Метод для отмены выполненной команды
};

// Команды для печати A и B

class TypeACommand : public Command
{
    void execute() override
    {
        std::cout << "Выполнено действие: A" << "\n\n";
    }
    void undo() override
    {
        std::cout << "Отменено действие: A" << "\n";
    }
};
class TypeBCommand : public Command
{
    void execute() override
    {
        std::cout << "Выполнено действие: B" << "\n\n";
    }
    void undo() override
    {
        std::cout << "Отменено действие: B" << "\n";
    }
};

// Команда для печати цифры 1
class TypeDigit1Command : public Command
{
    void execute() override
    {
        std::cout << "Выполнено действие: 1" << "\n\n";
    }
    void undo() override
    {
        std::cout << "Отменено действие: 1" << "\n";
    }
};


class VirtualKeyboard
{
private:
    std::unordered_map<std::string, Command*> keyActions; // Отображение клавиш на команды
    std::vector<std::string> actionHistory; // История выполненных действий

public:
    //деструктор
    ~VirtualKeyboard()
    {
        // Удаляем все команды из памяти
        for (auto it = keyActions.begin(); it != keyActions.end(); ++it)
        {
            delete it->second;
        }
    }

    //назначение команды к определенной клавише
    void assignAction(const std::string& key, Command* action)
    {
        // Удаляем старую команду, если она уже была назначена
        if (keyActions.find(key) != keyActions.end())
        {
            delete keyActions[key];
        }
        // Назначаем новую команду для клавиши
        keyActions[key] = action;
    }

    //обработка нажатия клавиши 
    void pressKey(const std::string& key)
    {
        // Выполняем команду, связанную с клавишей
        if (keyActions.find(key) != keyActions.end())
        {
            keyActions[key]->execute();
            actionHistory.push_back(key); // Добавляем действие в историю
        }
        else
        {
            std::cout << "Клавиша не назначена: " << key << std::endl;
        }
    }

    //отмена последнего действия
    void undoLastAction()
    {
        // Проверяем, есть ли выполненные действия для отмены
        if (!actionHistory.empty())
        {
            // Получаем последнюю нажатую клавишу из истории
            std::string lastKey = actionHistory.back();
            actionHistory.pop_back(); // Удаляем последнее действие из истории

            // Проверяем, было ли назначено действие для последней нажатой клавиши
            if (keyActions.find(lastKey) != keyActions.end())
            {
                // Выполняем метод undo() для последнего действия
                keyActions[lastKey]->undo();
            }
            // Выводим сообщение об отмене действия
            std::cout << "Отменено действие для клавиши " << lastKey << "\n\n";
        }
        else
        {
            // Выводим сообщение, если история действий пуста
            std::cout << "Нет действий для отмены" << "\n\n";
        }
    }


    // Запускаем последовательность действий (Workflow)
    void runWorkflow(const std::vector<std::string>& keys)
    {
        for (const auto& key : keys)
        {
            std::cout << key << std::endl; // Выводим нажатую клавишу
            pressKey(key); // Выполняем действие для клавиши
            std::this_thread::sleep_for(std::chrono::seconds(2)); // Задержка между нажатиями
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    VirtualKeyboard keyboard;

    // Назначаем действия для клавиш
    keyboard.assignAction("A", new TypeACommand());
    keyboard.assignAction("B", new TypeBCommand());
    keyboard.assignAction("1", new TypeDigit1Command());

    // Запускаем Workflow из нажатий клавиш
    std::vector<std::string> keys = { "A", "B", "1" };
    keyboard.runWorkflow(keys);

    std::cout << "-------------------------------------------" << std::endl;

    // Откатываем последнее действие
    keyboard.undoLastAction();
    keyboard.undoLastAction();
    keyboard.undoLastAction();
    keyboard.undoLastAction();

    std::cout << "-------------------------------------------" << std::endl;

    // Переназначаем действия для клавиш
    keyboard.assignAction("A", new TypeDigit1Command()); // A теперь выполняет действие 1
    keyboard.assignAction("B", new TypeACommand()); // B теперь выполняет действие A

    // Запускаем Workflow снова с переназначенными действиями
    keyboard.runWorkflow(keys);

    keyboard.undoLastAction();
    keyboard.undoLastAction();
    keyboard.undoLastAction();

    return 0;
}
