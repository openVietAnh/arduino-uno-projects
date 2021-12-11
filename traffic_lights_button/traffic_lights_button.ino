const int redPin = 7;
const int yellowPin = 6;
const int greenPin = 5;

bool red = false, yellow = false, green = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);

  pinMode(7, INPUT);
  pinMode(6, INPUT);
  pinMode(5, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 5; i <= 7; i++) { 
    int buttonState = digitalRead(i);
    if (buttonState == HIGH) {
      switch (i) {
        case 5:
          green = true; red = false; yellow = false;
          break;
        case 6:
          yellow = true; red = false; green = false;
          break;
        case 7:
          red = true; yellow = false; green = false;
          break; 
      }
      break;
    }
  }

  if (red) digitalWrite(13, HIGH); else digitalWrite(13, LOW);
  if (yellow) digitalWrite(12, HIGH); else digitalWrite(12, LOW);
  if (green) digitalWrite(11, HIGH); else digitalWrite(11, LOW);
  
}
