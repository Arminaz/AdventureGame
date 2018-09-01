#include "AlienTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION( AlienTest );

void AlienTest::setUp()
{
    a1 = new Alien(health, damage);
}

void AlienTest::tearDown()
{
    delete a1;
    delete a2;
    delete a3;
}

void AlienTest::testConstructor()
{
    const int testOperandOne = health;
    const int testOperandTwo = damage;

	CPPUNIT_ASSERT_EQUAL( testOperandOne, a1->getHealth() );
	CPPUNIT_ASSERT_EQUAL( testOperandTwo, a1->getDamage() );
}

void AlienTest::testStatus()
{
    CPPUNIT_ASSERT(a1->isCharDead() == false);
    a1->setHealth(0);
    a1->checkCurrentStatus();
    CPPUNIT_ASSERT(a1->isCharDead());
}

void AlienTest::testNegativeParameterOne()
{
    a2 = new Alien(-500, 3);
}

void AlienTest::testNegativeParameterTwo()
{
    a3 = new Alien(3, -500);
}
