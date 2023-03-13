//include libraries 
#include <LiquidCrystal.h>

//declare component pin variables 
const int redLedPin = 9;
const int greenLedPin = 10;
const int blueLedPin = 11;
const int colourS0 = 2;
const int colourS1 = 3;
const int colourS2 = 5;
const int colourS3 = 12;
const int colourSensorOut = 13;
const int PIRPin = 1;

//declare other code variables
int redReading = 0;
int greenReading = 0;
int blueReading = 0;
int motionReading = LOW;

void setup() { 
  Serial.begin(9600); //Baud rate 9600 
  // pins for RGB LED
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  // initialize pins for colour sensor
  pinMode(colourS0, OUTPUT); 
  pinMode(colourS1, OUTPUT);
  pinMode(colourS2, OUTPUT);
  pinMode(colourS3, OUTPUT);
  digitalWrite(colourS0,HIGH);
  digitalWrite(colourS1,LOW);
  pinMode(colourSensorOut, INPUT);
  
  // initialize pin for motion sensor


//Welcome message 

//delay 2s before clearing 

//clear LCD display 

//Set direction for colourS0-3 and OUT 

//Set the output frequency (PWM) through digitalWrite

}


void loop()

{
//read output variables for IR sensor and LEDs (hold frequency for each LED)  
    redReading = fRed();
    greenReading = fGreen();
    blueReading = fBlue();

//display RGB freq using LED 
    outputLedColour(redReading, greenReading, blueReading);


//fetch PIR sensor reading
    motionReading = readMotion();
//print frequency of each LED before adding new currency 

//compare colour sensor's output frequency with reference (to deduct amount from balance) 
  //condition 1 

  //condition 2 
  
  //condition 3 

  //condition 4 

//show wallet balance on LCD display 

//delay 1s 

}

//function outputing colour freq of red in currency 
int fRed()
{
//code content 
  digitalWrite(colourS2,LOW);
  digitalWrite(colourS3,LOW);
  int redFreq;
  redFreq = pulseIn(colourSensorOut, LOW);
  return redFreq;
}

//function outputing colour freq of blue in currency 
int fBlue()
{
  digitalWrite(colourS2,LOW);
  digitalWrite(colourS3,HIGH);
  int blueFreq;
  blueFreq = pulseIn(colourSensorOut, LOW);
  return blueFreq;
}

//function outputing colour freq of green in currency 
int fGreen()
{
//code content 
  digitalWrite(colourS2,HIGH);
  digitalWrite(colourS3,HIGH);
  int greenFreq;
  greenFreq = pulseIn(colourSensorOut, LOW);
  return greenFreq;
} 

//function to display colour sensor values on an RBG LED
void outputLedColour(r, g, b)
{
  analogWrite(redLedPin, r);
  analogWrite(greenLedPin, g);
  analogWrite(blueLedPin, b);
} 

void readMotion()
{
  int PIRReading;
  int PIRState;
  PIRReading = digitalRead(PIRPin);
  if (PIRReading == HIGH)
  {
      PIRState = HIGH;
  }
  else
  {
      PIRState = LOW;
  }
  return PIRState;
}
