#ifndef CONNECTION_H
#define CONNECTION_H_

#include <Arduino.h>
#include <PubSubClient.h>
// if its esp32
#include <WiFi.h>
// if its esp8266
//#include <ESP8266WiFi.h>

namespace connection {

void connectToWiFi();

void callback (char* topic, byte* payload, unsigned int length);

int returnpayload();

void reconnect(const char* Sub);

void setupMQTT();

void setup();

void check_connection();

void publish(String id, int value, const char* Pub);

} // namespace connection
#endif // CONNECTION_H_
