#include  <Arduino.h>
#include "settings.hpp"
#include "connection.hpp"
#include "Output.hpp"

void setup() {
  Serial.begin(115200);
  pinMode(25, INPUT);
  pinMode(26, INPUT);
  output::setup();
  connection::setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  connection::check_connection();
  if (digitalRead(25) == 1 && digitalRead(26) == 1)
  {
    connection::publish(ID, 1, Pub);
  }
  else
  {
    connection::publish(ID, 0, Pub);
  }
  delay(500);
}
