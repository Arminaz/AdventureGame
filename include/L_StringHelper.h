#ifndef L_STRINGHELPER_H
#define L_STRINGHELPER_H

#include <string>
#include <iterator>

/**
*@file L_StringHelper.h
*@brief Class that provides help when working with string
*@brief This class contains commonly used string related functions.
*@author
*/
class L_StringHelper
{
    public:

        /**
        *@brief Sets the whole string to lower case
        *@param s the string which is going to be converted to lowercase letters.
        */
        static void toLower(std::string &s);

        /**
        *@brief Sets the whole string to upper case
        *@param s the string which is going to be converted to uppercase letters.
        */
        static void toUpper(std::string &s);

        /**
        *@brief Casts the string to int
        *@param s the string to convert to an integer.
        *@return int result
        */
        static int toInt(std::string s);

        /**
        *@brief Casts the int to string
        *@param i the int that is going to be converted to a string
        *@return string result
        */
        static std::string toString(int i);

        /**
        *@brief Checks if string contains digits, then returns true otherwise false.
        *@param s the string to check for digits
        *@return bool result
        */
        static bool digitsExist(std::string s);

        static void printTextWrap(std::string &str, int length = 60);

    protected:

    private:
};

#endif // L_STRINGHELPER_H
