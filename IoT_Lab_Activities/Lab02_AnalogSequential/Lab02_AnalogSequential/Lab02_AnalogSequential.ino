// Group Activity 2
// Arrojo, Betina
// Mariano, Jamil
// Mendez, Rachelle

int ledpins[] = {12,11,10,9,8}; // Declare the LED pins.
int lednum = 5; // The number of LED pins to be used.

void setup()
{   
  int i = 0;
  while (i < lednum){
    pinMode(ledpins[i], OUTPUT); // This sets the pins as an output.
    i++; // Since the variable 'i' starts at 0, this is to ensure that every LED pin in the array is set as an output.
  }
}

void loop()
{
  int i = 0;
  
  while (i < lednum) { // This keeps the code looping until variable 'i' goes below 0.
    analogWrite(ledpins[i], 255); // Sets the LEDs to full brightness.
    delay(1000); // Wait for 1 second.
    i++; // This moves forward through the array. Moving from pin 12 all the way to pin 8.
  }
 
  i = 0;
  
  while (i < lednum) { // 
    analogWrite(ledpins[i], 0); // Sets the LEDs off.
    delay(1000); // Wait for 1 second.
    i++; // This moves forward through the array. Moving from pin 12 all the way to pin 8.
  } 
}