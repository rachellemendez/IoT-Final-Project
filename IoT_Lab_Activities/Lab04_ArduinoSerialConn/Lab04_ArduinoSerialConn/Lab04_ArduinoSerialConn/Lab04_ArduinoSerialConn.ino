const int sensorPin = A0; //Analog input for the light sensor
const int LEDPin = 8; //Plugging the LED to pin 8
const int brightnessThreshold = 220; //Setting the brightness threshold to 220


bool gaveCommand = false; // Tracker if a stop command was issued
bool blinking = false; // Indicates whether the LED is currently blinking

void setup(){
  pinMode(LEDPin, OUTPUT); // Setting the LED pin as output
  Serial.begin(9600); // Start Serial communication for monitoring
  Serial.setTimeout(50); // Reduces waiting time when reading serial input
  Serial.println("System ready. Type 'stop' to stop blinking."); // Instruction message
}

void loop(){
  int sensorValue = analogRead(sensorPin); // Read raw light value (0–1023)
  int mappedValue = map(sensorValue, 0, 1023, 0, 255); // Convert to a 0–255 brightness scale
  
  Serial.print("Brightness: "); // Display brightness reading
  Serial.println(mappedValue);
  
  
  if (mappedValue >= brightnessThreshold && !blinking && !gaveCommand) {
    blinking = true; // Start blinking if above threshold
    Serial.println("Threshold reached - LED blinking started.");
  }
  
  if (blinking){
    digitalWrite(LEDPin, HIGH); // LED on
    delay(100);
    digitalWrite(LEDPin, LOW); // LED off
    delay(100);
    Serial.println("LED Blinking");
  }
  
  if (Serial.available() > 0){ // Check for user command input
    String command = Serial.readStringUntil('\n'); // Read command line
    command.trim(); // Remove whitespace
    command.toLowerCase(); // Convert to lowercase for comparison
    
    if (command == "stop"){
      gaveCommand = true; // Mark that stop was requested
      blinking = false; // Stop LED blinking
      digitalWrite(LEDPin, LOW); // Making sure LED stays off
      Serial.println("Blinking stopped."); // Notifying the user that blinking stopped
    }
  }
}