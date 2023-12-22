// Corresponding test code (test_my_math.c)
#include "Unity/src/unity.h"
#include "mk_utils.h" // Include the implementation to be tested

void setUp(void)
{
    // set stuff up here
}

void tearDown(void)
{
    // clean stuff up here
}

void test_add()
{
    TEST_ASSERT_EQUAL(5, add(2, 3));
    TEST_ASSERT_EQUAL(-1, add(2, -3));
}

int main()
{
    UNITY_BEGIN(); // Initialize Unity test framework

    // Run test cases
    RUN_TEST(test_add);

    return UNITY_END(); // Finalize Unity test framework
}