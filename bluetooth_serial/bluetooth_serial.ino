// For the HC-05 Bluetooth Module
// D11   >>>  Rx
// D10   >>>  Tx

#include <SoftwareSerial.h>

SoftwareSerial blu(10, 11); // (RX, TX)
int ledpin = 13; // the LED on the Arduino Uno D13 pin blink on / off
int BluetoothData; // Received data from a phone / computer

void setup() {
  // put your setup code here, to run once:
  blu.begin(9600);
  blu.println("Bluetooth On please press 1 or 0 blink LED ..");
  pinMode(ledpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (blu.available()) {
    BluetoothData = blu.read();
    if (BluetoothData == '1') { // if number 1 pressed ....
      digitalWrite(ledpin, 1);
      blu.println("LED  On D13 ON ! ");
    }
    if (BluetoothData == '0') { // if number 0 pressed ....
      digitalWrite(ledpin, 0);
      blu.println("LED  On D13 Off ! ");
    }
  }
  delay(100);// prepare for next data ...
}
