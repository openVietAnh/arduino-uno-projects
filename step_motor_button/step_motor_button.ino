#define A 2
#define B 3
#define C 4
#define D 5

void setup() {
  pinMode(A,OUTPUT); pinMode(B,OUTPUT); pinMode(C,OUTPUT); pinMode(D,OUTPUT);
  pinMode(13, INPUT); pinMode(12, INPUT);
}

void one_step_clockwise() {
  digitalWrite(A, HIGH); delay(1); digitalWrite(D, LOW); delay(1);
  digitalWrite(B, HIGH); delay(1); digitalWrite(A, LOW); delay(1);
  digitalWrite(C, HIGH); delay(1); digitalWrite(B, LOW); delay(1);
  digitalWrite(D, HIGH); delay(1); digitalWrite(C, LOW); delay(1);
}

void one_step_counter_clockwise() {
  digitalWrite(A, HIGH); delay(1); digitalWrite(B, LOW); delay(1);
  digitalWrite(D, HIGH); delay(1); digitalWrite(A, LOW); delay(1);
  digitalWrite(C, HIGH); delay(1); digitalWrite(D, LOW); delay(1);
  digitalWrite(B, HIGH); delay(1); digitalWrite(C, LOW); delay(1);
}

void loop(){
  int turnLeftButtonState = digitalRead(13);
  int turnRightButtonState = digitalRead(12);
  if ((turnLeftButtonState == HIGH) && (turnRightButtonState == LOW))
      one_step_counter_clockwise();
  if ((turnLeftButtonState == LOW) && (turnRightButtonState == HIGH))
    one_step_clockwise();
}
