#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Task structure to store task details
struct Task {
    string description;
    bool completed;

    // Constructor to initialize task
    Task(string desc) : description(desc), completed(false) {}
};

// Function to add a new task
void addTask(vector<Task>& tasks) {
    string taskDescription;
    cout << "Enter the task description: ";
    cin.ignore();  // Ignore previous newline character
    getline(cin, taskDescription);  // Get the entire task description
    
    tasks.push_back(Task(taskDescription));  // Add the task to the list
    cout << "Task added successfully.\n";
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& tasks) {
    int taskIndex;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskIndex;

    if (taskIndex < 1 || taskIndex > tasks.size()) {
        cout << "Invalid task number.\n";
    } else {
        tasks[taskIndex - 1].completed = true;
        cout << "Task marked as completed.\n";
    }
}

// Function to remove a task
void removeTask(vector<Task>& tasks) {
    int taskIndex;
    cout << "Enter the task number to remove: ";
    cin >> taskIndex;

    if (taskIndex < 1 || taskIndex > tasks.size()) {
        cout << "Invalid task number.\n";
    } else {
        tasks.erase(tasks.begin() + taskIndex - 1);  // Remove the task from the list
        cout << "Task removed successfully.\n";
    }
}

// Function to view all tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to display.\n";
        return;
    }

    cout << "Your Tasks:\n";
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].description << " [";
        cout << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
}

// Function to display the menu
void displayMenu() {
    cout << "\nTodo List Manager\n";
    cout << "1. Add a Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove a Task\n";
    cout << "5. Exit\n";
    cout << endl;
}


int main() {
    vector<Task> tasks;  // Vector to store the tasks
    int choice;

    // Display initial greeting
    cout << "Welcome to your To-Do List Manager!\n";

    bool flag = true;

    // Run until user decides to exit
    do {
        if(flag) {
            displayMenu();
        }
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);  // Add task
                break;
            case 2:
                viewTasks(tasks);  // View tasks
                break;
            case 3:
                markTaskCompleted(tasks);  // Mark task as completed
                break;
            case 4:
                removeTask(tasks);  // Remove task
                break;
            case 5:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

        flag = false;

        cout << endl;

    } while (choice != 5);  // Exit the program when the user selects 5

    return 0;
}
