#include  <Arduino.h>
#include "settings.hpp"
#include "connection.hpp"
#include "Output.hpp"

void setup() {
  Serial.begin(115200);
  output::setup();
  connection::setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  connection::check_connection();
  
  int msgpayload=connection::returnpayload();
  if(msgpayload < 0)
  {
    output::LED(0);
  }
  
  if(msgpayload == 3)
  {
    output::LED(1);
  }
  
}
