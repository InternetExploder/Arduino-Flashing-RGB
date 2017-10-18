int rLedPin = 11;      // LED connected to digital pin 11
int gLedPin = 10;      // LED connected to digital pin 10
int bLedPin = 9;      // LED connected to digital pin 9
int analogPin = 0;   // potentiometer connected to analog pin 0
float scaleFactor = 1535.0/1023.0; 

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
  val = int(scaleFactor*float(analogRead(analogPin)));
  if (val < 256){
    rVal = 255;
    gVal = 0;
    bVal = val;
    } else if (val < 512){
    rVal = 255 - (val - 255);
    gVal = 0;
    bVal = 255;
    } else if (val < 768){
    rVal = 0;
    gVal = val - 511;
    bVal = 255;
    } else if (val < 1024){
    rVal = 0;
    gVal = 255;
    bVal = 255 - (val - 767);
    } else if (val < 1280){
    rVal = val - 1023;
    gVal = 255;
    bVal = 0;
    } else if (val < 1536){
    rVal = 255;
    gVal = 255 - (val - 1279);
    bVal = 0;
    }
  
  
  //val = analogRead(analogPin);   // read the input pin  250,235,215
  analogWrite(rLedPin, rVal);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  analogWrite(gLedPin, gVal);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  analogWrite(bLedPin, bVal);  // analogRead values go from 0 to 1023, analogWrite values from 0 to 255
  delay(5);
}
