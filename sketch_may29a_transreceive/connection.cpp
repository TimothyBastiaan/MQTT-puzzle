#include "connection.hpp"
#include "settings.hpp"
int msgpayload = 0;
int Astatus = 0;
int Bstatus = 0;
int Cstatus = 0;
namespace connection {

    WiFiClient wifiClient;
    PubSubClient mqttClient(wifiClient);

    void connectToWiFi(){
        
        Serial.print("Connecting to ");
        char* uSSID;
        uSSID = (char*)SSID;
        WiFi.begin( uSSID, PASSWORD);
        Serial.println(uSSID);
        int number = 0;
        while (WiFi.status() != WL_CONNECTED) {
            Serial.print(".");
            delay(500);
            number++;
            if(number>30)
            ESP.restart();
        }
        
        Serial.print("Connected.");
    }

    void callback(char* topic, byte* payload, unsigned int length) {
        Serial.print("Callback - ");
        Serial.println("Message:");
        char value[8]={NULL};
        for (int i = 0; i < length; i++) {
            
            value[i]=(char)payload [i];
        }
        String mystring(value);
        Serial.println(mystring[0]);
        Serial.println(mystring[2]);
        
        if(mystring[0] == 'A' )
        {
          Astatus = int(mystring[2]) - 48;
        }
        if(mystring[0] == 'B' )
        {
          Bstatus = int(mystring[2]) - 48;
        }
        if(mystring[0] == 'C' )
        {
          Cstatus = int(mystring[2]) - 48;
        }
        msgpayload = Astatus + Bstatus + Cstatus;
        Serial.println(msgpayload);
        
    }
    
    int returnpayload()
    {return msgpayload;}

    void reconnect(const char* Sub){
        Serial.println("Connecting to MQTT Broker...");
        int number =0;
        while (!mqttClient.connected()) {
            number++;
            Serial.println("Reconnecting to MQTT Broker..");
            String clientId = "ESP32Client-";
            clientId += String(random(0xffff), HEX);
            delay(500);
            if(number>30)
            ESP.restart();
            }
        if (mqttClient.connect("",MQTTUSER,MQTTPASS)) {
                Serial.println("Connected.");
              // subscribe to topic
             mqttClient.subscribe(Sub);
            }
    }

 
    void setupMQTT(){
        mqttClient.setServer(MQTTSERVER, MQTTPORT);
        mqttClient.connect("",MQTTUSER,MQTTPASS);
        // set the callback function
        mqttClient.setCallback(callback);
    }

    void setup() {
        connectToWiFi();
        setupMQTT();
    }

    void publish(String id, int value, const char* Pub){
      char message[64];
      sprintf(message, "%s %d",id, value);
      mqttClient.publish( Pub, message);
    }
    
    void check_connection () {
      int number = 0;
      while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
            delay(500);
            number++;
            if(number>30)
            ESP.restart();
      }
      
      if (!mqttClient.connected()) {
        mqttClient.disconnect();
        setupMQTT();
        reconnect(Sub); }
      mqttClient.loop();
    }

} // namespace connection
