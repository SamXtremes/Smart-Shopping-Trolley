#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int count = 0;                                          // count = 0
//int a;
int p1=0,p2=0,p3=0,p4=0;
int c1=0,c2=0,c3=0,c4=0;
char input[12];                                         // character array of size 12
boolean flag = 0;                                       // flag =0
double total = 0;
int count_prod = 0;


int pr1 = 0 ;
int pr2 = 0 ;
int pr3 = 0 ;
int pr4 = 0 ;
void setup()
{ //Serial Initiation
   Serial.begin(9600);    // begin serial port with baud rate 9600bps
  pinMode (19, OUTPUT);
//LCD initiation
 
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("     SMART     ");
  delay (2000);
  lcd.setCursor(0, 1);
  lcd.print("  SHOPPING CART  ");
  delay (2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("    WELCOME    ");
 
}

void loop()
{
  if(Serial.available())
   {
      count = 0;
      while(Serial.available() && count < 12)          // Read 12 characters and store them in input array
      {
         input[count] = Serial.read();
         count++;
         delay(5);
      }
      Serial.print(input);

      if ((strncmp(input, "09001FB28420", 12) == 0)&& pr1 == 0 )
      {
        lcd.setCursor(0, 0);
        lcd.print("Maggie Added       ");
        lcd.setCursor(0, 1);
        lcd.print("Price(Rs):12.00      ");
        digitalWrite(4,HIGH);
        digitalWrite(5,LOW);
        digitalWrite(6,HIGH);
        delay(1000);
        total = total + 12.00;
        count_prod++;
        pr1 = 1 ;
//        tone(buzzer,392);
//        delay(200);
//        noTone(buzzer);

        digitalWrite(19,HIGH);
        delay(1000);
        digitalWrite(19,LOW);
        delay(1000);
        digitalWrite(4,LOW);
        digitalWrite(5,HIGH);
        digitalWrite(6,LOW);  
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Total : ");
        lcd.setCursor(0, 1);
        lcd.print(total);      
      }
      else if ((strncmp(input, "09001FB28420", 12) == 0)&& pr1 == 1)
      {
       
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Maggie Removed!!!     ");
        digitalWrite(4,HIGH);
        digitalWrite(5,LOW);
        digitalWrite(6,HIGH);
        delay(1000);
        total = total - 12.00;
        pr1 = 0 ;
//        tone(buzzer,392);
//        delay(200);
//        noTone(buzzer);
        digitalWrite(13,HIGH);
        delay(1000);
        digitalWrite(13,LOW);
        delay(1000);
        lcd.clear();
        digitalWrite(4,LOW);
        digitalWrite(5,HIGH);
        digitalWrite(6,LOW);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Total : ");
        lcd.setCursor(0, 1);
        lcd.print(total);
       
//        else
//        {
//        lcd.clear();
//        lcd.setCursor(0, 0);
//        lcd.print("Not in cart!!!        ");
//        digitalWrite(4,HIGH);
//        digitalWrite(5,LOW);
//        digitalWrite(6,HIGH);
//        delay(2000);
//        digitalWrite(4,LOW);
//        digitalWrite(5,HIGH);
//        digitalWrite(6,LOW);
//        lcd.clear();
//        }
      }
/////////////////////////////
      if ((strncmp(input, "09001F7A2F43", 12) == 0)&& pr2 == 0 )
      {
        lcd.setCursor(0, 0);
        lcd.print("PEN Packet Added");
        lcd.setCursor(0, 1);
        lcd.print("Price(Rs):25.00 ");
        digitalWrite(4,HIGH);
        digitalWrite(5,LOW);
        digitalWrite(6,HIGH);
        delay(1000);
        total = total + 25.00;
        count_prod++;
        pr2 = 1 ;
//        tone(buzzer,392);
//        delay(200);
//        noTone(buzzer);
        digitalWrite(13,HIGH);
        delay(1000);
        digitalWrite(13,LOW);
        delay(1000);
        digitalWrite(4,LOW);
        digitalWrite(5,HIGH);
        digitalWrite(6,LOW);  
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Total : ");
        lcd.setCursor(0, 1);
        lcd.print(total);      
      }
      else if ((strncmp(input, "09001F7A2F43", 12) == 0) && pr2 == 1)
      {
       
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("PEN Packet  Removed!!!     ");
        digitalWrite(4,HIGH);
        digitalWrite(5,LOW);
        digitalWrite(6,HIGH);
        delay(1000);
        total = total - 25.00;
        pr2 = 0 ;
//        tone(buzzer,392);
//        delay(200);
//        noTone(buzzer);
        digitalWrite(13,HIGH);
        delay(1000);
        digitalWrite(13,LOW);
        delay(1000);
        lcd.clear();
        digitalWrite(4,LOW);
        digitalWrite(5,HIGH);
        digitalWrite(6,LOW);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Total : ");
        lcd.setCursor(0, 1);
        lcd.print(total);
       
//        else
//        {
//        lcd.clear();
//        lcd.setCursor(0, 0);
//        lcd.print("Not in cart!!!        ");
//        digitalWrite(4,HIGH);
//        digitalWrite(5,LOW);
//        digitalWrite(6,HIGH);
//        delay(2000);
//        digitalWrite(4,LOW);
//        digitalWrite(5,HIGH);
//        digitalWrite(6,LOW);
//        lcd.clear();
//        }

      }
////////////////////////////////////      
      if ((strncmp(input, "09001E54F6B5", 12) == 0)&& pr3 == 0 )
      {
        lcd.setCursor(0, 0);
        lcd.print("Biscuit Added       ");
        lcd.setCursor(0, 1);
        lcd.print("Price(Rs): 10.00      ");
        digitalWrite(4,HIGH);
        digitalWrite(5,LOW);
        digitalWrite(6,HIGH);
        delay(1000);
        total = total + 10.00;
        count_prod++;
        pr3 = 1 ;
//        tone(buzzer,392);
//        delay(200);
//        noTone(buzzer);
        digitalWrite(13,HIGH);
        delay(1000);
        digitalWrite(13,LOW);
        delay(1000);
        digitalWrite(4,LOW);
        digitalWrite(5,HIGH);
        digitalWrite(6,LOW);  
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Total : ");
        lcd.setCursor(0, 1);
        lcd.print(total);      
      }
      else if ((strncmp(input, "09001E54F6B5", 12) == 0) && pr3 == 1)
      {
       
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Biscuit Removed !!!     ");
        digitalWrite(4,HIGH);
        digitalWrite(5,LOW);
        digitalWrite(6,HIGH);
        delay(1000);
        total = total - 10.00;
        pr3 = 0 ;
//        tone(buzzer,392);
//        delay(200);
//        noTone(buzzer);
        digitalWrite(13,HIGH);
        delay(1000);
        digitalWrite(13,LOW);
        delay(1000);
        lcd.clear();
        digitalWrite(4,LOW);
        digitalWrite(5,HIGH);
        digitalWrite(6,LOW);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Total : ");
        lcd.setCursor(0, 1);
        lcd.print(total);
      }
///////////////////////////////////////    
      if ((strncmp(input, "09001F7C452F", 12) == 0)&& pr4 == 0 )
      {
        lcd.setCursor(0, 0);
        lcd.print("Soap Added       ");
        lcd.setCursor(0, 1);
        lcd.print("Price(Rs): 20.00      ");
        digitalWrite(4,HIGH);
        digitalWrite(5,LOW);
        digitalWrite(6,HIGH);
        delay(1000);
        total = total + 20.00;
        count_prod++;
        pr4 = 1 ;
//        tone(buzzer,392);
//        delay(200);
//        noTone(buzzer);
        digitalWrite(13,HIGH);
        delay(1000);
        digitalWrite(13,LOW);
        delay(1000);
        digitalWrite(4,LOW);
        digitalWrite(5,HIGH);
        digitalWrite(6,LOW);  
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Total : ");
        lcd.setCursor(0, 1);
        lcd.print(total);      
      }
      else if ((strncmp(input, "09001F7C452F", 12) == 0) && pr4 == 1)
      {
       
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Soap Removed !!!     ");
        digitalWrite(4,HIGH);
        digitalWrite(5,LOW);
        digitalWrite(6,HIGH);
        delay(1000);
        total = total - 20.00;
        pr4 = 0 ;
//        tone(buzzer,392);
//        delay(200);
//        noTone(buzzer);
        digitalWrite(13,HIGH);
        delay(1000);
        digitalWrite(13,LOW);
        delay(1000);
        lcd.clear();
        digitalWrite(4,LOW);
        digitalWrite(5,HIGH);
        digitalWrite(6,LOW);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Total : ");
        lcd.setCursor(0, 1);
        lcd.print(total);
      }
   }
}
