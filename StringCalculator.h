#ifndef STRINGCALCULATOR_H
#define STRINGCALCULATOR_H

#include <string>

class StringCalculator {
public:
    int add(const std::string& input);
    int addofnum(const std::string& input);
    void verify_NegativeNum(const std::string& input);
    std::string normalizeDelimiters(const std::string& input);
    std::string newlinecheck(const std::string& input);
};

#endif
