//Switch based Servo(4) Memory

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
const int pot_pin_1 = A0;
const int pot_pin_2 = A1;
const int pot_pin_3 = A2;
const int pot_pin_4 = A3;
int val_1 = 0;
int angle_1 = 0;
int val_2 = 0;
int angle_2 = 0;
int val_3 = 0;
int angle_3 = 0;
int val_4 = 0;
int angle_4 = 0;
int storage_1[150];
Servo bot_servo_1;

int storage_2[150];
Servo bot_servo_2;

int storage_3[150];
Servo bot_servo_3; 

int storage_4[150];
Servo bot_servo_4;

void setup()
{
 pinMode(rcrd_button,INPUT);
 pinMode(play_button,INPUT);
bot_servo_1.attach(9);
 bot_servo_2.attach(10);
 bot_servo_3.attach(11);
 bot_servo_4.attach(3);
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
   val_1 = analogRead(pot_pin_1);
   angle_1 = map(val_1,0,1023,0,179);
   bot_servo_1.write(angle_1);
   storage_1[i] = angle_1 ;

    val_2 = analogRead(pot_pin_2);
   angle_2 = map(val_2,0,1023,0,179);
    bot_servo_2.write(angle_2);
   storage_2[i] = angle_2 ;
   
    val_3 = analogRead(pot_pin_3);
   angle_3 = map(val_2,0,1023,0,179);
    bot_servo_3.write(angle_3);
   storage_3[i] = angle_3 ;

    val_4 = analogRead(pot_pin_4);
   angle_4 = map(val_4,0,1023,0,179);
    bot_servo_4.write(angle_4);
   storage_4[i] = angle_4 ;
   
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
   Serial.println(storage_1[i]);
   bot_servo_1.write(storage_1[i]);
   bot_servo_2.write(storage_2[i]);
   bot_servo_3.write(storage_3[i]);
   bot_servo_4.write(storage_4[i]);
   delay(25);
   i++;
  Serial.print("i :");
  Serial.println(i);
  }

 if(i==t)
    {i= 0;}
 delay(25);
}




