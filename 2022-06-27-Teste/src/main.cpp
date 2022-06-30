#include <Arduino.h>
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

const int Analog_channel_pin= 15;
int ADC_VALUE = 0;
int bits = 4095;
float Max_tension = 3.3;
double voltage_value = 0; 
void setup() 
{
char received;

Serial.begin(9600);
analogSetAttenuation(ADC_11db);

pinMode(Analog_channel_pin, ANALOG);

SerialBT.begin();
Serial.println("Bluetooth Started! Ready to pair...");
}



void loop() 
{
    ADC_VALUE = analogRead(Analog_channel_pin);
    voltage_value = (ADC_VALUE * Max_tension ) / (bits);
    delay(250);
    
    if (SerialBT.available())
    {
        SerialBT.println("Recebido: ");
        SerialBT.print((voltage_value));
    }
    if (Serial.available())
    {
        SerialBT.println(voltage_value);
    }
}