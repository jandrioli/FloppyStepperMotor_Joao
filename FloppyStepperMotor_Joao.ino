
/*
  3.5" Floppy Control

  Randomly move head around
  
  modified 9 Feb 2015
  by Norman Davie
 */


        // driveSelect            // Pin 12 needs to be grounded to Pin 1
        
const byte driveMotorEnable = 10; // Pin 14 on floppy connector
const byte directionPin     = 8;  // Pin 18 on floppy connector
const byte stepPin          = 6;  // Pin 20 on floppy connector

const int delayStep   = 1000;
const int delaySlowMs = 100;

void setup() 
{
  Serial.begin(9600);

  pinMode(driveMotorEnable, OUTPUT);
  pinMode(directionPin,     OUTPUT);
  pinMode(stepPin,          OUTPUT);
}


void SlowStep(unsigned long steps) 
{
  //Serial.print("Steps:");
  //Serial.println(steps);
  
  for (unsigned long i=0; i < steps; i++) 
  {
    digitalWrite(stepPin, LOW);
    delayMicroseconds(delaySlowMs);
    
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(delayStep);
  }
  
  // Set the pin low before we end
  digitalWrite(stepPin, LOW);
}



void loop() 
{


  digitalWrite(driveMotorEnable, HIGH);
  //Serial.println("driveMotorEnable HIGH");
  delay(1);   
  digitalWrite(directionPin, HIGH);  // clockwise
  // Serial.println("direction Clockwise HIGH");
  delay(1);  
  SlowStep(random(25, 200));            // perform 200 steps
  delay(50);
  
  
  
  digitalWrite(directionPin, LOW);   // anti-clockwise
  //Serial.println("direction Anti-Clockwise LOW");
  delay(1);   

  SlowStep(random(25, 200) );            // perform 100 steps
  delay(50);

}

