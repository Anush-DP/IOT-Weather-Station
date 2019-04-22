#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DHT.h>
#include <ESP8266mDNS.h>
#include <ESP8266mDNS_Legacy.h>
#include <LEAmDNS.h>
#include <LEAmDNS_lwIPdefs.h>
#include <LEAmDNS_Priv.h>

#define DHTTYPE DHT11
/*Put your SSID & Password*/
const char* ssid = "IOT WS";  // Enter SSID here
const char* password = "password";  //Enter Password here
MDNSResponder mdns;
ESP8266WebServer server(80);

// DHT Sensor
uint8_t DHTPin = D3;

// Initialize DHT sensor.
DHT dht(DHTPin, DHTTYPE);

float Temperature;
float Humidity;
void WIFISetup();
