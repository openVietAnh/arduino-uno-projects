const int digitPins[4] = {10, 13, 12, 11};
long int time = 0;
const bool A[10] = {true, false, true, true, false, true, true, true, true, true};
const bool B[10] = {true, true, true, true, true, false, false, true, true, true};
const bool C[10] = {true, true, false, true, true, true, true, true, true, true};
const bool D[10] = {true, false, true, true, false, true, true, false, true, true};
const bool E[10] = {true, false, true, false, false, false, true, false, true, false};
const bool F[10] = {true, false, false, false, true, true, true, false, true, true};
const bool G[10] = {false, false, true, true, true, true, true, false, true, true};
int number = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT); pinMode(3, OUTPUT); pinMode(4, OUTPUT); pinMode(5, OUTPUT); pinMode(6, OUTPUT); 
  pinMode(7, OUTPUT); pinMode(8, OUTPUT); pinMode(9, OUTPUT); pinMode(10, OUTPUT); pinMode(11, OUTPUT);
  pinMode(12, OUTPUT); pinMode(13, OUTPUT);
  digitalWrite(4, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 4; i++) digitalWrite(digitPins[i], LOW);
  int division = 1;
  for (int i = 0; i < 4; i++) {
    int digit = number / division % 10;
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
  time++;
  if (time % 100 == 0) if (number < 9999) number++;
}
