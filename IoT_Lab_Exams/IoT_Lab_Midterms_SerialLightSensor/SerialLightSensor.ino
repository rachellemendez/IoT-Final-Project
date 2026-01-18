const int photoresistorPin = A0;
const int greenLedPin = 11;
const int yellowLedPin = 12;
const int redLedPin = 13;

enum Mode {
  MANUAL,
  AUTOMATIC
};
Mode currentMode = MANUAL;

int lowThreshold = 40;
int highThreshold = 70;

const int lowThreshold_auto = 40;
const int highThreshold_auto = 70;

unsigned long lastSerialPrintTime = 0;
const long serialPrintInterval = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(greenLedPin, OUTPUT);
  pinMode(yellowLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  Serial.println("Smart Light System Initialized.");
  Serial.println("Mode: MANUAL");
  Serial.println("Type 'MODE AUTO' or 'MODE MANUAL' to change modes.");
  Serial.println("In MANUAL mode, use 'SET LOW n' or 'SET HIGH n' (n=0-100).");
}

void loop() {
  checkSerialCommands();
  unsigned long currentTime = millis(); 
  if (currentTime - lastSerialPrintTime >= serialPrintInterval) {
    lastSerialPrintTime = currentTime;
    int sensorValue = analogRead(photoresistorPin);
    int intensityPercent = map(sensorValue, 0, 1023, 0, 100);
    updateLEDs(intensityPercent);
    printSerialStatus(intensityPercent);
  }
}

void checkSerialCommands() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim(); //
    if (command.length() == 0) {
      return;
    }
    String commandUpper = command;
    commandUpper.toUpperCase(); //MODE MANUAL
    if (commandUpper == "MODE AUTO") {
      if (currentMode != AUTOMATIC) {
        currentMode = AUTOMATIC;
        Serial.println("Mode changed to AUTOMATIC.");
      }
    } else if (commandUpper == "MODE MANUAL") {
      if (currentMode != MANUAL) {
        currentMode = MANUAL;
        Serial.println("Mode changed to MANUAL.");
      }
    } else if (commandUpper.startsWith("SET LOW ") && currentMode == MANUAL) {
      parseSetCommand(command, "SET LOW ");
    } else if (commandUpper.startsWith("SET HIGH ") && currentMode == MANUAL) {
      parseSetCommand(command, "SET HIGH ");
    } else {
      Serial.println("Error: Wrong command");
    }
  }
}

void parseSetCommand(String command, String prefix) { // SET LOW
  String valueStr = command.substring(prefix.length()); /// command.substring(6)
  int n = valueStr.toInt();
  if (n >= 0 && n <= 100) {
    if (prefix == "SET LOW ") {
      if (n < highThreshold) {
        lowThreshold = n;
        Serial.print("New Low Threshold: ");
        Serial.println(lowThreshold);
      } else {
        Serial.println("Error: Low threshold must be less than high threshold.");
      }
    } else if (prefix == "SET HIGH ") {
      if (n > lowThreshold) {
        highThreshold = n;
        Serial.print("New High Threshold: ");
        Serial.println(highThreshold);
      } else {
        Serial.println("Error: High threshold must be greater than low threshold.");
      }
    }
  } else {
    Serial.println("Error: Value must be between 0 and 100.");
  }
}

void updateLEDs(int intensity) {
  int currentLow, currentHigh;
  if (currentMode == MANUAL) {
    currentLow = lowThreshold;
    currentHigh = highThreshold;
  } else {
    currentLow = lowThreshold_auto;
    currentHigh = highThreshold_auto;
  }
  if (intensity <= currentLow) {
    digitalWrite(greenLedPin, HIGH);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, LOW);
  } else if (intensity > currentLow && intensity <= currentHigh) {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, HIGH);
    digitalWrite(redLedPin, LOW);
  } else {
    digitalWrite(greenLedPin, LOW);
    digitalWrite(yellowLedPin, LOW);
    digitalWrite(redLedPin, HIGH);
  }
}

void printSerialStatus(int intensity) {
  String activeLED = "";
  String environment = "";
  int currentLow, currentHigh;
  if (currentMode == MANUAL) {
    currentLow = lowThreshold;
    currentHigh = highThreshold;
  } else {
    currentLow = lowThreshold_auto;
    currentHigh = highThreshold_auto;
  }

  if (intensity <= currentLow) {
    activeLED = "Green";
    environment = "Cloudy";
  } else if (intensity > currentLow && intensity <= currentHigh) {
    activeLED = "Yellow";
    environment = "Normal";
  } else {
    activeLED = "Red";
    environment = "Bright Sunlight";
  }

  Serial.print("Light Intensity: ");
  Serial.print(intensity);
  Serial.println("%");
  Serial.print("Active LED: ");
  Serial.println(activeLED); 
  Serial.print("Current Mode: ");
  if (currentMode == 0) {
  Serial.println("Manual"); 
  } else if (currentMode == 1) {
    Serial.println("Automatic"); 
  }
  
  if (currentMode == AUTOMATIC) {
    Serial.print("Environment: ");
    Serial.println(environment);
  }
  Serial.println();
}
