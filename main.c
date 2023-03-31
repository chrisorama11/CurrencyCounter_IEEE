/*
  blue - $5 
  red - $50
  green - $20  
*/

// Define pins
#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define sensorOut 6
#define PIRPin 7

#define led0 8
#define led1 9
#define led2 10
#define led3 11


// Initialize variables
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

//led array and variables
int ledPin[] = {led0, led1, led2, led3};
short totalCount=0;


void setup() {
  // Setting the sensor pins
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Setting the PIR pins
  pinMode(PIRPin, INPUT);

  //Setting LED pins
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
  // Setting frequency scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  // Begins serial communication
  Serial.begin(9600);
} 

void loop() {
  // Read the RGB values sensed
  int R = redFreq();
  int G = greenFreq();
  int B = blueFreq();

  if(readMotion()&&isRed(R,G,B) == true){
    Serial.println("It's red.");

    displayBinary(1);
    delay(5000);
  }
  else if(readMotion()&&isBlue(R,G,B) == true){
    Serial.println("It's blue.");

    displayBinary(2);
    delay(5000);
  }
  else if(readMotion()&&isGreen(R,G,B) == true){
    Serial.println("It's green.");

    displayBinary(3);
    delay(5000);
  }

}  

int redFreq() {
  // Sensor setting configuration: Red photodiodes ON
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  redFrequency = pulseIn(sensorOut, LOW);

  delay(100);
  
  return redFrequency;
}

int greenFreq() {
  // Sensor setting configuration: Green photodiodes ON
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  greenFrequency = pulseIn(sensorOut, LOW);

  delay(100);
  
  return greenFrequency;
}

int blueFreq() {
  // Sensor setting configuration: Blue photodiodes ON
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  blueFrequency = pulseIn(sensorOut, LOW);

  delay(100);
  
  return blueFrequency;
}

bool isRed(int r, int g, int b){
  if((r<g) && (r<b)){
    return true;
  }
  else{
    return false;
  }
}

bool isGreen(int r, int g, int b){
  if((g<r) && (g<b)){
    return true;
  }
  else{
    return false;
  }
}

bool isBlue(int r, int g, int b){
  if((b<r) && (b<g)){
    return true;
  }
  else{
    return false;
  }
}

int readMotion()
{
  int PIRReading;
  PIRReading = digitalRead(PIRPin);
  if (PIRReading == 1)
  {
      //Serial.println("Motion detected!");
  }
  else
  {
      //Serial.println("Motion finished!");
  }
  return PIRReading;
}

void displayBinary(short numToShow)
{
  totalCount+=numToShow;
  if(totalCount>15){
    totalCount=numToShow;
  }

  for (int i=0;i<4;i++)
  {
    if (bitRead(totalCount, i)== 1)
    {
      digitalWrite(ledPin[i], HIGH);
    }
    else
    {
      digitalWrite(ledPin[i], LOW);
    }
  }

}