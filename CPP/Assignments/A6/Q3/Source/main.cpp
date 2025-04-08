/*
Author: Mohamed Newir
Date: 10/03/2025
File: main.cpp
Description:

*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>

namespace FileManager
{
    void logError(const std::string &errorMessage);
    void writeToFile(const std::string &filename, const std::vector<std::string> &lines)
    {
        std::ofstream file(filename, std::ios::app);
        if (!file)
        {
            std::cerr << "Error: File not existed " << filename << std::endl;
            logError(filename + "doesn't exit");
            return;
        }
        for (const auto &line : lines)
        {
            file << line << std::endl;
        }
        file.close();
    }

    std::vector<std::string> readFromFile(const std::string &filename)
    {
        std::ifstream inputFile(filename);
        if (!inputFile)
        {
            std::cerr << "Error: File not existed " << filename << std::endl;
            logError(filename + "doesn't exit");
            throw std::runtime_error("File not found: " + filename);
        }

        std::vector<std::string> lines;
        std::string line;
        while (std::getline(inputFile, line))
        {
            lines.push_back(line);
        }
        inputFile.close();
        return lines;
    }

    void logError(const std::string &errorMessage)
    {
        std::ofstream file("error.log", std::ios::app);
        if (!file)
        {
            std::cerr << "Error: File not existed " << "error.log" << std::endl;
            return;
        }

        file << errorMessage << std::endl;
        file.close();
    }
}

int main(void)
{
    std::vector<std::string> str{
        "so", "sad", "bgd", ",", " NEWIR hazeen"};

    try
    {
        FileManager::writeToFile("sad.txt", str);
        std::vector<std::string> strVec = FileManager::readFromFile("sad.txt");

        for (const auto &it : strVec)
        {
            std::cout << it << std::endl;
        }
        FileManager::readFromFile("text.txt");
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}