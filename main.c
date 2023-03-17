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

// total balance (global variable) - its value is reassigned in the updateTotalBalance function 
int totalBalance = 0;

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
  
  // initialize pin for motion sensor --DONE


//Set direction for colourS0-3 and OUT ------DONE

//Set the output frequency (PWM) through digitalWrite

}


void loop()

{
//read output variables for IR sensor and LEDs (hold frequency for each LED)  
    redReading = fRed();
    greenReading = fGreen();
    blueReading = fBlue();


//fetch PIR sensor reading
    motionReading = readMotion();

    if(motionReading ==1){
        //display RGB freq using LED 
        outputLedColour(redReading, greenReading, blueReading);
    }
//print frequency of each LED before adding new currency 

//compare colour sensor's output frequency with reference (to deduct amount from balance) 
  //condition 1 
    if (){
        updateTotalBalance(5);
    } 
  //condition 2 
    else if (){
        updateTotalBalance(10);
    }
  //condition 3 
    else if (){
        updateTotalBalance(15);
    }
  //condition 4 
    else if (){
        updateTotalBalance(20);
    }
//show wallet balance array of LEDS

    showBalance(totalBalance);
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
  if (PIRReading == 1)
  {
      PIRState = 1;
  }
  else
  {
      PIRState = 0;
  }
  return PIRState;
}

void updateTotalBalance(int current)
{
    totalBalance += current;
}

void showBalance(int balance){
        int number_of_leds = n;

    // in this array the first element (index 0) is the least significant digit
    // so the binary number would be backwards
    int balance_in_binary[n]; // assuming there are n LEDs in the LED array
    int index = 0;


    balance %= math.pow(2,n);     Since there are only n LEDs, the largest binary number you could 
               // represent with n LEDs would be (2^n)-1

    while (balance){
        balance_in_binary[index] = balance%2;
        balance /= 2;
        index++;
    }
}
