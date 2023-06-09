#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_

#include <Arduino.h>

#define LED_pin 18
#define Buzzer_pin 19
#define Out1_pin 2
#define Out2_pin 4
#define Out3_pin 18
#define Out4_pin 19


namespace output{
  
    void setup();
    void LED(int LEDCmd);
    void Buzzer(int BuzCmd);
    void Output1(int Out1Cmd);
    void Output2(int Out2Cmd);
    void Output3(int Out3Cmd);
    void Output4(int Out4Cmd);

    }

#endif //OUTPUT_HPP_
