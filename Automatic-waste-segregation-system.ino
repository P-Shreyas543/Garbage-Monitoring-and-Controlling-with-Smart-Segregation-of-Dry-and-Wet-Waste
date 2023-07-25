#include <Servo.h>
#include <LiquidCrystal.h>
#include <Ultrasonic.h>

LiquidCrystal lcd(8,9,10,11,12,13);//RS,EN,D4,D5,D6,D7
int moisturePin = A0;     // moisture sensor pin
int irSensorPin = 6;     // IR sensor pin
int servoPin = 5;       // servo motor pin
int buzzpin = 7;       // buzzer pin

Ultrasonic ultrasonic1(1, 2);  //1 trigPin, 2 echoPin ultarsonic wet bin
Ultrasonic ultrasonic2(4, 3); //3 trigopin, 4 echopin ultarsoinc dry bin

Servo myServo;

void setup() 
{
  Serial.begin(9600);

  myServo.attach(servoPin, 600, 2300); // (pin, min, max)
  myServo.write(90);
  
  pinMode(moisturePin, INPUT);  //Moisture sensor Analog input
  pinMode(irSensorPin, INPUT); // IR sensor Digital input

  pinMode(buzzpin, OUTPUT); // buzzer output pin
  
  
  lcd.begin(16,2); //initializing LCD
  lcd.setCursor(0,0); 
  lcd.print("Automatic Waste");
  lcd.setCursor(0,1); 
  lcd.print("Segregation sys");
  delay(5000); 
  lcd.clear();

}

void loop() {
  int moistureValue = analogRead(moisturePin);  // read moisture sensor value
  int irValue = digitalRead(irSensorPin);  // read IR sensor value
   
  if (moistureValue < 800 && irValue == LOW ) {  // if the waste is wet
  delay(1000);                // wait for 1 seconds
    lcd.setCursor(0,0); 
    lcd.print(" WET  GARBAGE");       //lcd indicates the garbage is wet
    Serial.println("WET  GARBAGE");
    myServo.write(150);                // rotate servo to one side for wet waste
  delay(1000);                      // wait for 1 seconds
    myServo.write(90);               //Servomoto initial position
    lcd.clear();
} 

  else if (irValue == LOW) {  // if the waste is dry
  delay(1000);                // wait for 1 seconds
    lcd.setCursor(0,0); 
    lcd.print(" DRY  GARBAGE");      //lcd indicates the garbage is dry
    Serial.println("DRY  GARBAGE");
    myServo.write(30);                // rotate servo to the other side for dry waste
    delay(1000);                     // wait for 1 seconds
    myServo.write(90);              //Servomoto initial position
    lcd.clear();
    
  }
  else{                             // if the no waste present
  delay(1000);                      // wait for 1 seconds
    lcd.setCursor(0,0);
    lcd.print(" NO GARBAGE ");       //lcd indicates the no garbage
    Serial.print("NO GARBAGE");
    myServo.write(90);             //Servomoto initial position
  delay(1000);               
    lcd.clear(); 
  }
   
   // Bin level Mesurement Using ultra sonic

  Serial.print("Sensor 01: ");
  Serial.print(ultrasonic1.read()); //serialy prints the distance
  Serial.println("cm");
  
  int ultarsonic1 = ultrasonic1.read();
  if(ultarsonic1 <= 5){// When the the distance below 5cm
    delay(1000);
      digitalWrite(buzzpin, HIGH); // buzzer beeps
      lcd.setCursor(0,0);
      lcd.print("WET BIN FULL");
      Serial.print("WET BIN FULL");
    delay(1000);                
      lcd.clear();
  }
  else{
    digitalWrite(buzzpin, LOW);
  }

  Serial.print("Sensor 02: ");
  Serial.print(ultrasonic2.read()); //serialy prints the distance
  Serial.println("cm");

  int ultarsonic2 = ultrasonic2.read();
  if(ultarsonic2 <= 5){// When the the distance below 5cm
    delay(1000);
      digitalWrite(buzzpin, HIGH); // buzzer beeps
      lcd.setCursor(0,0);
      lcd.print("DRY BIN FULL");
      Serial.print("DRY BIN FULL");
    delay(1000);                
      lcd.clear();
  }
  else{
    digitalWrite(buzzpin, LOW);
  }
}