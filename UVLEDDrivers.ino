
//Chris Olsen, 2014

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#define UVLED_BUFFER_SIZE   60
#define UVLED_START_DELIM   '<'
#define UVLED_END_DELIM     '>'
boolean debug = false;
int ledArray[16];
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
typedef struct {
  unsigned char head;
  unsigned char tail;
  boolean active;
  char buffer[UVLED_BUFFER_SIZE];
} 


RingBuffer;
RingBuffer b = {
  0,0,false};

void setup(){
  Serial.begin(9600);
  Serial.println("Hello");
  pwm.begin();
  pwm.setPWMFreq(1600);  // This is the maximum PWM frequency
  // save I2C bitrate
  uint8_t twbrbackup = TWBR;
  // must be changed after calling Wire.begin() (inside pwm.begin())
  TWBR = 12; // upgrade to 400KHz!
}



void loop(){

  if (Serial.available()) {
    char c = (char)Serial.read();
    //   Serial1.write(c);
    uvled_buffer_add(c);  
  }




}


////////////////////////////////////////////////////////////////////////////////////

void uvled_buffer_add(char c)
{
  if(c == UVLED_START_DELIM)
  {
    //Serial.println("start");
    b.head = 0;
    b.tail = 0;
    b.active = true;
  }
  else if(c == UVLED_END_DELIM)
  {
    //Serial.println("end");
    if(b.active == false)
    {
      //Serial.println("empty");
    }
    else
    {
      uvled_buffer_check();
      b.active = false;
    }
  }
  else
  {
    if(b.active)
    {
      if(b.tail < UVLED_BUFFER_SIZE) 
      {
        b.buffer[b.tail] = c;
        b.tail++;
      } 
      else
      {
        //Serial.println("full");
        b.active = false;
      }
    }
  }
}



void uvled_buffer_check(void)
{
  unsigned char msgIdx = 0;
  unsigned char idx = 0;
  char tempChar = b.buffer[idx];

  while(msgIdx < 16)    //delim for msg size
  {
    String tempStr = "";
    unsigned int tempInt = 0;

    while(tempChar != ',' && idx < b.tail)
    {
      tempStr += tempChar;
      tempChar = b.buffer[++idx];
    }  

    tempInt = tempStr.toInt();


   

    if(msgIdx == 0){ 

      if (debug){
        Serial.print("Echo: ");
        Serial.println(tempInt);    //debug
      }
      //ledArray[msgIdx] = tempInt;
      pwm.setPWM(msgIdx, 0, map(tempInt,0,255,0,4095));
    }

    else if(msgIdx == 1){ 

      if (debug){
        Serial.print("Echo: ");
        Serial.println(tempStr);    //debug
      }
      //ledArray[msgIdx] = tempInt;
      pwm.setPWM(msgIdx, 0, map(tempInt,0,255,0,4095));
    }
    else if(msgIdx == 2){ 

      if (debug){
        Serial.print("Echo: ");
        Serial.println(tempStr);    //debug
      }
      // ledArray[msgIdx] = tempInt;
      pwm.setPWM(msgIdx, 0, map(tempInt,0,255,0,4095));
    }
    else if(msgIdx == 3) { 

      if (debug){
        Serial.print("Echo: ");
        Serial.println(tempStr);    //debug
      }
      // ledArray[msgIdx] = tempInt;
      pwm.setPWM(msgIdx, 0, map(tempInt,0,255,0,4095));
    }
    else if(msgIdx == 4){ 

      if (debug){
        Serial.print("Echo: ");
        Serial.println(tempStr);    //debug
      }
      //  ledArray[msgIdx] = tempInt;
      pwm.setPWM(msgIdx, 0, map(tempInt,0,255,0,4095));
    }
    else if(msgIdx == 5) { 

      if (debug){
        Serial.print("Echo: ");
        Serial.println(tempStr);    //debug
      }
      // ledArray[msgIdx] = tempInt;
      pwm.setPWM(msgIdx, 0, map(tempInt,0,255,0,4095));
    }
    else if(msgIdx == 6) { 

      if (debug){
        Serial.print("Echo: ");
        Serial.println(tempStr);    //debug
      }
      //ledArray[msgIdx] = tempInt;
      pwm.setPWM(msgIdx, 0, map(tempInt,0,255,0,4095));
    }
    else if(msgIdx == 7) { 

      if (debug){
        Serial.print("Echo: ");
        Serial.println(tempStr);    //debug
      }
      // ledArray[msgIdx] = tempInt;
      pwm.setPWM(msgIdx, 0, map(tempInt,0,255,0,4095));
    }
    else if(msgIdx == 8) { 

      if (debug){
        Serial.print("Echo: ");
        Serial.println(tempStr);    //debug
      }
      //  ledArray[msgIdx] = tempInt;
      pwm.setPWM(msgIdx, 0, map(tempInt,0,255,0,4095));
    }
    else if(msgIdx == 9) { 

      if (debug){
        Serial.print("Echo: ");
        Serial.println(tempStr);    //debug
      }
      //    ledArray[msgIdx] = tempInt;
      pwm.setPWM(msgIdx, 0, map(tempInt,0,255,0,4095));
    }
    else if(msgIdx == 10) { 

      if (debug){
        Serial.print("Echo: ");
        Serial.println(tempStr);    //debug
      }
      //ledArray[msgIdx] = tempInt;
      pwm.setPWM(msgIdx, 0, map(tempInt,0,255,0,4095));
    }
    else if(msgIdx == 11) { 

      if (debug){
        Serial.print("Echo: ");
        Serial.println(tempStr);    //debug
      }
      //   ledArray[msgIdx] = tempInt;
      pwm.setPWM(msgIdx, 0, map(tempInt,0,255,0,4095));
    }
    else if(msgIdx == 12) { 

      if (debug){
        Serial.print("Echo: ");
        Serial.println(tempStr);    //debug
      }
      //ledArray[msgIdx] = tempInt;
      pwm.setPWM(msgIdx, 0, map(tempInt,0,255,0,4095));
    }
    else if(msgIdx == 13) { 

      if (debug){
        Serial.print("Echo: ");
        Serial.println(tempStr);    //debug
      }
      //   ledArray[msgIdx] = tempInt;
      pwm.setPWM(msgIdx, 0, map(tempInt,0,255,0,4095));
    }
    else if(msgIdx == 14) { 

      if (debug){
        Serial.print("Echo: ");
        Serial.println(tempStr);    //debug
      }
      // ledArray[msgIdx] = tempInt;
      pwm.setPWM(msgIdx, 0, map(tempInt,0,255,0,4095));
    }
    else if(msgIdx == 15) { 

      if (debug){
        Serial.print("Echo: ");
        Serial.println(tempStr);    //debug
      }
      //ledArray[msgIdx] = tempInt;
      pwm.setPWM(msgIdx, 0, map(tempInt,0,255,0,4095));
    }
    else if(msgIdx == 16){
      // ledArray[msgIdx] = tempInt;
      pwm.setPWM(msgIdx, 0, map(tempInt,0,255,0,4095));
      //  adressLEDS();
    }


    msgIdx++;
    tempChar = b.buffer[++idx];

  }



}

void adressLEDS(){
  Serial.print("ArrayDump");
  for (int i=0;i<=16-1;){

    Serial.println(ledArray[i]);
  }
}


