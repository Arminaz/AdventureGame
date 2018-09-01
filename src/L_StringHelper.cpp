#include "L_StringHelper.h"

#include <sstream>
#include <iostream>

using namespace std;

void L_StringHelper::toLower(string& s)
{
    int size = s.length();
    for (int i=0; i<size; i++)
    {
        s[i] = tolower(s[i]);
    }
}

void L_StringHelper::toUpper(string& s)
{
    int size = s.length();
    for (int i=0; i<size; i++)
    {
        s[i] = toupper(s[i]);
    }
}

int L_StringHelper::toInt(string s)
{
    int result;
    istringstream convert(s);
    if ( !(convert >> result) )
    {
        result = 0; //No numbers or letters are included!
    }

    return result;

}

string L_StringHelper::toString(int i)
{
    string result;
    ostringstream convert;
    convert << i;
    result = convert.str();

    return result;
}

bool L_StringHelper::digitsExist(string s)
{
    if (s.find('0') != std::string::npos ||
        s.find('1') != std::string::npos ||
        s.find('2') != std::string::npos ||
        s.find('3') != std::string::npos ||
        s.find('4') != std::string::npos ||
        s.find('5') != std::string::npos ||
        s.find('6') != std::string::npos ||
        s.find('7') != std::string::npos ||
        s.find('8') != std::string::npos ||
        s.find('9') != std::string::npos)
    {
        return true;
    }
    return false;
}

void L_StringHelper::printTextWrap(string &str, int length)
{
    size_t curWidth = length;
    while(curWidth < str.length())
    {
        std::string::size_type spacePos = str.rfind(' ', curWidth );
        if(spacePos == std::string::npos)
        {
            spacePos = str.find(' ', curWidth);
        }
        if( spacePos != std::string::npos )
        {
            str[ spacePos ] = '\n';
            curWidth = spacePos + length + 1;
        }
    }
}
