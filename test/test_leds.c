#include "unity.h"
#include "leds.h"

uint16_t ledsVirtuales;
uint8_t errorRegistrado = 0;

void registrarError(void){
    errorRegistrado = 1;
}
void setUp(void){
    Leds_Create(&ledsVirtuales,registrarError);
    errorRegistrado = 0;
}

void tearDown(void){

}

//Despues de la inicializacion los LEDS deben quedar apagados
void test_LedsOffAfterCreate(void){
    uint16_t ledsVirtuales = 0xFFFF;
    Leds_Create(&ledsVirtuales,registrarError);
    TEST_ASSERT_EQUAL_HEX16(0x0000,ledsVirtuales);
}

//Se puede prender un led individual
void test_prender_led_individual(void){
    Leds_On(8);
    TEST_ASSERT_EQUAL_HEX16(1<<7,ledsVirtuales);
}

//Se puede apagar un led individual
void test_apagar_led_individual(void){
    Leds_On(1);
    Leds_Off(1);
    TEST_ASSERT_EQUAL_HEX16(0x0000,ledsVirtuales);
}

// Se pueden prender y apagar multiples LEDs
void test_prender_apagar_multiples(void){
    Leds_On(3);
    Leds_On(4);
    Leds_Off(3);
    TEST_ASSERT_EQUAL_HEX16(1<<3,ledsVirtuales);
}

// Revisar parametros fuera de limites
void test_prender_led_invalido(void){
    Leds_On(17);
    TEST_ASSERT_EQUAL(1,errorRegistrado);
}

// Revisar limite superior de numero de led al prender
void test_prender_led_16(void){
    Leds_On(16);
    TEST_ASSERT_EQUAL_HEX16(1<<15,ledsVirtuales);
}

// Revisar limite inferior de numero de led al prender
void test_prender_led_1(void){
    Leds_On(1);
    TEST_ASSERT_EQUAL_HEX16(0x0001,ledsVirtuales);
}

// Revisar limite superior de numero de led al apagar
void test_apagar_led_16(void){
    Leds_On(16);
    Leds_Off(16);
    TEST_ASSERT_EQUAL_HEX16(0x0000,ledsVirtuales);
}

// Revisar limite inferior de numero de led al apagar
void test_apagar_led_1(void){
    Leds_On(1);
    Leds_Off(1);
    TEST_ASSERT_EQUAL_HEX16(0x0000,ledsVirtuales);
}

// Se puede consultar el estado de un led
void test_get_led_prendido (void){
    Leds_On(7);
    TEST_ASSERT_TRUE(Leds_Get_State(7));
}

// Se puede consultar el estado de un led
void test_get_led_apagado (void){
    uint16_t ledsVirtuales = 0xFFFF;
    Leds_Off(5);
    TEST_ASSERT_FALSE(Leds_Get_State(5));
}

// Se pueden prender todos los LEDs de una vez
void test_prender_todos_los_leds(void){
    Leds_All_On();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF,ledsVirtuales);
}

// Se pueden apagar todos los LEDs de una vez
void test_apagar_todos_los_leds(void){
    Leds_All_Off();
    TEST_ASSERT_EQUAL_HEX16(0x0000,ledsVirtuales);
}