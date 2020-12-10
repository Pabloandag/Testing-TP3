#include "leds.h"

#define LEDS_ALL_OFF 0x0000
#define LEDS_ALL_ON  0xFFFF
#define LED_OFFSET   1
#define LSB          1

static uint16_t *leds;
static LedError_t registrarError;


uint16_t LedToMask(uint8_t led){
    if(led > 16){
        registrarError();
    }
    return (LSB << (led - LED_OFFSET));
}


void Leds_Create(uint16_t* direccion, LedError_t handler){
    leds = direccion;
    registrarError = handler;
    Leds_All_Off();
}

void Leds_On(uint8_t led){
    *leds |= LedToMask(led);
}

void Leds_Off(uint8_t led){
    *leds &= ~LedToMask(led);
}

bool Leds_Get_State(uint8_t led){
    if((*leds & LedToMask(led)) != 0 ){
        return true;
    }else{
        return false;
    }
}

void Leds_All_On(void){
    *leds = LEDS_ALL_ON;
}

void Leds_All_Off(void){
    *leds = LEDS_ALL_OFF;
}