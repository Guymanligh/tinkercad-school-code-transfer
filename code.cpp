unsigned const int A = 13;
unsigned const int B = 12;
unsigned const int C = 11;
unsigned const int D = 10;
unsigned const int E = 9;
unsigned const int F = 8;
unsigned const int G = 7;
unsigned const int H = 6;

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(H, OUTPUT);
}

void setSegments(int a, int b, int c, int d, int e, int f, int g, int h) {
  digitalWrite(A, a);
  digitalWrite(B, b);
  digitalWrite(C, c);
  digitalWrite(D, d);
  digitalWrite(E, e);
  digitalWrite(F, f);
  digitalWrite(G, g);
  digitalWrite(H, h);
}

// Ниже сохранены комбинации из кода на фото (при необходимости подправьте HIGH/LOW под свою схему)
void zero() {
  setSegments(LOW, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW);
}

void one() {
  setSegments(LOW, LOW, LOW, HIGH, LOW, LOW, HIGH, LOW);
}

void two() {
  setSegments(HIGH, LOW, HIGH, HIGH, HIGH, HIGH, LOW, LOW);
}

void three() {
  setSegments(HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH, LOW);
}

void four() {
  setSegments(HIGH, HIGH, LOW, HIGH, LOW, LOW, HIGH, LOW);
}

void five() {
  setSegments(HIGH, HIGH, HIGH, LOW, LOW, HIGH, HIGH, LOW);
}

void six() {
  setSegments(HIGH, HIGH, HIGH, LOW, HIGH, HIGH, HIGH, LOW);
}

void seven() {
  setSegments(LOW, LOW, HIGH, HIGH, LOW, LOW, HIGH, LOW);
}

void eight() {
  setSegments(HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW);
}

void nine() {
  setSegments(HIGH, HIGH, HIGH, HIGH, LOW, HIGH, HIGH, LOW);
}

void loop() {
  one();   delay(1000);
  two();   delay(1000);
  three(); delay(1000);
  four();  delay(1000);
  five();  delay(1000);
  six();   delay(1000);
  seven(); delay(1000);
  eight(); delay(1000);
  nine();  delay(1000);
  zero();  delay(1000);
}
