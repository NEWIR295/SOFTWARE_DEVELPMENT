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
