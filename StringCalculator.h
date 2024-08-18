cpp
Copy code
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
};

#endif // STRING_CALCULATOR_H
