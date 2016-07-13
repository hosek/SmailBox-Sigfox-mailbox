#include <Wire.h>
#include <SmeSFX.h>
#include <Arduino.h>

#define BUTTON_PIN       13  // Button
#define DELAY            1000  


char helloMsg[4]= {'M','a', 'i', 'l'};
bool messageSent;

void setup() {
    
    SerialUSB.begin(115200);
    sfxAntenna.begin();
    int initFinish=1;

    pinMode(BUTTON_PIN, INPUT);

    SerialUSB.println("SFX in Command mode");
    sfxAntenna.setSfxConfigurationMode(); // enter in configuration Mode

    do {
        uint8_t answerReady = sfxAntenna.hasSfxAnswer();
        if (answerReady){
            switch (initFinish){
            case 1:                                
                SerialUSB.println("SFX in Data mode");
                sfxAntenna.setSfxDataMode();
                initFinish++;
                break;

            case 2:
                initFinish++; // exit
                break;
            }
        }
    } while (initFinish!=3);
}

void loop() {
  
    SerialUSB.println(digitalRead(BUTTON_PIN));
 
    if(digitalRead(BUTTON_PIN) == HIGH)
    {
     
      SerialUSB.println("You have a mail!");
      sfxAntenna.sfxSendData(helloMsg, strlen((char*)helloMsg));
  
      bool answerReady = sfxAntenna.hasSfxAnswer();
  
      if (answerReady) {
          if (sfxAntenna.getSfxMode() == sfxDataMode) {
  
              switch (sfxAntenna.sfxDataAcknoledge()) {
              case SFX_DATA_ACK_START:
                  SerialUSB.println("Waiting Answer");
                  break;
  
              case SFX_DATA_ACK_PROCESSING:
                  SerialUSB.print('.');
                  break;
  
              case SFX_DATA_ACK_OK:
                  ledGreenLight(HIGH);
                  SerialUSB.println(' ');
                  SerialUSB.println("Delivered");
                  break;
  
              case SFX_DATA_ACK_KO:
                  ledRedLight(HIGH);
                  SerialUSB.println(' ');
                  SerialUSB.println("Delivery failed");
                  break;
              }
          }
    }
      delay(DELAY); 
    }
}

