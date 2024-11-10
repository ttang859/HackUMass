#include <Servo.h>
#include "AccelStepper.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Motor pin definitions:
#define motorPin1 11  // IN1 on the ULN2003 driver
#define motorPin2 10  // IN2 on the ULN2003 driver
#define motorPin3 9   // IN3 on the ULN2003 driver
#define motorPin4 8   // IN4 on the ULN2003 driver

// Define the AccelStepper interface type; 4 wire motor in half step mode:
#define MotorInterfaceType 8

// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper library with 28BYJ-48 stepper motor:
AccelStepper stepper = AccelStepper(MotorInterfaceType, motorPin1, motorPin3, motorPin2, motorPin4);

int pin = 13;

Servo servo;
int angle = 10;
int destination = 0;
int scale = 819.2;
void setup() {
  servo.attach(12);
  servo.write(angle);
  // Set the maximum steps per second:
  stepper.setMaxSpeed(1000);
  // Initialize the Serial
  Serial.begin(9600);
  pinMode(pin, OUTPUT);

  stepper.setCurrentPosition(0);

  delay(1000);
  stepper.setSpeed(500);

  push();
  delay(1000);
  pull();
}

int rotateToPosition(int position) {
  while (stepper.currentPosition() != position) {
    if (stepper.currentPosition() < position) {
      stepper.setSpeed(500);
      stepper.runSpeed();
    } else {
      stepper.setSpeed(-500);
      stepper.runSpeed();
    }
  }
  return;
}

void push() {
  for (angle = 150; angle > 30; angle--) {
    servo.write(angle);
    delay(15);
  }
}

void pull() {
  for (angle = 30; angle < 150; angle++) {
    servo.write(angle);
    delay(15);
  }
}




// void loop() {
//   // Print received Serial data
//   // Serial.println(receivedString);
//   // Set the current position to 0:

//   // CHeck to see if Serial data is being received
//   if (Serial.available() > 0) {

//     // Create a new string variable to receive Serial data
//     char receivedString = "";
//     int convertReceived;

//     // Loop through received data and append to the receivedString variable
//     while (Serial.available() > 0) {
//       receivedString += char(Serial.read());
//       convertReceived = atoi(receivedString);

//       // say what you got:
//       Serial.print("I received: ");
//       Serial.println(receivedString, DEC);

//       while (convertReceived != 0) {
//         rotateToPosition(scale * (((convertReceived % 10) - 1)));
//         convertReceived = convertReceived / 10;
//         push();
//         pull();
//         delay(500);
//       }
//     }
//   }
// }

void loop() {
  // Check to see if Serial data is being received
  if (Serial.available() > 0) {

    // Create a new string variable to receive Serial data
    String receivedString = "";

    // Loop through received data and append to the receivedString variable
    while (Serial.available() > 0) {
      char receivedChar = Serial.read();  // Read a single character
      if (receivedChar == '\n') {
        break;  // Exit loop on newline character (if you’re sending newline-terminated data)
      }
      receivedString += receivedChar;
      delay(1);  // Short delay to allow Serial buffer to fill
    }

    // Convert receivedString to integer
    int convertReceived = receivedString.toInt();

    // Print what you received
    Serial.print("I received: ");
    Serial.println(receivedString);

    // Process the received integer
    while (convertReceived != 0) {
      int position = (convertReceived % 10) - 1;
      rotateToPosition(scale * position);
      convertReceived = convertReceived / 10;
      push();
      pull();
      delay(500);
    }
  }
}
