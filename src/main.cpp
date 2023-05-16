/*
  Simple example for receiving
  
  https://github.com/sui77/rc-switch/
*/
#include <Arduino.h>
#include <RCSwitch.h>

#define PIN_RELAY   	22
#define PIN_RF      	23
#define PIN_LED      	32

RCSwitch mySwitch = RCSwitch();

void setup() {
	Serial.begin(115200);
	pinMode(PIN_RELAY, OUTPUT);
	pinMode(PIN_LED, OUTPUT);
	pinMode(PIN_RF, INPUT);
	delay(10);
	digitalWrite(PIN_RELAY,LOW);
	digitalWrite(PIN_LED,LOW);
	mySwitch.enableReceive(digitalPinToInterrupt(PIN_RF));  // Receiver on interrupt 0 => that is pin #2
}

void loop() {
	if (mySwitch.available()) {
		Serial.print("Received ");
		Serial.print( mySwitch.getReceivedValue() );
		if(mySwitch.getReceivedValue() == 925747){
			digitalWrite(PIN_RELAY,HIGH);
			digitalWrite(PIN_LED,HIGH);
		}
		Serial.print(" / ");
		Serial.print( mySwitch.getReceivedBitlength() );
		Serial.print("bit ");
		Serial.print("Protocol: ");
		Serial.println( mySwitch.getReceivedProtocol() );
		mySwitch.resetAvailable();
	}
	// digitalWrite(PIN_RELAY,LOW);
	// delay(1000);
	// digitalWrite(PIN_RELAY,HIGH);
	// delay(1000);

}
