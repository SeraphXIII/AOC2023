#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>

std::vector<char> numbers;
int total = 0;

int main()
{
    std::ifstream file ("F:\\AOC2023\\day1\\day1input.txt", std::ios::in);
    std::vector<std::string> textNumbers = {"one", "two", "three", "four",
                                            "five", "six", "seven", "eight", "nine"};
    // A sneaky solution to a sneaky problem. This allows for subsequent text-numbers to still be complete despite replacement.
    std::vector<std::string> numReplace = {"o1e", "t2o", "t3e", "f4r", "f5e", "s6x", "s7n", "e8t", "n9e"};
    int lineCount = 1;
    
    if(!file)
    {
        // file not found
        std::cerr << "Input file not found.";
        return 1;
    }

    while(file)
    {
        // read line
        std::string str;
        file >> str;
        if(!str.empty())
        {
            for(int j=0; j < textNumbers.size(); j++)
            {
                while(str.find(textNumbers.at(j)) != -1)
                {
                    // Replacing the text version of the number with the numeric
                    str.replace(str.find(textNumbers.at(j)), textNumbers.at(j).length(), numReplace.at(j));
                }
            }
            std::cout << "Line " << lineCount << " sanitized to " << str << "\n";
            for(int i=0; i < str.length(); i++)
            {
                char c = str.at(i);
                if(isdigit(c))
                {
                    numbers.push_back(c);
                }
            }
            std::string numOut;
            numOut += numbers.front();
            numOut += numbers.back();
            total += std::stoi(numOut);
            std::cout << "Line " << lineCount << " result is " << numbers.front() << numbers.back() << "\n";
            numbers.clear();
            lineCount++;
        }
    }
    std:: cout << "Total result is " << total << "\n";
    return 0;
}