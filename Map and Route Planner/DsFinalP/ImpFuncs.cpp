#include "ImpFuncs.h"
#include <iostream>
#include <sstream>
#include <vector>

std::vector<std::string> explode(std::string i, char delimeter)
{
    std::stringstream s(i);
    std::vector<std::string> row;
    std::string word;
    while (getline(s, word, delimeter)) {
        row.push_back(word);
    }
    return row;
}