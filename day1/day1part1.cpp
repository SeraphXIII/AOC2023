#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>

std::vector<char> numbers;
int total = 0;

int main()
{
    std::ifstream file ("F:\\AOC\\day1\\day1input.txt", std::ios::in);
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
            std::cout << "Line " << lineCount << " result is " << (numbers.front() + numbers.back()) << "\n";
            numbers.clear();
            lineCount++;
        }
    }
    std:: cout << "Total result is " << total << "\n";
    return 0;
}