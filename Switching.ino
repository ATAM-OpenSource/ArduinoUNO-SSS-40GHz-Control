// Truht Table for switching

// C4 C3 C2 C1 Result
// 1  1  1  0  J1
// 1  1  0  1  J2
// 1  0  1  1  J3
// 0  1  1  1  J4

// GND         Gray
// +5Vdc       Orange
int C1 = 4; // Purple
int C2 = 5; // Blue
int C3 = 6; // Green
int C4 = 7; // Yellow

String port_number;
void setup() {
  Serial.begin(9600);
  pinMode(C1, OUTPUT);
  pinMode(C2, OUTPUT);
  pinMode(C3, OUTPUT);
  pinMode(C4, OUTPUT);
  digitalWrite(C1, LOW);
  digitalWrite(C2, LOW);
  digitalWrite(C3, LOW);
  digitalWrite(C4, LOW);
  delay(100);
  Serial.println("Please select a port number 1,2,3,4 and C for close all port...");
}

void loop() {
  if (Serial.available()) {
    port_number = Serial.readStringUntil('\n');
    Serial.print("Selected port number is: ");
    Serial.print(port_number);
    Serial.println(" opening...");

    if (port_number.equals("1")){

      digitalWrite(C1, LOW);
      digitalWrite(C2, HIGH);
      digitalWrite(C3, HIGH);
      digitalWrite(C4, HIGH);
      Serial.println("PORT1 is open.");
    }
    else if (port_number.equals("2")){
      digitalWrite(C1, HIGH);
      digitalWrite(C2, LOW);
      digitalWrite(C3, HIGH);
      digitalWrite(C4, HIGH);
      Serial.println("PORT2 is open.");
    }
    else if (port_number.equals("3")) {
      digitalWrite(C1, HIGH);
      digitalWrite(C2, HIGH);
      digitalWrite(C3, LOW);
      digitalWrite(C4, HIGH);
      Serial.println("PORT3 is open.");
    }
    else if (port_number.equals("4")) {
      digitalWrite(C1, HIGH);
      digitalWrite(C2, HIGH);
      digitalWrite(C3, HIGH);
      digitalWrite(C4, LOW);
      Serial.println("PORT4 is open.");
    }
    else if (port_number.equals("C")) {
      digitalWrite(C1, LOW);
      digitalWrite(C2, LOW);
      digitalWrite(C3, LOW);
      digitalWrite(C4, LOW);
      Serial.println("All ports are closed.");
    }
    else {
      Serial.println("Invalid syntax! Use 1,2,3,4 and C for close all port...");
    }
  }
}
