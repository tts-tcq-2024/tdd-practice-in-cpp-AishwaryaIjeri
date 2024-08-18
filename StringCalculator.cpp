#ifndef STRING_CALCULATOR_H
#define STRING_CALCULATOR_H

#include <string>
#include <vector>
#include <stdexcept>

class StringCalculator {
public:
    static int Add(const std::string& numbers);

private:
    static std::vector<int> parseNumbers(const std::string& input);
    static void validateNumbers(const std::vector<int>& numbers);
    static std::string extractDelimiter(const std::string& input);
    static std::string removeDelimiterLine(const std::string& input);
};

#endif // STRING_CALCULATOR_H
StringCalculator.cpp
cpp
Copy code
#include "StringCalculator.h"
#include <sstream>
#include <cctype>
#include <regex>
#include <stdexcept>

// Main method to add numbers based on the input string
int StringCalculator::Add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    std::string input = numbers;
    std::string delimiter = extractDelimiter(input);
    input = removeDelimiterLine(input);

    std::vector<int> parsedNumbers = parseNumbers(input, delimiter);
    validateNumbers(parsedNumbers);

    int sum = 0;
    for (int number : parsedNumbers) {
        sum += number;
    }
    return sum;
}

// Extract delimiter if specified at the start of the string
std::string StringCalculator::extractDelimiter(const std::string& input) {
    if (input.rfind("//", 0) == 0) {
        size_t delimiterEnd = input.find("\n");
        std::string delimiterLine = input.substr(2, delimiterEnd - 2);
        if (delimiterLine.front() == '[' && delimiterLine.back() == ']') {
            return delimiterLine.substr(1, delimiterLine.length() - 2);
        }
        return delimiterLine;
    }
    return ",\n"; // default delimiters
}

// Remove the delimiter line from the input string
std::string StringCalculator::removeDelimiterLine(const std::string& input) {
    if (input.rfind("//", 0) == 0) {
        size_t delimiterEnd = input.find("\n");
        return input.substr(delimiterEnd + 1);
    }
    return input;
}

// Parse numbers from the string based on the provided delimiter
std::vector<int> StringCalculator::parseNumbers(const std::string& input, const std::string& delimiter) {
    std::vector<int> numbers;
    std::string token;
    std::stringstream ss(input);

    // Tokenize input based on the delimiter
    while (std::getline(ss, token, delimiter[0])) {
        std::stringstream tokenStream(token);
        while (std::getline(tokenStream, token, '\n')) {
            if (!token.empty()) {
                int number = std::stoi(token);
                if (number <= 1000) {
                    numbers.push_back(number);
                }
            }
        }
    }

    return numbers;
}

// Validate numbers to check for negatives and other constraints
void StringCalculator::validateNumbers(const std::vector<int>& numbers) {
    std::vector<int> negatives;
    for (int number : numbers) {
        if (number < 0) {
            negatives.push_back(number);
        }
    }
    if (!negatives.empty()) {
        std::ostringstream errorMessage;
        errorMessage << "negatives not allowed: ";
        for (size_t i = 0; i < negatives.size(); ++i) {
            if (i > 0) errorMessage << ", ";
            errorMessage << negatives[i];
        }
        throw std::runtime_error(errorMessage.str());
    }
}
