/*
Cayenne Ethernet Manual IP Example
Adapted from Blynk's Arduino_Ethernet_Manual Example

This sketch connects to the Cayenne server using an Arduino Ethernet Shield W5100 and a 
manually specified MAC address, IP and gateway.

For Cayenne Dashboard widgets using digital or analog pins this sketch will automatically
send data on those pins to the Cayenne server. If the widgets use Virtual Channels, data
should be sent to those channels using virtualWrites. Examples for sending and receiving
Virtual Channel data are under the Basics folder.
*/

//#define CAYENNE_DEBUG         // Uncomment to show debug messages
#define CAYENNE_PRINT Serial  // Comment this out to disable prints and save space
#include <CayenneEthernet.h>

// Cayenne authentication token. This should be obtained from the Cayenne Dashboard.
char token[] = "AuthenticationToken";

// Mac address should be different for each device in your LAN
byte arduino_mac[] = { 0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED };
IPAddress arduino_ip(10, 0, 0, 20);
IPAddress dns_ip(8, 8, 8, 8);
IPAddress gateway_ip(10, 0, 0, 1);
IPAddress subnet_mask(255, 255, 255, 0);

void setup()
{
	Serial.begin(9600);
	Cayenne.begin(token, arduino_ip, dns_ip, gateway_ip, subnet_mask, arduino_mac);
}

void loop()
{
	Cayenne.run();
}
