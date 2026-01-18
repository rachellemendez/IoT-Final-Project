// INITIALIZE 
#define notifyPin 12
#define thermistor A0
#define photoResistor A2
const int lightLimit = 220; //Sets limit for light
const int tempLimit = 50; //Sets limit for temperature
 
void setup(){
	Serial.begin(9600); //Start serial monitor for checking values
	pinMode(notifyPin, OUTPUT); //Set the notify pin as output
}

//For reading the light sensor through potentiometer
int brightnessReading(){
  int lightValue = analogRead(photoResistor); //Read value from light sensor
  Serial.print("lightValue: ");    //Displays text label
  Serial.println(lightValue);      //Displays the value of light sensor
  if (lightValue >= lightLimit){   //If light is bright enough
  	return 1;				       //Then, return true
  } else {
  	return 0;				       //Otherwise, false
  }
}

//For reading temperature through thermistor
int temperatureReading(){
  int thermistorValue = analogRead(thermistor); //Read value from thermistor
  int tempC = map(((thermistorValue - 20) * 3.04), 0, 1023, -40, 125); //Converting analog value to temperature
   Serial.print("thermistorValue: "); //Displays text label
  Serial.println(tempC);	          //Displays the value of temperature
  if (tempC >= tempLimit){            //If light is high enough
  	return 1;                         //Then, return true
  } else {
  	return 0;                         //Otherwise, false
  }
}

void loop(){
  int brightnessValue = brightnessReading(); //Getting status of light
  int temperatureValue = temperatureReading(); //Getting status of temperature
  
  if(brightnessValue && temperatureValue){         //If both are above the limit
    Serial.println("Sensor Threshold Working");    //Then display this
    digitalWrite(notifyPin, HIGH);                 //and turn on the led/buzzer
    delay(1000);                                   //Wait for 1 second
    digitalWrite(notifyPin, LOW);			       //and turn off the led/buzzer
    delay(1000);								   //Wait for 1 second
  } else {
  	digitalWrite(notifyPin, LOW);                  //Otherwise, keep it off
  }
}