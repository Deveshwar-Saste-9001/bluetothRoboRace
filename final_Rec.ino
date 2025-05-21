#include <SoftwareSerial.h>

SoftwareSerial mySerial(11, 10); // RX, TX

String receivedData = "";

// TB6612FNG Motor Driver Control Pins
const int STBY = 6;  // Standby pin

// Motor A pins
const int PWMA = 3;  // PWM pin for Motor A
const int AIN1 = 4;  // Direction pin 1 for Motor A
const int AIN2 = 5;  // Direction pin 2 for Motor A

// Motor B pins
const int PWMB = 9;  // PWM pin for Motor B
const int BIN1 = 7;  // Direction pin 1 for Motor B
const int BIN2 = 8;  // Direction pin 2 for Motor B

void stop() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
}

void backward() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
}

void forward() {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
}

void right() {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
}

void left() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
}

void setup() {
  mySerial.begin(38400);   // Start SoftwareSerial on pins 10(RX), 11(TX)
Serial.begin(38400);
  pinMode(STBY, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  digitalWrite(STBY, HIGH); // Disable standby
}

void loop() {
  if (mySerial.available()) {
    char data = mySerial.read();
Serial.println(data);
    if (data == 'D') {
      analogWrite(PWMA, 255);
      analogWrite(PWMB, 255);
      forward();
      mySerial.println("FORWARD");
    } else if (data == 'B') {
      analogWrite(PWMA, 155);
      analogWrite(PWMB, 155);
      right();
      mySerial.println("RIGHT");
    } else if (data == 'A') {
      analogWrite(PWMA, 155);
      analogWrite(PWMB, 155);
      left();
      mySerial.println("LEFT");
    } else if (data == 'C') {
      analogWrite(PWMA, 255);
      analogWrite(PWMB, 255);
      backward();
      mySerial.println("BACKWARD");
    } else if (data == 'E') {
      stop();
      mySerial.println("STOP");
    }
  }
}
