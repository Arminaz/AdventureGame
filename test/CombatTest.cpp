#include "CombatTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION( CombatTest );

void CombatTest::setUp()
{
    p1 = new Player(health, damage, oxygen);
    a1 = new Alien(health, damage);
    c1 = new Combat(p1, a1);
    a1->setHealth(0); //Killing alien
    a1->checkCurrentStatus(); //Updating status
}

void CombatTest::tearDown()
{
    delete p1;
    delete p2;
    delete a1;
    delete a2;
    delete c1;
    delete c2;
}

void CombatTest::testCombatZeroHealth()
{
    CPPUNIT_ASSERT(c1->fight()); //Player should win automatically.
}

void CombatTest::testNullPointer()
{
    c2 = new Combat(p2, a2);
}
