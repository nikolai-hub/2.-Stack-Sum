#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<std::string> readInput() {
    std::vector<std::string> input;
    std::string inputLine;

    std::getline(std::cin, inputLine);
    std::istringstream istr(inputLine);
    std::string digits;
    while (istr >> digits)
    {
        input.push_back(digits);
    }

    return input;
}

void command(std::vector<std::string>& vecFromDigits) {
    std::string currCommand;
    std::getline(std::cin, currCommand);
    std::istringstream istr(currCommand);
    while (currCommand != "end")
    {
        std::string commandToDo;
        std::istringstream extractCommand(currCommand);
        extractCommand >> commandToDo;
        if (commandToDo == "add")
        {
            int digit = 0;
            while (extractCommand >> digit)
            {
                std::string digitToStr = std::to_string(digit);
                vecFromDigits.push_back(digitToStr);
            }
        }
        else if(commandToDo == "remove")
        {
            int digit = 0;
            extractCommand >> digit;
            for (size_t i = 0; i < digit; i++)
            {
                vecFromDigits.pop_back();
            }
        }
        std::getline(std::cin, currCommand);
    }
}

void printResult(std::vector<std::string>& vecFromDigits) {
    int sum = 0;
    for (size_t i = 0; i < vecFromDigits.size(); i++)
    {
        sum += stoi(vecFromDigits[i]);
    }
    std::cout << sum << std::endl;

 }

int main()
{
    std::vector<std::string> vecFromDigits = readInput();
    command(vecFromDigits);
    printResult(vecFromDigits);
}