/* Main file for the application.

This file contains the `main` function that gets started when the application
gets started. Because we are developing for a Arduino-like board (like a ESP32
or ESP8266), we run it like a Arduino application.
*/
#include "arduino.h"

int main()
{
    setup();

    while (true)
        loop();

    return 0;
}
