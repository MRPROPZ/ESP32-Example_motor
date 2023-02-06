//Testing the DC Motors
//Define Pins
//Motor A
String serialStr;
int enableA = 23;
int pinA1 = 19;
int pinA2 = 18;

//Motor B
int enableB = 5;
int pinB1 = 26;
int pinB2 = 25;

//define time for run
// in milliseconds
int running = 10000; // 10 seconds
boolean play;

void setup() {
  Serial.begin(9600);
  //Config pin modes
  pinMode(enableA, OUTPUT);
  pinMode(pinA1, OUTPUT);
  pinMode(pinA2, OUTPUT);
  pinMode(enableB, OUTPUT);
  pinMode(pinB1, OUTPUT);
  pinMode(pinB2, OUTPUT);
}

void forward() {
  digitalWrite(enableA, HIGH);
  digitalWrite(pinA1, HIGH);
  digitalWrite(pinA2, LOW);
  digitalWrite(enableB, HIGH);
  digitalWrite(pinB1, HIGH);
  digitalWrite(pinB2, LOW);
}

void backward() {
  digitalWrite(enableA, HIGH);
  digitalWrite(pinA2, HIGH);
  digitalWrite(pinA1, LOW);
  digitalWrite(enableB, HIGH);
  digitalWrite(pinB2, HIGH);
  digitalWrite(pinB1, LOW);
  delay(1000);
}

void left() {
  digitalWrite(enableA, HIGH);
  digitalWrite(pinA1, HIGH);
  digitalWrite(pinA2, LOW);
  digitalWrite(enableB, LOW);
  delay(1000);
  digitalWrite(enableA, LOW);
}

void right() {
  digitalWrite(enableB, HIGH);
  digitalWrite(pinB1, HIGH);
  digitalWrite(pinB2, LOW);
  digitalWrite(enableA, LOW);
  delay(1000);
  digitalWrite(enableB, LOW);
}

void stop() {
  digitalWrite(enableA, LOW);
  digitalWrite(enableB, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    serialStr = Serial.readString();
    if (serialStr[0] == 'f') {
      forward();
    }
    else if(serialStr[0] == 'b') {
      backward();
    }
    else if(serialStr[0] == 'r') {
      right();
    }
    else if(serialStr[0] == 'l') {
      left();
    }
    else if(serialStr[0] == 's') {
      stop();
    }
  }

}
