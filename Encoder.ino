#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8); // lcd configure pin

int sensorInput = 5; // digital sensor input from pin 5
long i = 0;
int M1=HIGH,M2=LOW; // control motor
int value; // store digital sensor input value



void setup() {
  // put your setup code here, to run once:
  attachInterrupt(0,turn,RISING); // interrupt 0
  attachInterrupt(1,sub,RISING); // interrupt 1

  pinMode(7,OUTPUT); // motor driving
  pinMode(6,OUTPUT); // motor driving 
  pinMode(sensorInput,INPUT); // pin 5 input
  
//lcd display
  lcd.begin(16,2);
  lcd.print("Arduino Blink");
  lcd.setCursor(0,1);
  lcd.print("ENCODER");
  delay(500);
  lcd.clear();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  lcd.setCursor(0,0);
  lcd.print("ENCODER");
  lcd.setCursor(0,1);
  lcd.print(i);
  lcd.print("         ");

  digitalWrite(7,M1);
  digitalWrite(6,M2);
}

void turn(){ // interruot 0 occured ( pin 2)

  M1=!M1;
  M2=!M2;
}

void sub(){ //interrupt 1 occured ( pin 3 )

  value = digitalRead(sensorInput);
  if(value==1){ // button not pressed
    i++;
  }
  else // button pressed
  {
    i--;
  }
}
