#include <Arduino.h>
#define Reed A2 //input Reed Sensor
#define P1 6    //binnenste ring LEDs
#define P2 3    //middele ring LEDs
#define P3 10   //buitenste ring LEDs
#define X1 11   //amulet verlichting
#define RS analogRead(Reed) //reed state
#define Result pgm_read_byte(&gamma[i])
#define Resultp pgm_read_byte(&gamma[p])
#define Resultq pgm_read_byte(&gamma[q])
#define Resultr pgm_read_byte(&gamma[r])


void ReedSetup () {
  pinMode(Reed,INPUT);
  pinMode(P1,OUTPUT);
  pinMode(P2,OUTPUT);
  pinMode(P3,OUTPUT);
  pinMode(X1,OUTPUT);
}

const uint8_t PROGMEM gamma[] = {
    0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
    2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
    5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
   10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
   17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
   25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
   37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
   51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
   69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
   90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
  115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
  144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
  177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
  215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255 };
  
  
//  
  
void Breathe (int timeb = 5) {         //Breathe is de amulet verlichting als er geen magneet is
   int gu = 1;                         
   //timeb is hoe snel Breathe pulseerd
   for (int i = 0; i > -1; i = i + gu){
      analogWrite(X1, Result);
      if (i == 120) gu = -1;             //i == is de max LED intensiteit van 0-255
      delay(timeb);
   } 
}

int count=0;
unsigned int p=0;
unsigned int q=0;
unsigned int r=0;
int d=1;
int e=1;
int f=1;

void Circles (int timea = 2000) {    //Circles zijn de 3 buiten kringen LEDs
  count=0;                           //timea is de wacht tijd hoe snel de sequentie afloopt
    for(int a=0;a>-1;a=a+1) { 
    if (a==254) a=-1;
    if (count==5){break;}
    if (a==0) {count=count+1;}
    
    delayMicroseconds (timea);
    
      if (count>=1 &&count<=2)  {
          p=p+d;
          if (p==255) d=-1;      
          analogWrite (P1,Resultp);    
      }
      else {digitalWrite (P1,0);p=0;d=1;}
      
      if (count>=2 &&count<=3) {
          q=q+e;
          if (q==255) e=-1;
          analogWrite (P2,Resultq);
      }
      else {digitalWrite (P2,0);q=0;e=1;}
      if (count>= 3 && count<=4) {
          r=r+f;
          if (r==255) f=-1;
          analogWrite (P3,Resultr);
      }
      else {digitalWrite (P3,0);r=0;f=1;}
     
  }
}
