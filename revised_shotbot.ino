const int threshold = 20;       // Set the threshold value to 10
unsigned long interval = 2000; // Time window in milliseconds
unsigned long previousMillis = 0;
int ledPin = 9;
int motorPin = 3; // Define the digital pin connected to the base of the transistor


void setup() {
  // Initialize your setup here
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT); // Set the motorPin as an OUTPUT

}

void loop() {
  int sensorValue = analogRead(A0); // Read the analog value
  
  // Check if the current sensor value is greater than or equal to the threshold
  if (sensorValue >= threshold) {
  Serial.println("STARTED");
  unsigned long startMillis = millis();  // Start the timer
  int exceedCount = 0;
  while (millis() - startMillis < interval) {
    int sensorValue = analogRead(A0);
    if (sensorValue >= threshold) {
    delay(30);
    exceedCount++;
    delay(100);
    Serial.println("KNOCK WHILE TIMED");
    }}
  Serial.println("Times hit: ");
  Serial.println(exceedCount);

  if (exceedCount >=3 && exceedCount < 5){
  digitalWrite(ledPin, HIGH);
  digitalWrite(motorPin, HIGH);
  
  // Delay for 3 seconds (3000 milliseconds)
  delay(8500);
  
  // Turn off the LED
  digitalWrite(ledPin, LOW);
  digitalWrite(motorPin, LOW);
  delay(1000);
  Serial.println("Ready for another go!");
  Serial.println();
  }
  
  
  // The rest of your loop code runs here
}}
