// SMART PARKING SYSTEM - 1 SENZOR TEST
const int TRIG = 2;
const int ECHO = 3;
const int LED_RED = 4;
const int LED_GREEN = 5;
const int DISTANCE_THRESHOLD = 20;

void setup() {
  Serial.begin(9600);
  Serial.println("\n=== SMART PARKING SYSTEM STARTED ===");
  Serial.println("Testing 1 Parking Space...\n");
  
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_RED, LOW);
  
  delay(1000);
}

void loop() {
  int distance = measureDistance();
  
  if (distance < DISTANCE_THRESHOLD) {
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_GREEN, LOW);
    Serial.print("OCCUPIED - Distance: ");
  } else {
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, HIGH);
    Serial.print("FREE - Distance: ");
  }
  
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(500);
}

int measureDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  long duration = pulseIn(ECHO, HIGH, 30000);
  
  int distance = duration * 0.0343 / 2;
  
  if (distance == 0 || distance > 100) {
    return 100;
  }
  
  return distance;
}