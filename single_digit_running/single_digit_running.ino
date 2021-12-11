int number = 0;
const bool A[10] = {true, false, true, true, false, true, true, true, true, true};
const bool B[10] = {true, true, true, true, true, false, false, true, true, true};
const bool C[10] = {true, true, false, true, true, true, true, true, true, true};
const bool D[10] = {true, false, true, true, false, true, true, false, true, true};
const bool E[10] = {true, false, true, false, false, false, true, false, true, false};
const bool F[10] = {true, false, false, false, true, true, true, false, true, true};
const bool G[10] = {false, false, true, true, true, true, true, false, true, true};
void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT); pinMode(3, OUTPUT);
  pinMode(4, OUTPUT); pinMode(5, OUTPUT);

  pinMode(13, OUTPUT); pinMode(12, OUTPUT);
  pinMode(11, OUTPUT); pinMode(10, OUTPUT);
}

void loop() {
  if (A[number]) digitalWrite(11, LOW); else digitalWrite(11, HIGH);
  if (B[number]) digitalWrite(10, LOW); else digitalWrite(10, HIGH);
  if (C[number]) digitalWrite(4, LOW); else digitalWrite(4, HIGH);
  if (D[number]) digitalWrite(3, LOW); else digitalWrite(3, HIGH);
  if (E[number]) digitalWrite(2, LOW); else digitalWrite(2, HIGH);
  if (F[number]) digitalWrite(12, LOW); else digitalWrite(12, HIGH);
  if (G[number]) digitalWrite(13, LOW); else digitalWrite(13, HIGH);
  number = (number + 1) % 10;
  delay(500);
}
