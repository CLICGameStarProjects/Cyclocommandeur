#define hall_1 2
#define hall_2 3

int oldState;

void setup() {
  Serial.begin(9600);

  // Wheel
  pinMode(hall_1, INPUT);
  oldState = digitalRead(hall_1);
}

void loop() {
  int newState = digitalRead(hall_1);
  
  Serial.print("State: ");
  Serial.print(newState);

  if (newState != oldState) {
    Serial.print(" - Change of state!");    
  }
  oldState = newState;

  Serial.println();

  delay(10);
}

