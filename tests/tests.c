#include "tests.h"
#include "../utils/HAL.h"
#include "testConfig.h"

#define RUN_TEST_CASE(flag, testCase)   if(flag != 0)\
                                        {testCase();}

static void runTestCase1();
static void runTestCase2();
static void runTestCase3();
static void runTestCase4();
static void runTestCase5();
static void runTestCase6();
static void runTestCase7();
static void runTestCase8();
static void runTestCase9();
static void runTestCase10();
static void runTestCase11();
static void runTestCase12();

void runTests()
{
    RUN_TEST_CASE(TEST_CASE_1, runTestCase1);
    RUN_TEST_CASE(TEST_CASE_2, runTestCase2);
    RUN_TEST_CASE(TEST_CASE_3, runTestCase3);
    RUN_TEST_CASE(TEST_CASE_4, runTestCase4);
    RUN_TEST_CASE(TEST_CASE_5, runTestCase5);
    RUN_TEST_CASE(TEST_CASE_6, runTestCase6);
    RUN_TEST_CASE(TEST_CASE_7, runTestCase7);
    RUN_TEST_CASE(TEST_CASE_8, runTestCase8);
    RUN_TEST_CASE(TEST_CASE_9, runTestCase9);
    RUN_TEST_CASE(TEST_CASE_10, runTestCase10);
    RUN_TEST_CASE(TEST_CASE_11, runTestCase11);
    RUN_TEST_CASE(TEST_CASE_12, runTestCase12);
}

static void runTestCase1()
{
    static int count = 0;
    if(count >= 0)
    {
        count++;
    }

    if(count == 1)
    {
        printf("Test case 1: Button 1 single press\n");
        HAL_Set_Pin(GPIO_PIN_1);
    }
    else  if(count >= 5)
    {
        HAL_Reset_Pin(GPIO_PIN_1);
        count = -1;
    }
}

static void runTestCase2()
{
    static int count = 0;
    if(count >= 0)
    {
        count++;
    }

    if(count == 1)
    {
        printf("Test case 2: Button 1 double press\n");
        HAL_Set_Pin(GPIO_PIN_1);
    }
    else  if(count == 5)
    {
        HAL_Reset_Pin(GPIO_PIN_1);
    }
    else if(count == 10)
    {
        HAL_Set_Pin(GPIO_PIN_1);
    }
    else if(count >= 15)
    {
        HAL_Reset_Pin(GPIO_PIN_1);
        count = -1;
    }
}

static void runTestCase3()
{
    static int count = 0;
    if(count >= 0)
    {
        count++;
    }

    if(count == 1)
    {
        printf("Test case 3: Button 1 triple press\n");
        HAL_Set_Pin(GPIO_PIN_1);
    }
    else  if(count == 5)
    {
        HAL_Reset_Pin(GPIO_PIN_1);
    }
    else if(count == 10)
    {
        HAL_Set_Pin(GPIO_PIN_1);
    }
    else if(count == 15)
    {
        HAL_Reset_Pin(GPIO_PIN_1);
    }
    else if(count == 20)
    {
        HAL_Set_Pin(GPIO_PIN_1);
    }
    else if(count >= 25)
    {
        HAL_Reset_Pin(GPIO_PIN_1);
    }
}

static void runTestCase4()
{
    static int count = 0;
    if(count >= 0)
    {
        count++;
    }

    if(count == 1)
    {
        printf("Test case 4: Button 1 long press\n");
        HAL_Set_Pin(GPIO_PIN_1);
    }
    else  if(count >= 500)
    {
        HAL_Reset_Pin(GPIO_PIN_1);
        count = -1;
    }
}


static void runTestCase5()
{
    static int count = 0;
    if(count >= 0)
    {
        count++;
    }

    if(count == 1)
    {
        printf("Test case 5: Button 2 single press\n");
        HAL_Set_Pin(GPIO_PIN_2);
    }
    else  if(count >= 5)
    {
        HAL_Reset_Pin(GPIO_PIN_2);
        count = -1;
    }
}

static void runTestCase6()
{
    static int count = 0;
    if(count >= 0)
    {
        count++;
    }

    if(count == 1)
    {
        printf("Test case 6: Button 2 double press\n");
        HAL_Set_Pin(GPIO_PIN_2);
    }
    else  if(count == 5)
    {
        HAL_Reset_Pin(GPIO_PIN_2);
    }
    else if(count == 10)
    {
        HAL_Set_Pin(GPIO_PIN_2);
    }
    else if(count >= 15)
    {
        HAL_Reset_Pin(GPIO_PIN_2);
        count = -1;
    }
}

static void runTestCase7()
{
    static int count = 0;
    if(count >= 0)
    {
        count++;
    }

    if(count == 1)
    {
        printf("Test case 7: Button 2 triple press\n");
        HAL_Set_Pin(GPIO_PIN_2);
    }
    else  if(count == 5)
    {
        HAL_Reset_Pin(GPIO_PIN_2);
    }
    else if(count == 10)
    {
        HAL_Set_Pin(GPIO_PIN_2);
    }
    else if(count == 15)
    {
        HAL_Reset_Pin(GPIO_PIN_2);
    }
    else if(count == 20)
    {
        HAL_Set_Pin(GPIO_PIN_2);
    }
    else if(count >= 25)
    {
        HAL_Reset_Pin(GPIO_PIN_2);
    }
}

static void runTestCase8()
{
    static int count = 0;
    if(count >= 0)
    {
        count++;
    }

    if(count == 1)
    {
        printf("Test case 8: Button 3 long press\n");
        HAL_Set_Pin(GPIO_PIN_3);
    }
    else  if(count >= 500)
    {
        HAL_Reset_Pin(GPIO_PIN_3);
        count = -1;
    }
}


static void runTestCase9()
{
    static int count = 0;
    if(count >= 0)
    {
        count++;
    }

    if(count == 1)
    {
        printf("Test case 9: Button 3 single press\n");
        HAL_Set_Pin(GPIO_PIN_3);
    }
    else  if(count >= 5)
    {
        HAL_Reset_Pin(GPIO_PIN_3);
        count = -1;
    }
}

static void runTestCase10()
{
    static int count = 0;
    if(count >= 0)
    {
        count++;
    }

    if(count == 1)
    {
        printf("Test case 10: Button 3 double press\n");
        HAL_Set_Pin(GPIO_PIN_3);
    }
    else  if(count == 5)
    {
        HAL_Reset_Pin(GPIO_PIN_3);
    }
    else if(count == 10)
    {
        HAL_Set_Pin(GPIO_PIN_3);
    }
    else if(count >= 15)
    {
        HAL_Reset_Pin(GPIO_PIN_3);
        count = -1;
    }
}

static void runTestCase11()
{
    static int count = 0;
    if(count >= 0)
    {
        count++;
    }

    if(count == 1)
    {
        printf("Test case 11: Button 3 triple press\n");
        HAL_Set_Pin(GPIO_PIN_3);
    }
    else  if(count == 5)
    {
        HAL_Reset_Pin(GPIO_PIN_3);
    }
    else if(count == 10)
    {
        HAL_Set_Pin(GPIO_PIN_3);
    }
    else if(count == 15)
    {
        HAL_Reset_Pin(GPIO_PIN_3);
    }
    else if(count == 20)
    {
        HAL_Set_Pin(GPIO_PIN_3);
    }
    else if(count >= 25)
    {
        HAL_Reset_Pin(GPIO_PIN_3);
    }
}

static void runTestCase12()
{
    static int count = 0;
    if(count >= 0)
    {
        count++;
    }

    if(count == 1)
    {
        printf("Test case 12: Button 3 long press\n");
        HAL_Set_Pin(GPIO_PIN_3);
    }
    else  if(count >= 500)
    {
        HAL_Reset_Pin(GPIO_PIN_3);
        count = -1;
    }
}