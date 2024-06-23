#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task 
{
    string description;
    bool isCompleted;

    Task(const string& desc) : description(desc), isCompleted(false) {}
};

vector<Task> tasks;

void addTask(const string &description) 
{
    tasks.emplace_back(description);
    cout << "Task added successfully." << endl;
}

void viewTasks() 
{
    if (tasks.empty()) 
    {
        cout << "No tasks in the list." << endl;
        return;
    }

    cout << "To-Do List:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) 
    {
        cout << i + 1 << ". " << tasks[i].description
             << " [" << (tasks[i].isCompleted ? "Completed" : "Pending") << "]" << endl;
    }
}

void markTaskAsCompleted(int taskNumber) 
{
    if (taskNumber == 0 || taskNumber > tasks.size()) 
    {
        cout << "Invalid task number." << endl;
        return;
    }

    tasks[taskNumber - 1].isCompleted = true;
    cout << "Task marked as completed." << endl;
}

void removeTask(int taskNumber) {
    if (taskNumber == 0 || taskNumber > tasks.size()) 
    {
        cout << "Invalid task number." << endl;
        return;
    }

    tasks.erase(tasks.begin() + (taskNumber - 1));
    cout << "Task removed successfully." << endl;
}

void displayMenu() 
{
    cout << "\nTo-Do List Manager" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
}

int main() {
    int choice;
    string description;
    size_t taskNumber;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the input buffer

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, description);
                addTask(description);
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                cout << "Enter task number to mark as completed: ";
                cin >> taskNumber;
                markTaskAsCompleted(taskNumber);
                break;
            case 4:
                cout << "Enter task number to remove: ";
                cin >> taskNumber;
                removeTask(taskNumber);
                break;
            case 5:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
