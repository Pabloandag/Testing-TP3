/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_LedsOffAfterCreate(void);
extern void test_prender_led_individual(void);
extern void test_apagar_led_individual(void);
extern void test_prender_apagar_multiples(void);
extern void test_prender_led_invalido(void);
extern void test_prender_led_16(void);
extern void test_prender_led_1(void);
extern void test_apagar_led_16(void);
extern void test_apagar_led_1(void);
extern void test_get_led_prendido (void);
extern void test_get_led_apagado (void);
extern void test_prender_todos_los_leds(void);
extern void test_apagar_todos_los_leds(void);


/*=======Mock Management=====*/
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
}
static void CMock_Verify(void)
{
}
static void CMock_Destroy(void)
{
}

/*=======Test Reset Options=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  CMock_Verify();
  CMock_Destroy();
  CMock_Init();
  setUp();
}
void verifyTest(void);
void verifyTest(void)
{
  CMock_Verify();
}

/*=======Test Runner Used To Run Each Test=====*/
static void run_test(UnityTestFunction func, const char* name, int line_num)
{
    Unity.CurrentTestName = name;
    Unity.CurrentTestLineNumber = line_num;
#ifdef UNITY_USE_COMMAND_LINE_ARGS
    if (!UnityTestMatches())
        return;
#endif
    Unity.NumberOfTests++;
    UNITY_CLR_DETAILS();
    UNITY_EXEC_TIME_START();
    CMock_Init();
    if (TEST_PROTECT())
    {
        setUp();
        func();
    }
    if (TEST_PROTECT())
    {
        tearDown();
        CMock_Verify();
    }
    CMock_Destroy();
    UNITY_EXEC_TIME_STOP();
    UnityConcludeTest();
}

/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_leds.c");
  run_test(test_LedsOffAfterCreate, "test_LedsOffAfterCreate", 20);
  run_test(test_prender_led_individual, "test_prender_led_individual", 27);
  run_test(test_apagar_led_individual, "test_apagar_led_individual", 33);
  run_test(test_prender_apagar_multiples, "test_prender_apagar_multiples", 40);
  run_test(test_prender_led_invalido, "test_prender_led_invalido", 48);
  run_test(test_prender_led_16, "test_prender_led_16", 54);
  run_test(test_prender_led_1, "test_prender_led_1", 54);
  run_test(test_apagar_led_16, "test_apagar_led_16", 66);
  run_test(test_apagar_led_1, "test_apagar_led_1", 66);
  run_test(test_get_led_prendido , "test_get_led_prendido ", 80);
  run_test(test_get_led_apagado , "test_get_led_apagado ", 86);
  run_test(test_prender_todos_los_leds, "test_prender_todos_los_leds", 93);
  run_test(test_apagar_todos_los_leds, "test_apagar_todos_los_leds", 99);

  return UnityEnd();
}