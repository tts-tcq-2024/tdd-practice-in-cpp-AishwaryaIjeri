#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include "StringCalculator.h"

std::string ReplaceWithCommas(const std::string& input, const std::string& delimiter)
{
    std::string numbersStr = input;
    std::replace_if(numbersStr.begin(), numbersStr.end(), [&](char c) {
        return c == '\n' || delimiter.find(c) != std::string::npos;
    }, ',');
    return numbersStr;
}

std::string FindDelimeter(const std::string& input)
{
   
    std::string delimiter = ",";
    std::string numbersStr = input;

    
    if (input.substr(0, 2) == "//") {
        size_t delimiterPos = input.find("\n");
        if (delimiterPos != std::string::npos) {
            delimiter = input.substr(2, delimiterPos - 2);
            numbersStr = input.substr(delimiterPos + 1);
        }
    }
    numbersStr = ReplaceWithCommas(numbersStr, delimiter);
    return numbersStr;
}
void FindNegatives(const std::string& updatedinput)
{
    std::stringstream strstream(updatedinput);
    std::string segment;

    while (std::getline(strstream, segment, ',')) {
        if (std::stoi(segment) < 0) 
        {
        throw std::runtime_error("negatives not allowed");
        }
    }
}

int FindSum(const std::string& updatedinput)
{
 
    std::stringstream strstream(updatedinput);
    std::string segment;
    int sum = 0;

    while (std::getline(strstream, segment, ',')) {
        int number = std::stoi(segment);
        if (number <= 1000) {
            sum += number;
        }
    }
    return sum;
}

int StringCalculator::add(const std::string& input) 
{
  if (input.empty()) {
        return 0;
    }
    std::string updatedinput = FindDelimeter(input);

 

    int sum = FindSum(updatedinput);
    
    FindNegatives(updatedinput);

    return sum;
}
