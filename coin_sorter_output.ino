/*INPUT*/
//紅外線感應腳位設置D4,D7,D8,D10
const int pinNTD1 = 4;
const int pinNTD5 = 7;
const int pinNTD10 = 8;
const int pinNTD50 = 10;

//按鈕腳位D14,D15,D16,D17,D12
const int pinbuttonNTD1 = 14;
const int pinbuttonNTD5 = 15;
const int pinbuttonNTD10 = 16;
const int pinbuttonNTD50 = 17;

const int pinbuttondisplaychange = 12;

//開關腳位D11
const int pinswitch = 11;

/*OUTPUT*/
//馬達腳位D3,D5,D6,D9
const int pinmotorNTD1 = 3;
const int pinmotorNTD5 = 5;
const int pinmotorNTD10 = 6;
const int pinmotorNTD50 = 9;


//LCD I2C1602腳位設置 A4,A5
const int pinLCD3 = 4;
const int pinLCD4 = 5;

/*變數設置*/
//紅外線變數
int statesensorNTD1 = 0;
int statesensorNTD5 = 0;
int statesensorNTD10 = 0;
int statesensorNTD50 = 0;

//按鈕變數
int statebuttonNTD1 = 0;
int statebuttonNTD5 = 0;
int statebuttonNTD10 = 0;
int statebuttonNTD50 = 0;
int statebuttondisplaychange = 0;

//按鈕是否放開
boolean buttonUpNTD1 = true;
boolean buttonUpNTD5 = true;
boolean buttonUpNTD10 = true;
boolean buttonUpNTD50 = true;

//開關變數
int stateswitch = 0;

//各硬幣總價值
int valueNTD1 = 0;
int valueNTD5 = 0;
int valueNTD10 = 0;
int valueNTD50 = 0;

//各硬幣總數
int quantityNTD1 = 0;
int quantityNTD5 = 0;
int quantityNTD10 = 0;
int quantityNTD50 = 0;

//錢總量
int MoneyWorth = 0;




/* Display */
/* Include the HCMAX7219 and SPI library */
#include <LiquidCrystal_I2C.h> 
/* Set the LOAD (CS) digital pin number*/
#define LOAD 10
/* Create somewhere to store the message*/
String message = "BEEF";
// LCD I2C位址，默認為0x27或0x3F，依據背板的晶片不同而有差異，16、2為LCD顯示器大小。
LiquidCrystal_I2C lcd(0x27, 16, 2); 




void setup()
{
  Serial.begin(9600);
  pinMode(pinNTD1,INPUT);
  pinMode(pinNTD5,INPUT);
  pinMode(pinNTD10,INPUT);
  pinMode(pinNTD50,INPUT);
  
  pinMode(pinbuttonNTD1,INPUT_PULLUP);
  pinMode(pinbuttonNTD5,INPUT_PULLUP);
  pinMode(pinbuttonNTD10,INPUT_PULLUP);
  pinMode(pinbuttonNTD50,INPUT_PULLUP);
  pinMode(pinbuttondisplaychange,INPUT_PULLUP);
  
  pinMode(pinswitch,INPUT_PULLUP);
  
  
  pinMode(pinmotorNTD1,OUTPUT);
  pinMode(pinmotorNTD5,OUTPUT);
  pinMode(pinmotorNTD10,OUTPUT);
  pinMode(pinmotorNTD50,OUTPUT);

  

}

void loop()
{
  //button偵測
  statebuttondisplaychange = digitalRead(pinbuttondisplaychange);
  statebuttonNTD1 = digitalRead(pinbuttonNTD1);
  statebuttonNTD5 = digitalRead(pinbuttonNTD5);
  statebuttonNTD10 = digitalRead(pinbuttonNTD10);
  statebuttonNTD50 = digitalRead(pinbuttonNTD50);
  


  if(statebuttonNTD1 != HIGH && buttonUpNTD1 == true) {
    servoNTD1.write(180);
    delay(1000);
    servoNTD1.write(0);
    digitalWrite(13, state);
    buttonUpNTD1 = false;
  }
  else if(statebuttonNTD1 == HIGH && buttonUpNTD1 != true) {
    buttonUpNTD1 = true;
  }
  delay(10);
  //5
  if(statebuttonNTD1 != HIGH && buttonUpNTD1 == true) {
    servoNTD1.write(180);
    delay(1000);
    servoNTD1.write(0);
    digitalWrite(13, state);
    buttonUpNTD1 = false;
  }
  else if(statebuttonNTD1 == HIGH && buttonUpNTD1 != true) {
    buttonUpNTD1 = true;
  }
  delay(10);
  //10
  if(statebuttonNTD1 != HIGH && buttonUpNTD1 == true) {
    servoNTD1.write(180);
    delay(1000);
    servoNTD1.write(0);
    digitalWrite(13, state);
    buttonUpNTD1 = false;
  }
  else if(statebuttonNTD1 == HIGH && buttonUpNTD1 != true) {
    buttonUpNTD1 = true;
  }
  delay(10);
  //50
  if(statebuttonNTD1 != HIGH && buttonUpNTD1 == true) {
    servoNTD1.write(180);
    delay(1000);
    servoNTD1.write(0);
    digitalWrite(13, state);
    buttonUpNTD1 = false;
  }
  else if(statebuttonNTD1 == HIGH && buttonUpNTD1 != true) {
    buttonUpNTD1 = true;
  }
  delay(10);
  
}

