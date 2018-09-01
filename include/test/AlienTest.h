#ifndef ALIENTEST_H
#define ALIENTEST_H

#include "Exceptions.h"
#include "Alien.h"

#include <cppunit/extensions/HelperMacros.h>

/**
*@file AlienTest.h
*@brief Class that tests the Alien class and its functions
*@author
*/
class AlienTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( AlienTest ); //Setting the suite

	CPPUNIT_TEST( testConstructor ); //Testing the constructor
	CPPUNIT_TEST( testStatus ); //Checking if alien is set to alive status, and if it dies at 0 health.

    CPPUNIT_TEST_EXCEPTION( testNegativeParameterOne, invalid_parameter );//Checking negative value exception handling
    CPPUNIT_TEST_EXCEPTION( testNegativeParameterTwo, invalid_parameter );//Checking negative value exception handling

	CPPUNIT_TEST_SUITE_END(); //Ending suite

private:
    Alien *a1, *a2, *a3;
    const static int health = 50;
    const static int damage = 5;

public:
	void setUp(); //initializes and sets up the functions
	void tearDown(); //breaks and destroys all the functions

    /**
    *@brief Testing constructor for alien class
    */
	void testConstructor();

	/**
	*@brief Testing aliens status, and testing if with 0 health.
	*/
    void testStatus();

    /**
    *@brief Testing if alien class throws exception on health parameter
    */
	void testNegativeParameterOne();

    /**
    *@brief Testing if alien class throws exception on damage parameter
    */
	void testNegativeParameterTwo();
};

#endif

