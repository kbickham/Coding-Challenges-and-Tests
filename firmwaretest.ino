#include <Wire.h>
#define D1 13
#define D2 12
#define D3 11
#define D4 10
#define D5 9
#define D6 8
#define BUTTONPOWER 2
#define BUT_K3 3
#define BUT_K4 4
#define BTN_ON 0
#define BTN_OFF 1

typedef struct
{ unsigned long timer;
  bool flag;
  bool state; 
  int pin;
} outputp, *poutputp;

typedef struct
{ unsigned long startT,stopT;
  bool flag,state,complete,check;
  int mode;  
} button, *pbutton;

outputp LEDS[6];
button K3;
button K4;

int i = 0;
bool goflag = false;
unsigned long printtimer;


void setup() 
{ Serial.begin(9600);
  LEDS[0].pin=D1;
  LEDS[1].pin=D2;
  LEDS[2].pin=D3;
  LEDS[3].pin=D4;
  LEDS[4].pin=D5;
  LEDS[5].pin=D6;
    pinMode(BUTTONPOWER, OUTPUT);
    pinMode(BUT_K3, INPUT_PULLUP);
    pinMode(BUT_K4, INPUT_PULLUP);
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);
    pinMode(D4, OUTPUT);
    pinMode(D5, OUTPUT);
    pinMode(D6, OUTPUT);
    printtimer=millis();
  for(i=0;i<=5;i++)
    LEDS[i].timer=millis();
};

void loop() 
 {K3.state = digitalRead(BUT_K3);   // bitwise polling port regs
  K4.state = digitalRead(BUT_K4);   // would probably be faster...if time
  //Serial.println(K4.state);
  
  input_k3p();     //start stop time
  d12_handle();  //conditionals to process time for button press
  f_d12out(); 
  
  function_d3(); //flash d3 when powered on

  input_k4p(); 
  function_d456_out(); 
}

void input_k3p()
{ if(K3.state == BTN_ON and K3.flag == false  )
   { K3.startT=millis();
     K3.flag = true; };

 if(K3.state == BTN_OFF and K3.flag == true )
   { K3.stopT=millis();
     K3.complete = true; };  
};    


void input_k4p()
{ 
if(K4.state == BTN_ON and K4.flag == false)
  { K4.startT=millis();
    K4.flag = true;
  };

if(K4.state == BTN_OFF and K4.flag == true)
   { K4.stopT = millis();
     unsigned long tempB = K4.stopT-K4.startT;
    // Serial.print("time: ");
    //Serial.println(tempB);
      if (tempB>=20);
         { if (K4.mode==0)
              { goflag=true;
                  }else{K4.mode=1; };
         };
    K4.flag = false;
    };
};

void d12_handle()
{ if (K3.complete == true)
    { unsigned long tempA = K3.stopT-K3.startT;     
     Serial.print("time k3: ");
     Serial.println(tempA);
     if (tempA<500)                             //DOESN'T STATE MUTUALLY EXCLUSIVITY, ALLOW
       { if (tempA >= 20 and tempA <=100)        //BOTH STATES TO RUN SIMULTANEOUSLY
           { K3.mode=1;
             LEDS[0].state = true;
             LEDS[0].timer=millis();
              }else if (tempA > 100 and tempA <500)
                     { K3.mode=2; 
                       LEDS[1].state = true;
                       LEDS[1].timer=millis(); };
        }else{ K3.mode=0; };                      
        K3.flag = false;
        K3.complete= false;
        };   
};

void f_d12out()
{ switch (K3.mode)
 { case 0:    if (LEDS[0].state != false)
               {digitalWrite(LEDS[0].pin,LOW); 
                LEDS[0].state = false;
               };
               if (LEDS[1].state != false)
               {digitalWrite(LEDS[1].pin,LOW);
                LEDS[1].state = false;
                };
            break;
   case 1:  digitalWrite(LEDS[0].pin,HIGH);
               if ( millis()-LEDS[0].timer >= 1000)
                   {
                     digitalWrite(LEDS[0].pin,LOW);  
                     K3.mode=0; };
            break;
    case 2: digitalWrite(LEDS[1].pin,HIGH);
               if ( millis()-LEDS[1].timer >= 1000)
                   { 
                     digitalWrite(LEDS[1].pin,LOW);  
                     K3.mode=0; };
             break;
    }; 
};

void function_d3()
{ if (millis()-LEDS[2].timer >= 1000)
    { LEDS[2].state= !LEDS[2].state;
      digitalWrite(LEDS[2].pin,LEDS[2].state);
      LEDS[2].timer=millis();  };
};

void function_d456_out()
{   switch(K4.mode)
  {
case 0:  if (goflag==true)
          K4.mode++; 
          break;          
case 1:  digitalWrite(LEDS[3].pin,HIGH);
         digitalWrite(LEDS[4].pin,LOW);
         digitalWrite(LEDS[5].pin,LOW);
         LEDS[3].timer=millis();
         K4.mode++;
         break;         
case 2:  if ( millis()-LEDS[3].timer >= 500)
           {digitalWrite(LEDS[3].pin,LOW);
            K4.mode++;
           };
        break;      
case 3:  digitalWrite(LEDS[3].pin,LOW);
         digitalWrite(LEDS[4].pin,HIGH);
         digitalWrite(LEDS[5].pin,LOW);
         LEDS[4].timer=millis();
         K4.mode++;
         break;         
case 4: if ( millis()-LEDS[4].timer >= 500)
           {digitalWrite(LEDS[4].pin,LOW);
            K4.mode++;
           };
          break;          
case 5:  digitalWrite(LEDS[3].pin,LOW);
         digitalWrite(LEDS[4].pin,LOW);
         digitalWrite(LEDS[5].pin,HIGH);
         LEDS[5].timer=millis();
         K4.mode++;
         break;         
case 6:  if ( millis()-LEDS[5].timer >= 500)
         {digitalWrite(LEDS[5].pin,LOW);
          K4.mode++;
          };
           break;                    
case 7:    goflag=false;
           K4.mode=0;       
           break;
  }; 
};
