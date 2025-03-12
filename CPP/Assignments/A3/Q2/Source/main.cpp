/*
Author: Mohamed Newir
Date: 9/03/2025
File: main.cpp
Description: 
            file contains main function to test worker class and its derived classes part time worker and full time worker
*/

#include <iostream>
#include "../Include/worker.hpp"

int main(void) {
    // create full time worker object
    FullTimeWorker fullTimeWorker("John Doe 1", 8);
    // create part time worker object
    PartTimeWorker partTimeWorker("Jane Doe 2", 4);

    // display full time worker details
    fullTimeWorker.display();
    // display part time worker details
    partTimeWorker.display();

    return 0;
}