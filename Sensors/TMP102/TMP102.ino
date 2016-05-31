/*
Cayenne TMP102 Example

This sketch shows how to send temperature data to a TMP102 Sensor in the Cayenne Dashboard.

Steps:
1. In the Cayenne Dashboard add a new TMP102 widget.
2. Set the widget to Value Display.
3. Select Virtual Pins and a virtual channel number.
4. Set VIRTUAL_CHANNEL below to the channel number you selected.
5. Attach a TMP102 to your Arduino.
   Schematic:
   TMP102    Arduino
   [VCC] --- [3V3]
   [GND] --- [GND]
   [ADD0] -- [GND]
   [SDA] --- [Analog Pin 4] (The SDA may be different on some devices, e.g. for Arduino Mega the SDA pin is Digital Pin 20)
   [SCL] --- [Analog Pin 5] (The SCL may be different on some devices, e.g. for Arduino Mega the SCL pin is Digital Pin 21)
6. Set the tmp102Address variable below to match the ADD0. ADD0 connected to GND corresponds to an address of 0x48.
7. Set the authentication token below to match the Arduino token from the Dashboard.
8. Compile and upload this sketch.
9. Once the Arduino connects to the Dashboard it should automatically update the TMP102 widget with data.
*/

#define CAYENNE_PRINT Serial   // Comment this out to disable prints and save space
#include <CayenneTMP102.h>
#include <CayenneEthernet.h>   // Change this to use a different communication device. See Communications examples.

// Cayenne authentication token. This should be obtained from the Cayenne Dashboard.
char token[] = "AuthenticationToken";

// Virtual Channel of the TMP102 widget.
#define VIRTUAL_CHANNEL V1

// Address used to read from the TMP102. This is determined by the ADD0 pin on the TMP102.
// Connecting it to ground means the sensor will use 0x48 for the address.  See the TMP102 datasheet for more info.
const int tmp102Address = 0x48;

TMP102 tmpSensor(tmp102Address);

void setup()
{
	Serial.begin(9600);
	Wire.begin();
	Cayenne.begin(token);
}

void loop()
{
	Cayenne.run();
}

// This function is called when the Cayenne widget requests data for the Virtual Channel.
CAYENNE_OUT(VIRTUAL_CHANNEL)
{
	// This command writes the temperature in Celsius to the Virtual Channel.
	Cayenne.celsiusWrite(VIRTUAL_CHANNEL, tmpSensor.getCelsius());
	// To send the temperature in Fahrenheit or Kelvin use the corresponding code below.
	//Cayenne.fahrenheitWrite(VIRTUAL_CHANNEL, tmpSensor.getFahrenheit());
	//Cayenne.kelvinWrite(VIRTUAL_CHANNEL, tmpSensor.getKelvin());
}
