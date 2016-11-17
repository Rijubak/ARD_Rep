//Switch based Servo(1) Memory
#include<Servo.h>
int i=0,t=0;
const int rcrd_button = 8;
const int play_button = 7;
int rcrd_but_state = 0;
//int rcrd_lastbut_state = 0;
int play_but_state = 0;
int lastbut_state = 0;
int rcrd_led_pin = 6;
int play_led_pin = 5;
const int pot_pin = A0;
int val = 0;
int angle = 0;
int storage[200];
Servo bot_servo;

void setup()
{
 pinMode(rcrd_button,INPUT);
 pinMode(play_button,INPUT);
bot_servo.attach(9);
 Serial.begin(9600); 

}

void loop()
{
 delay(50);
 rcrd_but_state = digitalRead(rcrd_button);
  Serial.println(rcrd_but_state);
 if(rcrd_but_state==1 && lastbut_state==0)
  {while(rcrd_but_state==1 )
   { digitalWrite(rcrd_led_pin,HIGH);
    record();
    rcrd_but_state = digitalRead(rcrd_button);
   delay(80);
   } 
  lastbut_state = 1 ;
  t = i;
  i = 0;
  }
 digitalWrite(rcrd_led_pin,LOW);

 delay(50);
 play_but_state = digitalRead(play_button);
// Serial.println(button_state);
 if(play_but_state==1 )
  { while(play_but_state==1 )
    { digitalWrite(play_led_pin,HIGH);
       play();
     play_but_state = digitalRead(play_button);
     rcrd_but_state = digitalRead(rcrd_button);
    }
  lastbut_state = 0;
  i=0;
  t=0;
  }
 digitalWrite(play_led_pin,LOW);
 
} 

void record()
{
   val = analogRead(pot_pin);
   angle = map(val,0,1023,0,179);
   bot_servo.write(angle);
   storage[i] = angle ;
   delay(25);
   i++;
 
} 

void play()
{
 //Serial.println("Playing");
 if(i<t)
  {
   Serial.println("Playing");
   Serial.print("Storage_");
   Serial.print(i);
   Serial.print(": ");
   Serial.println(storage[i]);
   bot_servo.write(storage[i]);
   delay(25);
   i++;
  Serial.print("i :");
  Serial.println(i);
  }

 if(i==t)
    {i= 0;}
 delay(25);
}




