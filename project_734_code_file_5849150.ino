const int pinIr2p = 7;
const int pinIr50p = 9;
const int pinIr10p = 2;
const int pinIr100p = 4;
const int pinIr20p = 5;
const int pinIr1p = 6;
const int pinIr5p = 8;
const int pinIr200p = 12;


int IRvalue2p = 0;
int IRvalue50p = 0;
int IRvalue10p = 0;
int IRvalue100p = 0;
int IRvalue20p = 0;
int IRvalue1p = 0;
int IRvalue5p = 0;
int IRvalue200p = 0;

const int pinIrStart = 6;
int pinMotor = 3;
int IRvalueStart = 0;

int coinCount = 0;
int MoneyWorth = 0;
String MessageToPrint = "p";


/* Display */
/* Include the HCMAX7219 and SPI library */
#include <LiquidCrystal_I2C.h> 
/* Set the LOAD (CS) digital pin number*/
#define LOAD 10
/* Create somewhere to store the message*/
String message = "BEEF";




void setup()
{
  Serial.begin(9600);
  pinMode(pinIr2p,INPUT);
  pinMode(pinIrStart,INPUT);
  pinMode(pinMotor,OUTPUT);


  
  //Welcome message
  byte Loopcounter;
  byte Position;

}

void loop()
{
  IRvalue2p = digitalRead(pinIr2p);
  IRvalue50p = digitalRead(pinIr50p);
  IRvalue10p = digitalRead(pinIr10p);
  IRvalue100p = digitalRead(pinIr100p);
  IRvalue20p = digitalRead(pinIr20p);
  IRvalue1p = digitalRead(pinIr1p);
  IRvalue5p = digitalRead(pinIr5p);
  IRvalue200p = digitalRead(pinIr200p);
  IRvalueStart = digitalRead(pinIrStart);
  


 //  if (IRvalueStart == 0) {
 //   Serial.println("Coin detected. Starting motor...");
 //   digitalWrite(pinMotor, HIGH);
 //   delay(200);
 //  }
   
   if (IRvalue2p == 0) {
    Serial.println("It was a 2p coin that was detected");
    coinDetected();
    MoneyWorth = MoneyWorth + 1;
    //displayAmountSerial();
    //isplayAmount();
    delay(200);
   }

   if (IRvalue50p == 0) {
    Serial.println("It was a 50p coin that was detected");
    coinDetected();
    MoneyWorth = MoneyWorth + 50;
    //displayAmountSerial();
    //displayAmount();
    delay(200);
   }

   if (IRvalue10p == 0) {
    Serial.println("It was a 10p coin that was detected");
    coinDetected();
    MoneyWorth = MoneyWorth + 10;
    //displayAmountSerial();
    //displayAmount();
    delay(200);
   }

   if (IRvalue100p == 0) {
    Serial.println("It was a £1 coin that was detected");
    coinDetected();
    MoneyWorth = MoneyWorth + 100;
    //displayAmountSerial();
    //displayAmount();
    delay(200);
   }

   if (IRvalue20p == 0) {
    Serial.println("It was a 20p coin that was detected");
    coinDetected();
    MoneyWorth = MoneyWorth + 20;
    //displayAmountSerial();
    //displayAmount();
    delay(200);
   }

   if (IRvalue1p == 0) {
    Serial.println("It was a 1p coin that was detected");
    coinDetected();
    MoneyWorth = MoneyWorth + 1;
    //displayAmountSerial();
    //displayAmount();
    delay(200);
   }

   if (IRvalue5p == 0) {
    Serial.println("It was a 5p coin that was detected");
    coinDetected();
    MoneyWorth = MoneyWorth + 5;
    //displayAmountSerial();
    //displayAmount();
    delay(200);
   }
   
   if (IRvalue200p == 0) {
    Serial.println("It was a £2 coin that was detected");
    coinDetected();
    MoneyWorth = MoneyWorth + 200;
    //displayAmountSerial();
    //displayAmount();
    delay(200);
   }

}

//void displayAmount() {
  /* Clear the output buffer of the screen */
    lcd.Clear();
    /* Write some text and output it*/
    if (MoneyWorth > 9999){
      lcd.Clear();
      lcd.setCursor(0,0);
      lcd.print(MoneyWorth,6);
    }
    else if (MoneyWorth > 999){
      lcd.Clear();
      lcd.setCursor(0,0);
      lcd.print(MoneyWorth,5);
    }
    else if (MoneyWorth > 99){
      lcd.Clear();
      lcd.setCursor(0,0);      
      lcd.print(MoneyWorth,4);
    }
    else if (MoneyWorth > 9){
      lcd.Clear();
      lcd.setCursor(0,0);
      lcd.print(MoneyWorth,3);
    }
    else{
      lcd.Clear();
      lcd.setCursor(0,0);
      lcd.print(MoneyWorth,2); 
    }
    
    lcd.Clear();
    lcd.setCursor(0,0);
    lcd.print("p",1); //always add the 'p' sign
    lcd.Refresh();
}

//void displayAmountSerial(){
  Serial.print("So that's ");
    Serial.print(coinCount);
    Serial.print(" coins now and the total value counted is ");
    Serial.print(MoneyWorth);
    Serial.println("p");
    Serial.println();
}

void coinDetected() {
    coinCount ++;
    digitalWrite(pinMotor, LOW);
}
