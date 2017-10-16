int rLedPin = 11;      // LED connected to digital pin 9
int gLedPin = 10;      // LED connected to digital pin 9
int bLedPin = 9;      // LED connected to digital pin 9
int analogPin = 3;   // potentiometer connected to analog pin 3

int rVal = 0;         // variable to store the read value
int gVal = 0;         // variable to store the read value
int bVal = 0;         // variable to store the read value
int val = 0;

void setup()
{
  pinMode(rLedPin, OUTPUT);   // sets the pin as output
  pinMode(gLedPin, OUTPUT);   // sets the pin as output
  pinMode(bLedPin, OUTPUT);   // sets the pin as output
}

void loop()
{
  val ++;
  if (val < 256){
    rVal = val;
    } else if (val < 511){
    rVal = 255;
    gVal = val - 255;
    } else if (val < 511){
    rVal = 255;
    gVal = val - 255;
    }
  
  
  //val = analogRead(analogPin);   // read the input pin  250,235,215
  analogWrite(rLedPin, rVal);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  analogWrite(gLedPin, gVal);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  analogWrite(bLedPin, bVal);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  delay(1);
}
