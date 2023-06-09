#include "Output.hpp"

namespace output {

       void setup()
    { pinMode(LED_pin,OUTPUT);
      pinMode(Buzzer_pin,OUTPUT);
      pinMode(Out1_pin,OUTPUT);
      pinMode(Out2_pin,OUTPUT);
      pinMode(Out3_pin,OUTPUT);
      pinMode(Out4_pin,OUTPUT);
    }

    void LED(int LEDCmd){

        digitalWrite(LED_pin,LEDCmd);
    
    }
    void Buzzer(int BuzCmd){

        digitalWrite(Buzzer_pin,BuzCmd);

    }
    void Output1(int Out1Cmd){

        digitalWrite(Out1_pin,Out1Cmd);

    }
    void Output2(int Out2Cmd){

        digitalWrite(Out2_pin,Out2Cmd);

    }
    void Output3(int Out3Cmd){

        digitalWrite(Out3_pin,Out3Cmd);

    }
    void Output4(int Out4Cmd){

        digitalWrite(Out4_pin,Out4Cmd);

    }
}
