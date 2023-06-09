#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_

#define ID "C"

// No need internet just need local connection
static const char* SSID = "Emmerich"; // wifi ssid
static const char* PASSWORD = ""; // wifi password

static char* MQTTSERVER = "192.168.5.50";
static int  MQTTPORT = 9696;
static char* MQTTUSER = "emmerich";
static char* MQTTPASS = "emmerich";

static unsigned long last_time = 0;
static const char* Pub = "Room1";
static const char* Sub = ID;



#endif // SETTINGS_H_
