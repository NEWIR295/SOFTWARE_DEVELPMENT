/*
Author: Mohamed Newir
Date: 21/03/2025
File: main.cpp
Description:
            Question 1: 
                Implement a Task Management System that utilizes lambda expressions to: 
                    1.  Task Creation: 
                        o Store a list of tasks with attributes like task ID, description, priority (low, 
                            medium, high), and status (pending, completed). 
                    2.  Task Filtering: 
                        o Use lambda expressions to filter tasks based on priority or status. 
                    3.  Task Sorting: 
                        o Sort tasks by priority and completion status using lambda functions. 
                    4.  Task Completion: 
                        o Mark tasks as completed using a lambda function. 
                    5.  Summary Generation: 
                        o Generate a summary of tasks grouped by status and priority. 

                Requirements 
                    1.  Use std::vector to store tasks. 
                    2.  Define a Task struct with attributes: id, description, priority, and status. 
                    3.  Implement the following functionalities using lambda expressions: 
                        o Add new tasks. 
                        o Filter tasks by priority (low, medium, high) or status (pending, completed). 
                        o Sort tasks by priority or status. 
                        o Mark a specific task as completed. 
                    4.  Display tasks and summaries. 

                Expected Output 
                    1.  Display all tasks after creation. 
                    2.  Filter and display tasks by priority and status. 
                    3.  Display tasks sorted by priority and completion status. 
                    4.  Mark a task as completed and show the updated task list. 
                    5.  Generate and display a summary of tasks grouped by status and priority. 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

struct Task {
    int id;
    std::string description;
    std::string priority; // low, medium, high
    std::string status;   // pending, completed

    void display() const {
        std::cout << "ID: " << id << ", Description: " << description
                << ", Priority: " << priority << ", Status: " << status << std::endl;
    }
};

void display_tasks(const std::vector<Task>& tasks) {
    for (const auto& task : tasks) {
        task.display();
    }
    std::cout << std::endl;
}

enum{LOW, MEDIUM, HIGH};

int main(void){

    std::vector<Task> tasks{
        {1, "Task 1", "high", "pending"},
        {2, "Task 2", "medium", "completed"},
        {3, "Task 3", "low", "pending"},
        {4, "Task 4", "high", "completed"},
        {5, "Task 5", "medium", "pending"}
    };
    
    // 1. Display all tasks after creation
    display_tasks(tasks);
    // 2. Filter tasks by priority
    std::string filter_priority = "high";

    auto filter_tasks = std::count_if(tasks.begin(), tasks.end(),
        [&filter_priority](const Task& task) {
            return task.priority == filter_priority;
        }
    );
    std::cout << "High Priority Tasks Counts: " << filter_tasks << std::endl;
    std::cout << "Filtered Tasks by Priority (" << filter_priority << "):" << std::endl;
    display_tasks(tasks);

    // 3. Sort tasks by priority and completion status
    std::sort(tasks.begin(), tasks.end(),
        [](const Task& t1, const Task& t2){
            if(t1.priority == t2.priority){
                return t1.status < t2.status;
            }
            const std::map<std::string, int> priority_map = {
                {"low", LOW},
                {"medium", MEDIUM},
                {"high", HIGH}
            };
            return priority_map.at(t1.priority) < priority_map.at(t2.priority);
        }
    );

    std::cout << "Sorted Tasks by Priority and Completion Status:" << std::endl;
    display_tasks(tasks);

    // 4. Mark specific task as completed
    int task_id_to_complete = 3;
    auto mark_completed = std::find_if(tasks.begin(), tasks.end(), 
        [task_id_to_complete](const Task& t){
            return t.id == task_id_to_complete;
        }
    );
    if(mark_completed != tasks.end()){
        mark_completed->status = "completed";
    }
    std::cout << "Updated Task List after marking task " << task_id_to_complete << " as completed:" << std::endl;
    display_tasks(tasks);

    // 5. Generate and display a summary of tasks grouped by status and priority
    std::map<std::string, int> summary;

    for(auto &task: tasks){
        summary[task.status]++;
    }
    std::cout << "Summary of Tasks Grouped by Status:" << std::endl;
    for(const auto& [status, count] : summary){
        std::cout << status << " : " << count << std::endl;
    }
    std::cout << std::endl;

}