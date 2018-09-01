#ifndef L_STRINGHELPERTEST_H
#define L_STRINGHELPERTEST_H

#include "L_StringHelper.h"

#include <cppunit/extensions/HelperMacros.h>

/**
*@file L_StringHelperTest.h
*@brief Class that tests the L_StringHelper class and its functions
*@author
*/
class L_StringHelperTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( L_StringHelperTest ); //Setting the suite

	CPPUNIT_TEST( testToLower ); //Testing if String is set to lower
	CPPUNIT_TEST( testToUpper ); //Testing if String is set to Upper
	CPPUNIT_TEST( testToInt ); //Testing if String is set to int
	CPPUNIT_TEST( testToString ); //Testing if int is set to string
	CPPUNIT_TEST( testDigitsExist ); //Checking if it checks if digits exist

	CPPUNIT_TEST_SUITE_END(); //Ending suite

private:

public:
	void setUp(); //initializes and sets up the functions
	void tearDown(); //breaks and destroys all the functions

    /**
    *@brief Testing if the String is set to lower case.
    */
	void testToLower();

    /**
    *@brief Testing if the String is set to Upper case.
    */
	void testToUpper();

    /**
    *@brief Testing if the String is set to int.
    */
	void testToInt();

    /**
    *@brief Testing if the int is set to string
    */
	void testToString();

	/**
	*@brief Testing if it returns true for digits existing
	*/
    void testDigitsExist();
};

#endif

