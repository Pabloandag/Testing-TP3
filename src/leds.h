#include <stdint.h>
#include <stdbool.h>

typedef void (*LedError_t) (void);


bool Leds_Get_State(uint8_t led);
void Leds_Create(uint16_t* puerto, LedError_t handler);
void Leds_On(uint8_t led);
void Leds_Off(uint8_t led);
void Leds_All_On(void);
void Leds_All_Off(void);