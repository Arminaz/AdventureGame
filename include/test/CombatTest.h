#ifndef COMBATTEST_H
#define COMBATTEST_H

#include "Exceptions.h"
#include "Player.h"
#include "Alien.h"
#include "Combat.h"

#include <cppunit/extensions/HelperMacros.h>

/**
*@file CombatTest.h
*@brief Class that tests the Combat class and its functions
*@author
*/
class CombatTest : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE( CombatTest ); //Setting the suite

	CPPUNIT_TEST( testCombatZeroHealth ); //Testing the constructor

	CPPUNIT_TEST_EXCEPTION( testNullPointer, invalid_parameter ); //Testing for null pointers

	CPPUNIT_TEST_SUITE_END(); //Ending suite

private:
    Player *p1, *p2;
    Alien *a1, *a2;
    Combat *c1, *c2;
    const static int health = 50;
    const static int damage = 5;
    const static int oxygen = 100; //For player

public:
	void setUp(); //initializes and sets up the functions
	void tearDown(); //breaks and destroys all the functions

    /**
    *@brief Testing combat class
    */
	void testCombatZeroHealth();

    /**
    *@brief Testing null pointers
    */
	void testNullPointer();
};

#endif

