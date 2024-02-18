//YWROBOT

//Compatible with the Arduino IDE 1.0

//Library version:1.1



#include <Wire.h>

#include <LiquidCrystal_I2C.h>



LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display



int counter = 0;



byte LT[8] =

{



  B00111,

  B01111,

  B11111,

  B11111,

  B11111,

  B11111,

  B11111,

  B11111

};

byte UB[8] =

{

  B11111,

  B11111,

  B11111,

  B00000,

  B00000,

  B00000,

  B00000,

  B00000

};

byte RT[8] =

{



  B11100,

  B11110,

  B11111,

  B11111,

  B11111,

  B11111,

  B11111,

  B11111

};

byte LL[8] =

{





  B11111,

  B11111,

  B11111,

  B11111,

  B11111,

  B11111,

  B01111,

  B00111

};

byte LB[8] =

{

  B00000,

  B00000,

  B00000,

  B00000,

  B00000,

  B11111,

  B11111,

  B11111

};

byte LR[8] =

{





  B11111,

  B11111,

  B11111,

  B11111,

  B11111,

  B11111,

  B11110,

  B11100

};

byte MB[8] =

{

  B11111,

  B11111,

  B11111,

  B00000,

  B00000,

  B00000,

  B11111,

  B11111

};

byte block[8] =

{

  B11111,

  B11111,

  B11111,

  B11111,

  B11111,

  B11111,

  B11111,

  B11111

};



void setup()

{

  lcd.init();                      // initialize the lcd



  lcd.createChar(0,LT);

  lcd.createChar(1,UB);

  lcd.createChar(2,RT);

  lcd.createChar(3,LL);

  lcd.createChar(4,LB);

  lcd.createChar(5,LR);

  lcd.createChar(6,MB);

  lcd.createChar(7,block);

 

  // Print a message to the LCD.

  lcd.backlight();



   int temp = 10;

  lcd.clear();

  printDigits(0,0);

  printDigits(1,4);

  printDigits(2,8);

  printDigits(3,12);

 

}



void printNumber(int val){

 

     int col=0;   

     printDigits(val/10,col);

     printDigits(val%10,col+4);

}



void loop()

{

   lcd.clear();

   printNumber( counter );

   counter++;

   if( counter >= 100) counter= 0;

 

   delay(500);

}



void custom0(int x){



  lcd.setCursor(x,0);

  lcd.write(0); 

  lcd.write(1); 

  lcd.write(2);

  lcd.setCursor(x, 1);

  lcd.write(3); 

  lcd.write(4); 

  lcd.write(5);

}



void custom1(int x){

  lcd.setCursor(x,0);

  lcd.write(1);

  lcd.write(2);

  lcd.print(" ");

  lcd.setCursor(x,1);

  lcd.write(4);

  lcd.write(7);

  lcd.write(4);

}



void custom2(int x){

  lcd.setCursor(x,0);

  lcd.write(6);

  lcd.write(6);

  lcd.write(2);

  lcd.setCursor(x, 1);

  lcd.write(3);

  lcd.write(4);

  lcd.write(4);

}



void custom3(int x){

  lcd.setCursor(x,0);

  lcd.write(6);

  lcd.write(6);

  lcd.write(2);

  lcd.setCursor(x, 1);

  lcd.write(4);

  lcd.write(4);

  lcd.write(5);

}



void custom4(int x){

  lcd.setCursor(x,0);

  lcd.write(3);

  lcd.write(4);

  lcd.write(7);

  lcd.setCursor(x, 1);

  lcd.print(" ");

  lcd.print(" ");

  lcd.write(7);

}



void custom5(int x){

  lcd.setCursor(x,0);

  lcd.write(3);

  lcd.write(6);

  lcd.write(6);

  lcd.setCursor(x, 1);

  lcd.write(4);

  lcd.write(4);

  lcd.write(5);

}



void custom6(int x){

  lcd.setCursor(x,0);

  lcd.write(0);

  lcd.write(6);

  lcd.write(6);

  lcd.setCursor(x, 1);

  lcd.write(3);

  lcd.write(4);

  lcd.write(5);

}



void custom7(int x){

  lcd.setCursor(x,0);

  lcd.write(1);

  lcd.write(1);

  lcd.write(2);

  lcd.setCursor(x, 1);

  lcd.print(" ");

  lcd.print(" ");

  lcd.write(7);

}



void custom8(int x){

  lcd.setCursor(x,0);

  lcd.write(0);

  lcd.write(6);

  lcd.write(2);

  lcd.setCursor(x, 1);

  lcd.write(3);

  lcd.write(4);

  lcd.write(5);

}



void custom9(int x){

 

  lcd.setCursor(x,0);

  lcd.write(0);

  lcd.write(6);

  lcd.write(2);

  lcd.setCursor(x, 1);

  lcd.print(" ");

  lcd.print(" ");

  lcd.write(7);



}

void printDigits(int digits, int x){

  // utility function for digital clock display: prints preceding colon and leading 0



  switch (digits) {

  case 0: 

    custom0(x);

    break;

  case 1: 

    custom1(x);

    break;

  case 2: 

    custom2(x);

    break;

  case 3: 

    custom3(x);

    break;

  case 4: 

    custom4(x);

    break;

  case 5: 

    custom5(x);

    break;

  case 6: 

    custom6(x);

    break;

  case 7: 

    custom7(x);

    break;

  case 8: 

    custom8(x);

    break;

  case 9: 

    custom9(x);

    break;



  }



}
