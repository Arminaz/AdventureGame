#ifndef PLAYERTEST_H
#define PLAYERTEST_H

#include "Exceptions.h"
#include "Player.h"

#include <cppunit/extensions/HelperMacros.h>

/**
*@file PlayerTest.h
*@brief Class that tests the Player class and its functions
*@author
*/
class PlayerTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( PlayerTest ); //Setting the suite

	CPPUNIT_TEST( testConstructor ); //Testing the constructor
	CPPUNIT_TEST( testStatus ); //Checking if Player is set to alive status, and if it dies at 0 health.

    CPPUNIT_TEST_EXCEPTION( testNegativeParameterOne, invalid_parameter );//Checking negative value exception handling
    CPPUNIT_TEST_EXCEPTION( testNegativeParameterTwo, invalid_parameter );//Checking negative value exception handling
    CPPUNIT_TEST_EXCEPTION( testNegativeParameterThree, invalid_parameter );//Checking negative value exception handling

	CPPUNIT_TEST_SUITE_END(); //Ending suite

private:
    Player *p1, *p2, *p3, *p4;
    const static int health = 100;
    const static int damage = 5;
    const static int oxygen = 100;

public:
	void setUp(); //initializes and sets up the functions
	void tearDown(); //breaks and destroys all the functions

    /**
    *@brief Testing constructor for player class
    */
	void testConstructor();

	/**
	*@brief Testing player status, and testing if with 0 health.
	*/
    void testStatus();

    /**
    *@brief Testing if player class throws exception on health parameter
    */
	void testNegativeParameterOne();

    /**
    *@brief Testing if player class throws exception on damage parameter
    */
	void testNegativeParameterTwo();

    /**
    *@brief Testing if player class throws exception on oxygen parameter
    */
	void testNegativeParameterThree();
};

#endif

