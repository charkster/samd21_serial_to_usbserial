/*

  Multiple Serial test

  Receives from the main serial port, sends to the others.

  Receives from serial port 1, sends to the main serial (Serial 0).

  This example works only with boards with more than one serial like Arduino Mega, Due, Zero etc.

  The circuit:

  - any serial device attached to Serial port 1

  - Serial Monitor open on Serial port 0

  created 30 Dec 2008

  modified 20 May 2012

  by Tom Igoe & Jed Roach

  modified 27 Nov 2015

  by Arturo Guadalupi

  This example code is in the public domain.

*/
// small changes to clarify the USB serial port, and select BAUD_RATE
// This configures the SAMD21 QTPY to be a USB serial bridge

#define SerialUSB Serial
#define BAUD_RATE 2000000 // 2Mpbs

void setup() {

  // initialize both serial ports:

  SerialUSB.begin(BAUD_RATE);

  Serial1.begin(BAUD_RATE);
}

void loop() {

  // read from port 1, send to USB port:

  if (Serial1.available()) {

    int inByte = Serial1.read();

    SerialUSB.write(inByte);
//    SerialUSB.println(inByte);

  }

  // read from USB port, send to port 1:

  if (SerialUSB.available()) {

    int inByte = SerialUSB.read();

    Serial1.write(inByte);

  }
}
