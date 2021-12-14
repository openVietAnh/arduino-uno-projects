#include <Servo.h>

Servo servo;
int angle = 0;
const bool A[10] = {true, false, true, true, false, true, true, true, true, true};
const bool B[10] = {true, true, true, true, true, false, false, true, true, true};
const bool C[10] = {true, true, false, true, true, true, true, true, true, true};
const bool D[10] = {true, false, true, true, false, true, true, false, true, true};
const bool E[10] = {true, false, true, false, false, false, true, false, true, false};
const bool F[10] = {true, false, false, false, true, true, true, false, true, true};
const bool G[10] = {false, false, true, true, true, true, true, false, true, true};
const int digitPins[4] = {10, 13, 12, 11};

void setup() {
  pinMode(A2, OUTPUT);
  servo.attach(A2);
  servo.write(angle);
  pinMode(A0, INPUT); pinMode(A1, INPUT);
  pinMode(2, OUTPUT); pinMode(3, OUTPUT); pinMode(4, OUTPUT); pinMode(5, OUTPUT); pinMode(6, OUTPUT); 
  pinMode(7, OUTPUT); pinMode(8, OUTPUT); pinMode(9, OUTPUT); pinMode(10, OUTPUT); pinMode(11, OUTPUT);
  pinMode(12, OUTPUT); pinMode(13, OUTPUT);
  digitalWrite(4, HIGH);
}

void loop() 
{
  int turnLeftState = digitalRead(A1);
  int turnRightState = digitalRead(A0);
  if (turnLeftState == HIGH) if (angle > 0) angle--;
  if (turnRightState == HIGH) if (angle < 180) angle++;                     
  servo.write(angle);
  for (int i = 0; i < 4; i++) digitalWrite(digitPins[i], LOW);
  int division = 1;
  for (int i = 0; i < 4; i++) {
    int digit = angle / division % 10;
    digitalWrite(digitPins[i], HIGH);
    if (A[digit]) digitalWrite(7, LOW); else digitalWrite(7, HIGH);
    if (B[digit]) digitalWrite(9, LOW); else digitalWrite(9, HIGH);
    if (C[digit]) digitalWrite(5, LOW); else digitalWrite(5, HIGH);
    if (D[digit]) digitalWrite(3, LOW); else digitalWrite(3, HIGH);
    if (E[digit]) digitalWrite(2, LOW); else digitalWrite(2, HIGH);
    if (F[digit]) digitalWrite(8, LOW); else digitalWrite(8, HIGH);
    if (G[digit]) digitalWrite(6, LOW); else digitalWrite(6, HIGH);
    delay(1); digitalWrite(digitPins[i], LOW); division *= 10;
  }
  delay(5);          
}
