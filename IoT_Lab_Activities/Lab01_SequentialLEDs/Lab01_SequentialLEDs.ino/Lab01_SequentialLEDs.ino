// Group Activity 1
// Arrojo, Betina
// Mariano, Jamil
// Mendez, Rachelle

//Here we declare 5 pins to be used, specifically pins from 12 to 8, enclosed in curly braces.
int ledPins[5] = {12, 11, 10, 9, 8};


void setup(){ //void means the function returns nothing and setup() runs once at the start of the program which initializes and sets the initial values
 for (int i = 0; i < 5; i++){
    //int ledPin[i] = number--; debugging
    //Serial.print(ledPin[i]); debugging
    Serial.println(ledPins[i]);//Prints the data at position i from the ledPins array (declared above).
    pinMode(ledPins[i], OUTPUT); //Sets the pin from ledPins[i] as an output.
  }
  
}

void loop(){ //loop() contains the code that turns the LEDs on and off repeatedly
  for (int i = 0; i < 5; i++){
    digitalWrite(ledPins[i], HIGH); //"HIGH" turns the pin on
    delay(1000); //Waits for 1000 milliseconds or 1 second after the pin is turned on.
  }
  
  for (int i = 0; i < 5; i++){
    digitalWrite(ledPins[i], LOW); //"LOW" turns the pin off
    delay(1000); //Waits for 1000 milliseconds or 1 second after the pin is turned off.
  }
}