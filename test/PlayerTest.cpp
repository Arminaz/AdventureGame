#include "PlayerTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION( PlayerTest );

void PlayerTest::setUp()
{
    p1 = new Player(health, damage);
}

void PlayerTest::tearDown()
{
    delete p1;
    delete p2;
    delete p3;
    delete p4;
}

void PlayerTest::testConstructor()
{
    const int testOperandOne = health;
    const int testOperandTwo = damage;
    const int testOperandThree = oxygen;

	CPPUNIT_ASSERT_EQUAL( testOperandOne, p1->getHealth() );
	CPPUNIT_ASSERT_EQUAL( testOperandTwo, p1->getDamage() );
	CPPUNIT_ASSERT_EQUAL( testOperandThree, p1->getOxygen() );
}

void PlayerTest::testStatus()
{
    CPPUNIT_ASSERT(p1->isCharDead() == false);
    p1->setHealth(0);
    p1->checkCurrentStatus();
    CPPUNIT_ASSERT(p1->isCharDead());
}

void PlayerTest::testNegativeParameterOne()
{
    p2 = new Player(-500, 3, 100);
}

void PlayerTest::testNegativeParameterTwo()
{
    p3 = new Player(3, -500, 100);
}

void PlayerTest::testNegativeParameterThree()
{
    p4 = new Player(3, 3, -500);
}

