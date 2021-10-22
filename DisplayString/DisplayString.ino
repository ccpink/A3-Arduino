 #include <stdint.h>
#include <LCD.h>
#include <SPI.h>
#define __AVR_ATmega32U4__


void setup()
{  
    SPI.setDataMode(SPI_MODE3);
    SPI.setBitOrder(MSBFIRST);
    SPI.setClockDivider(SPI_CLOCK_DIV4);
    SPI.begin();

    Tft.lcd_init();                                      // init TFT library
    Tft.lcd_display_string(60, 120, (const uint8_t *)"Charles Pink", 16, BLACK);
    Tft.lcd_display_string(60, 152, (const uint8_t *)"is my name!", 12, RED);
}

void loop()
{
  
}

/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
