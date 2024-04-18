// Define motor control pins for Motor A
int enA = 9;
int in1 = 8;
int in2 = 7;

// Define motor control pins for Motor B
int enB = 3;
int in3 = 5;
int in4 = 4;

void setup() {
  // Set motor control pins as output
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    // Forward
    if (command == 'F') {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enA, 200);
      analogWrite(enB, 200);
    }
    // Backward
    else if (command == 'B') {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(enA, 200);
      analogWrite(enB, 200);
    }
    // Left
    else if (command == 'L') {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enA, 200);
      analogWrite(enB, 200);
    }
    // Right
    else if (command == 'R') {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(enA, 200);
      analogWrite(enB, 200);
    }
    // Stop
    else if (command == 'S') {
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      analogWrite(enA, 0);
      analogWrite(enB, 0);
    }
  }
}
