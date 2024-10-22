// Arduino Fixed-point Vehicle Proximity Detector
// Authors: Krishna Rawat, Thasleem Sulthan, Abhinav K Anudath
// Course: 21CSS201T - Computer Organization and Architecture
// Institution: SRM Institute of Science and Technology

// Pin definitions
const int TRIGGER_PIN = 8;  // Ultrasonic sensor trigger pin
const int ECHO_PIN = 9;     // Ultrasonic sensor echo pin
const int RED_LED = 13;     // Stop signal
const int YELLOW_LED = 12;  // Warning signal
const int GREEN_LED = 11;   // Safe signal

// Distance thresholds (in inches)
const int STOP_DISTANCE = 6;    // Threshold for danger zone
const int WARN_DISTANCE = 60;   // Threshold for warning zone

// Variables for distance calculation
long duration;  // Time taken for pulse to return
long distance;  // Calculated distance

void setup() {
  // Configure LED pins as outputs
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Initial LED test
  testLEDs();
}

void loop() {
  // Measure distance using ultrasonic sensor
  distance = measureDistance();
  
  // Update LED indicators based on distance
  updateLEDs(distance);
  
  // Print distance to serial monitor
  printDistance(distance);
  
  // Short delay to prevent flooding serial monitor
  delay(200);
}

// Function to measure distance using ultrasonic sensor
long measureDistance() {
  // Generate trigger pulse
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(5);
  digitalWrite(TRIGGER_PIN, LOW);
  
  // Read echo pulse
  pinMode(ECHO_PIN, INPUT);
  duration = pulseIn(ECHO_PIN, HIGH);
  
  // Convert time to distance (inches)
  // Speed of sound = 343m/s = 13,500 inches/s
  // Distance = (Time × Speed) ÷ 2
  // Using 72 as conversion factor (derived from speed of sound)
  return duration / 72 / 2;
}

// Function to update LED indicators based on distance
void updateLEDs(long dist) {
  if (dist >= WARN_DISTANCE) {
    // Safe zone - Green LED
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
  }
  else if (dist > STOP_DISTANCE && dist < WARN_DISTANCE) {
    // Warning zone - Yellow LED
    digitalWrite(RED_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
  }
  else {
    // Danger zone - Red LED
    digitalWrite(RED_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
  }
}

// Function to print distance to serial monitor
void printDistance(long dist) {
  Serial.print("Distance: ");
  Serial.print(dist);
  Serial.println(" inches");
}

// Function to test LEDs during setup
void testLEDs() {
  // Test each LED in sequence
  digitalWrite(RED_LED, HIGH);
  delay(500);
  digitalWrite(RED_LED, LOW);
  
  digitalWrite(YELLOW_LED, HIGH);
  delay(500);
  digitalWrite(YELLOW_LED, LOW);
  
  digitalWrite(GREEN_LED, HIGH);
  delay(500);
  digitalWrite(GREEN_LED, LOW);
}
