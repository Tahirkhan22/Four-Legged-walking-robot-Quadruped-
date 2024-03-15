
#include "pitches.h"

#include <Servo.h>   

Servo servo[4][3];

//define servos' ports
const int servo_pin[4][3] =  { {2, 3, 4}, {5, 6, 7}, {8, 9, 10}, {11, 12, 13} };

void setup()
{
  Serial.begin(9600);
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);
  //initialize all servos
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      servo[i][j].attach(servo_pin[i][j]);
      delay(500);
    }
  }
}

void loop()
{
  Serial.println("1 sit");
  Serial.println("2 stand"); 
  Serial.println("3 wavehand"); 
  Serial.println("4 move forward"); 
  Serial.println("5 turn left"); 
  Serial.println("6 turn right");
buzzer();
 while(Serial.available()==0){
   led();
 }
   int c=Serial.parseInt();
   if(c==1){buzzer(); sit();
   delay(100);}
   if(c==2){buzzer(); stand();
   delay(100);}
   if(c==3){buzzer(); waveHand();
   delay(100);}
   if(c==4){buzzer(); forward();forward();forward();
   delay(100);}
   if(c==5){buzzer(); left();
   delay(100);}
   if(c==6){buzzer();right();
   delay(100);}
if(c==7){sound();
   delay(100);}

 }
 

int flag1,flag2 =0;
void sit()
 {
   led();
if(flag1==0){
  for (int i = 0; i < 4; i++)
  {
    if(i==0 || i==3){
      servo[i][0].write(90);
      delay(10);
      servo[i][1].write(120);
      delay(10);
      servo[i][2].write(55);
      delay(10);
    }
    else{
      servo[i][0].write(90);
      delay(10);
      servo[i][1].write(60);
      delay(10);
      servo[i][2].write(125);
      delay(10);
       }
    }
}
if(flag1==1){
 for (int i = 0; i < 4; i++)
  {
    if(i==0 || i==3){
      servo[i][0].write(90);
      delay(10);
      servo[i][1].write(120);
       }
    else{
      servo[i][0].write(90);
      delay(10);
      servo[i][1].write(60);
      }
      if(i==3 ) {
      for(int j=0;j<=75;j++){
           servo[0][2].write(130-j);
           servo[3][2].write(130-j);
           
         servo[1][2].write(50+j);
         servo[2][2].write(50+j);
        delay(10);}
       }
    
    
    } 
}
flag2=0;
}
 

 void stand(){
   led();
 if(flag2==0){
 
 for (int i = 0; i < 4; i++)
  {
    if(i==0 || i==3){
      servo[i][0].write(90);
      delay(10);
      servo[i][1].write(120);
       }
    else{
      servo[i][0].write(90);
      delay(10);
      servo[i][1].write(60);
    
      }
      if(i==3 ) {
      for(int j=0;j<=75;j++){
           servo[0][2].write(55+j);
           servo[3][2].write(55+j);
           
         servo[1][2].write(125-j);
         servo[2][2].write(125-j);
        delay(10);}
       }
    
    
    }
 }
 if(flag2==1){
  for (int i = 0; i < 4; i++)
  {
    if(i==0 || i==3){
      servo[i][0].write(90);
      delay(10);
      servo[i][1].write(120);
      delay(10);
      servo[i][2].write(130);
       }
    else{
      servo[i][0].write(90);
      delay(10);
      servo[i][1].write(60);
       delay(10);
      servo[i][2].write(50);
    
      }
    
    } 
 }
    flag1,flag2=1;
 }
    
  
 
 
 void waveHand()
{
  led();
      servo[1][0].write(110);
      delay(100);
      servo[1][1].write(60);
      delay(100);
      servo[1][2].write(50);
      delay(100);
   
      servo[3][0].write(90);
      delay(100);
      servo[3][1].write(120);
      delay(100);
      servo[3][2].write(130);
      delay(100);

      servo[2][0].write(0);
      delay(100);
      servo[2][1].write(60);
      delay(100);
      servo[2][2].write(50);
      delay(100);

       servo[0][1].write(180);
       delay(100);
       servo[0][2].write(90);
      for(int i=60; i<=180;i++){
      servo[0][0].write(i);
      delay(10);
      }
      for(int i=180; i>=60;i--){
      servo[0][0].write(i);
      delay(10);
      }

    for(int i=60; i<=180;i++){
      servo[0][0].write(i);
      delay(10);
      if(i==65 || i==120 ||i==170){
       for(int j=60; j<=120;j++){
      servo[0][2].write(j);
      delay(10);
       }
       for(int j=120; j>=60;j--){
      servo[0][2].write(j);
      delay(10);
       }

      }
      servo[0][2].write(90);
      }

      for(int i=180; i>=90;i--){
      servo[0][0].write(i);
      delay(10);
      if(i==100 ||i==150){
       for(int j=60; j<=120;j++){
      servo[0][2].write(j);
      delay(10);
       }
       for(int j=120; j>=60;j--){
      servo[0][2].write(j);
      delay(10);
       }

      }
      servo[0][2].write(90);

      }
      delay(10);
    
    //again stand position
    servo[0][0].write(90);
      delay(100);
      servo[0][1].write(120);
      delay(100);
      for(int j=60; j<=130;j++){
      servo[0][2].write(j);
      delay(10);
       }
     servo[1][0].write(90);
      delay(100);

       servo[2][0].write(30);
      delay(10);
       servo[2][0].write(60);
      delay(10);
       servo[2][0].write(90);
      delay(100);
 flag2,flag1=1;
  }
 

 void forward(){
led();

 for (int i = 0; i < 4; i++)
  {
    if(i==3){
      
      servo[0][0].write(120);
      servo[1][0].write(60);
      
       }

     if(i==0 || i==3){
      servo[i][1].write(120);
      servo[3][0].write(90);
      servo[i][2].write(130);
      
       }
    else{
      servo[2][0].write(90);
      servo[i][1].write(60);
    servo[i][2].write(50);
       }
    }


servo[2][1].write(35);  //2
for(int i=0;i<=60;i++){
servo[2][0].write(90-i);
delay(10);}
servo[2][1].write(60);
delay(10);
servo[2][2].write(50);
delay(10);

// 1st body forward
for(int i=0;i<=30;i++){
servo[0][0].write(120-i); 
servo[1][0].write(60-i);
servo[2][0].write(30+i);
servo[3][0].write(90+i);
delay(10);

}


servo[1][1].write(35);  //1
for(int i=0;i<=60;i++){
servo[1][0].write(30+i);
delay(10);}
servo[1][1].write(60);
delay(10);
servo[1][2].write(50);
delay(100);

servo[0][1].write(145);  //0
for(int i=0;i<=60;i++){
servo[0][0].write(90+i);
delay(10);}
servo[0][1].write(120);
delay(10);
servo[0][2].write(130);
delay(10);

//2nd body forward
for(int i=0;i<=30;i++){
servo[0][0].write(150-i); 
servo[1][0].write(90-i);
servo[2][0].write(60+i);
servo[3][0].write(120+i);
delay(10);

}



servo[3][1].write(145);  //3
for(int i=0;i<=60;i++){
servo[3][0].write(150-i);
delay(10);}
servo[3][1].write(120);
delay(10);
servo[3][2].write(130);
delay(100);
flag1,flag2=1;
 }

 void left(){
led();
 servo[0][1].write(145);  //0
for(int i=0;i<=30;i++){
servo[0][0].write(90+i);
delay(10);}
servo[0][1].write(120);
delay(10);
servo[0][2].write(130);
delay(100);

servo[2][1].write(35);  //2
for(int i=0;i<=30;i++){
servo[2][0].write(90+i);
delay(10);}
servo[2][1].write(60);
delay(10);
servo[2][2].write(50);
delay(100);

servo[3][1].write(145);  //3
for(int i=0;i<=30;i++){
servo[3][0].write(90+i);
delay(10);}
servo[3][1].write(120);
delay(10);
servo[3][2].write(130);
delay(100);

servo[1][1].write(35);  //1
for(int i=0;i<=30;i++){
servo[1][0].write(90+i);
delay(10);}
servo[1][1].write(60);
delay(10);
servo[1][2].write(50);
delay(100);


// body left turn
for(int i=0;i<=30;i++){
servo[0][0].write(120-i); 
servo[1][0].write(120-i);
servo[2][0].write(120-i);
servo[3][0].write(120-i);
delay(10);
}
flag1,flag2=1;
}

 void right(){
led();
 
servo[2][1].write(35);  //2
for(int i=0;i<=30;i++){
servo[2][0].write(90-i);
delay(10);}
servo[2][1].write(60);
delay(10);
servo[2][2].write(50);
delay(100);

servo[0][1].write(145);  //0
for(int i=0;i<=30;i++){
servo[0][0].write(90-i);
delay(10);}
servo[0][1].write(120);
delay(10);
servo[0][2].write(130);
delay(100);

servo[3][1].write(145);  //3
for(int i=0;i<=30;i++){
servo[3][0].write(90-i);
delay(10);}
servo[3][1].write(120);
delay(10);
servo[3][2].write(130);
delay(100);

servo[1][1].write(35);  //1
for(int i=0;i<=30;i++){
servo[1][0].write(90-i);
delay(10);}
servo[1][1].write(60);
delay(10);
servo[1][2].write(50);
delay(100);


// body right turn
for(int i=0;i<=45;i++){
servo[0][0].write(60+i); 
servo[1][0].write(60+i);
servo[2][0].write(60+i);
servo[3][0].write(60+i);
delay(10);
}
flag1,flag2=1;
 }
 
 void led(){
   digitalWrite(A0,HIGH);
   delay(100);
   digitalWrite(A0,LOW);
   delay(100);
 }

 void buzzer(){
   digitalWrite(A1,LOW);
   digitalWrite(A1,HIGH);
   delay(50);
   digitalWrite(A1,LOW);
    }





#define BUZZER_PIN A1



int melody[] = {
  NOTE_E5, NOTE_E5, REST, NOTE_E5, REST, NOTE_C5, NOTE_E5,
  NOTE_G5, REST, NOTE_G4, REST, 
  NOTE_C5, NOTE_G4, REST, NOTE_E4,
  NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
  REST, NOTE_E5,NOTE_C5, NOTE_D5, NOTE_B4,
  NOTE_C5, NOTE_G4, REST, NOTE_E4,
  NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
  REST, NOTE_E5,NOTE_C5, NOTE_D5, NOTE_B4,
  
  REST, NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, NOTE_E5,
  REST, NOTE_GS4, NOTE_A4, NOTE_C4, REST, NOTE_A4, NOTE_C5, NOTE_D5,
  REST, NOTE_DS5, REST, NOTE_D5,
  NOTE_C5, REST,
  
  REST, NOTE_G5, NOTE_FS5, NOTE_F5, NOTE_DS5, NOTE_E5,
  REST, NOTE_GS4, NOTE_A4, NOTE_C4, REST, NOTE_A4, NOTE_C5, NOTE_D5,
  REST, NOTE_DS5, REST, NOTE_D5,
  NOTE_C5, REST,
  
  NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5,
  NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
  
  NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5, NOTE_E5,
  REST, 
  NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5,
  NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
  NOTE_E5, NOTE_E5, REST, NOTE_E5, REST, NOTE_C5, NOTE_E5,
  NOTE_G5, REST, NOTE_G4, REST, 
  NOTE_C5, NOTE_G4, REST, NOTE_E4,
  
  NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
  REST, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_B4,
  
  NOTE_C5, NOTE_G4, REST, NOTE_E4,
  NOTE_A4, NOTE_B4, NOTE_AS4, NOTE_A4,
  NOTE_G4, NOTE_E5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_G5,
  REST, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_B4,
  
  NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
  NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
  NOTE_D5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_F5,
  
  NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
  NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
  NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
  NOTE_B4, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5,
  NOTE_C5, NOTE_E4, NOTE_E4, NOTE_C4,
  
  NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
  NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
  NOTE_D5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_F5,
  
  NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
  NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
  NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
  NOTE_B4, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5,
  NOTE_C5, NOTE_E4, NOTE_E4, NOTE_C4,
  NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5, NOTE_E5,
  REST,
  
  NOTE_C5, NOTE_C5, NOTE_C5, REST, NOTE_C5, NOTE_D5,
  NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
  NOTE_E5, NOTE_E5, REST, NOTE_E5, REST, NOTE_C5, NOTE_E5,
  NOTE_G5, REST, NOTE_G4, REST, 
  NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
  NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
  NOTE_D5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_G5, NOTE_F5,
  
  NOTE_E5, NOTE_C5, NOTE_A4, NOTE_G4,
  NOTE_E5, NOTE_C5, NOTE_G4, REST, NOTE_GS4,
  NOTE_A4, NOTE_F5, NOTE_F5, NOTE_A4,
  NOTE_B4, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_E5, NOTE_D5,
  NOTE_C5, NOTE_E4, NOTE_E4, NOTE_C4,
  
  // Game over sound
  NOTE_C5, NOTE_G4, NOTE_E4,
  NOTE_A4, NOTE_B4, NOTE_A4, NOTE_GS4, NOTE_AS4, NOTE_GS4,
  NOTE_G4, NOTE_D4, NOTE_E4
};

int durations[] = {
  8, 8, 8, 8, 8, 8, 8,
  4, 4, 8, 4, 
  4, 8, 4, 4,
  4, 4, 8, 4,
  8, 8, 8, 4, 8, 8,
  8, 4,8, 8, 4,
  4, 8, 4, 4,
  4, 4, 8, 4,
  8, 8, 8, 4, 8, 8,
  8, 4,8, 8, 4,
  
  
 /* 4, 8, 8, 8, 4, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  4, 4, 8, 4,
  2, 2,
  
  4, 8, 8, 8, 4, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  4, 4, 8, 4,
  2, 2,
  
  8, 4, 8, 8, 8, 4,
  8, 4, 8, 2,
  
  8, 4, 8, 8, 8, 8, 8,
  1, 
  8, 4, 8, 8, 8, 4,
  8, 4, 8, 2,
  8, 8, 8, 8, 8, 8, 4,
  4, 4, 4, 4, 
  4, 8, 4, 4,
  
  4, 4, 8, 4,
  8, 8, 8, 4, 8, 8,
  8, 4, 8, 8, 4,
  
  4, 8, 4, 4,
  4, 4, 8, 4,
  8, 8, 8, 4, 8, 8,
  8, 4, 8, 8, 4,
  
  8, 4, 8, 4, 4,
  8, 4, 8, 2,
  8, 8, 8, 8, 8, 8,
  
  8, 4, 8, 2,
  8, 4, 8, 4, 4,
  8, 4, 8, 2,
  8, 4, 8, 8, 8, 8,
  8, 4, 8, 2,
  
  8, 4, 8, 4, 4,
  8, 4, 8, 2,
  8, 8, 8, 8, 8, 8,
  
  8, 4, 8, 2,
  8, 4, 8, 4, 4,
  8, 4, 8, 2,
  8, 4, 8, 8, 8, 8,
  8, 4, 8, 2,
  8, 4, 8, 8, 8, 8, 8,
  1,
  
  8, 4, 8, 8, 8, 4,
  8, 4, 8, 2,
  8, 8, 8, 8, 8, 8, 4,
  4, 4, 4, 4, 
  8, 4, 8, 4, 4,
  8, 4, 8, 2,
  8, 8, 8, 8, 8, 8,
  
  8, 4, 8, 2,
  8, 4, 8, 4, 4,
  8, 4, 8, 2,
  8, 4, 8, 8, 8, 8,
  8, 4, 8, 2,
  
  //game over sound
  4, 4, 4,
  8, 8, 8, 8, 8, 8,
  8, 8, 2*/
};


void sound()
{
  int size = sizeof(durations) / sizeof(int);

  for (int note = 0; note < size; note++) {
    //to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durations[note];
    tone(BUZZER_PIN, melody[note], duration);

    //to distinguish the notes, set a minimum time between them.
    //the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);
    
    //stop the tone playing:
    noTone(BUZZER_PIN);
  }
}