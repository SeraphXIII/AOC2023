#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>

std::vector<char> numbers;
std::vector<std::string> games;
int total = 0;
int lineNum = 1;

int main()
{
    std::ifstream file ("F:\\AOC2023\\day2\\day2input.txt", std::ios::in);
    if(!file)
    {
        // file not found
        std::cerr << "Input file not found.";
        return 1;
    }

    while(file)
    {
        // read line
        std::string str, processedStr;
        if(std::getline(file, str))
        {
            // Remove Game X:, use +2 to skip the space
            processedStr = str.substr(str.find_first_of(":") + 2);

            // Split on semicolons
            while(processedStr.find(";") != -1)
            {
                int pos = processedStr.find_first_of(";");
                games.push_back(processedStr.substr(0, pos));
                processedStr.replace(0, pos + 2, "");
            }
            games.push_back(processedStr);
            std::vector<std::string> singlePull;
            bool possible = true;
            for (int i=0; i<games.size(); i++)
            {
                std::string gameLine = games.at(i);
                while(gameLine.find(",") != -1)
                {
                    int pos = gameLine.find_first_of(",");
                    singlePull.push_back(gameLine.substr(0, pos));
                    gameLine.replace(0, pos + 2, "");
                }
                singlePull.push_back(gameLine);

                for(int j=0; j<singlePull.size(); j++)
                {
                    std::string element = singlePull.at(j);
                    int num = std::stoi(element.substr(0, element.find_first_of(" ")));
                    int limit = 12;
                    if(element.find("green") != -1) limit++;
                    if(element.find("blue") != -1) limit+=2;
                    if(num > limit) possible = false;
                }
                singlePull.clear();
            }

            if(possible)
            {
                total += lineNum;
                std::cout << "Game " << std::to_string(lineNum) << " is possible.\n";
                std::cout << "Total is now " << std::to_string(total) << ".\n";
            } 
            else
            {
                std::cout << "Game " << std::to_string(lineNum) << " is not possible.\n";
            }
            games.clear();
            lineNum++;
        } 
    }
    std::cout << "Total is " << std::to_string(total);
}