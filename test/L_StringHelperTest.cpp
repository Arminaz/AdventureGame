#include "L_StringHelperTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION( L_StringHelperTest );

void L_StringHelperTest::setUp()
{
    //Place holder
}

void L_StringHelperTest::tearDown()
{
    //Place holder
}

void L_StringHelperTest::testToLower()
{
    std::string testOperandOne = "ABC";
    std::string testOperandTwo = "abc";

    L_StringHelper::toLower(testOperandOne); //Setting the operand one to lower

	CPPUNIT_ASSERT_EQUAL( testOperandTwo, testOperandOne );
}

void L_StringHelperTest::testToUpper()
{
    std::string testOperandOne = "abc";
    std::string testOperandTwo = "ABC";

    L_StringHelper::toUpper(testOperandOne); //Setting the operand one to Upper

    CPPUNIT_ASSERT_EQUAL( testOperandTwo, testOperandOne );

}

void L_StringHelperTest::testToInt()
{
    std::string testOperandOne = "123";
    int testOperandTwo = 123;

    int retOperand = L_StringHelper::toInt(testOperandOne); //Setting operand to int and returning

    CPPUNIT_ASSERT_EQUAL( testOperandTwo, retOperand );
}

void L_StringHelperTest::testToString()
{
    int testOperandOne = 123;
    std::string testOperandTwo = "123";

    std::string retOperand = L_StringHelper::toString(testOperandOne); // Setting operand to string and returning

    CPPUNIT_ASSERT_EQUAL( testOperandTwo, retOperand );
}

void L_StringHelperTest::testDigitsExist()
{
    std::string testOperandOne = "abc123";
    std::string testOperandTwo = "123";
    std::string testOperandThree = "abc";

    CPPUNIT_ASSERT(L_StringHelper::digitsExist(testOperandOne)); //Should be true
    CPPUNIT_ASSERT(L_StringHelper::digitsExist(testOperandTwo)); //Should be true
    CPPUNIT_ASSERT(L_StringHelper::digitsExist(testOperandThree) == false); //Should be false but condition must be true

}

