#define A 2
#define B 3
#define C 4
#define D 5
 
#define NUMBER_OF_STEPS_PER_REV 512

bool clockwise = true;

void setup() {
  pinMode(A,OUTPUT); pinMode(B,OUTPUT); pinMode(C,OUTPUT); pinMode(D,OUTPUT);
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
  int i = 0;
  for (int i = 0; i < NUMBER_OF_STEPS_PER_REV; i++ ) {
    if (clockwise)
      one_step_clockwise();
    else one_step_counter_clockwise();
  }
  clockwise = !clockwise;
}
