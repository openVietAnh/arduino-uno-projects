int head = 3;
int tail = 0;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  for (int i = tail; i <= head; i++) {
    digitalWrite(i + 2, HIGH);
  }
}

void loop() {
  head = (head + 1) % 12;
  digitalWrite(head + 2, HIGH);
  digitalWrite(tail + 2, LOW);
  tail = (tail + 1) % 12;
  delay(125);                       
}
