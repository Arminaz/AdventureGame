/**
*@file Exceptions.h
*@brief Collection of various exceptions.
*@author
*/

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>

/**
*Exception for when an array goes out of bounds (eg. array[-1])
*/
class invalid_index : public std::runtime_error
{
    public:
        /**
        *@param errMessage an error message.
        */
        invalid_index(const char* errMessage)
            : std::runtime_error(errMessage) {}
};


/**
*Exception for when the input stream enters the failstate (ie. garbage is given to input stream).
*Also handles input that has no mapping (ie. passing in the character 'i' may have no assigned output) and input that is valid, but does not have functionality.
*/
class invalid_input : public std::runtime_error
{
    public:
        /**
        *@param errMessage an error message.
        */
        invalid_input(const char* errMessage)
            : std::runtime_error(errMessage) {}
};


/**
*Exception for when a function parameter is given a bad value or when a function parameter does not meet a particular requirement.
*/
class invalid_parameter : public std::runtime_error
{
    public:
        /**
        *@param errMessage an error message.
        */
        invalid_parameter(const char* errMessage)
            : std::runtime_error(errMessage) {}

};


#endif // EXCEPTIONS_H
