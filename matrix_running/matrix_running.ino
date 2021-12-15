const int ROW_PINS[8] = {9, 7, 6, 8, 2, 5, 3, 4};
const int COLUMN_PINS[8] = {13, A1, A2, A0, A3, 12, 11, 10};
int time = 0;
int state = 0;

bool mat[8][8] =
    {
        {0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,1,0},
        {1,1,1,0,0,1,1,1},
        {1,1,1,1,1,1,1,1},
        {0,1,1,1,1,1,1,0},
        {0,0,1,1,1,1,0,0},
        {0,0,0,1,1,0,0,0},
        {0,0,0,0,0,0,0,0},
    };

void setup() {
  for (int i = 2; i <= 13; i++) pinMode(i, OUTPUT);
  pinMode(A0, OUTPUT); pinMode(A1, OUTPUT); pinMode(A2, OUTPUT); pinMode(A3, OUTPUT); 
}

void writeRow(bool row[], int index) {
  digitalWrite(ROW_PINS[index], HIGH);
  for (int i = 0; i < 8; i++)
    if (mat[index][i]) digitalWrite(COLUMN_PINS[i], LOW);
    else digitalWrite(COLUMN_PINS[i], HIGH);
  
}

void move_mat() {
  int temp[8]; 
  for (int i = 0; i < 8; i++) temp[i] = mat[7][i];
  for (int i = 7; i > 0; i--) {
     for (int j = 0; j < 8; j++) mat[i][j] = mat[i - 1][j];
  }
  for (int i = 0; i < 8; i++) mat[0][i] = temp[i];
}

void loop() {
  time++;
  if (time % 10 == 0) {
    move_mat(); time = 0;
  }
  for (int i = 0; i < 8; i++) {
    writeRow(mat[i], i);
    delay(1);
    digitalWrite(ROW_PINS[i], LOW);
    for (int i = 0; i < 8; i++) digitalWrite(COLUMN_PINS[i], HIGH);
  }
}
