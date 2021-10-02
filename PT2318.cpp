#include <Arduino.h>
#include <Wire.h>
#include "PT2318.h"

PT2318::PT2318(){Wire.begin();}
 

void PT2318::setVolume(int vol, bool loud, bool zcm){
   writeWire(VOLUME, vol + (loud << 6) + (zcm << 7));
}

void PT2318::setFader_FR(int fr){writeWire(FADER_FRONT_RIGHT, 63-fr);} 
void PT2318::setFader_FL(int fl){writeWire(FADER_FRONT_LEFT, 63-fl);} 
void PT2318::setFader_RR(int rr){writeWire(FADER_REAR_RIGHT, 63-rr);} 
void PT2318::setFader_RL(int rl){writeWire(FADER_REAR_LEFT, 63-rl);}

void PT2318::setBass(int bass){
  switch(bass){
   case 12: bass = 0b11101;break;
   case 11: bass = 0b11100;break;
   case 10: bass = 0b11011;break;
   case  9: bass = 0b11010;break;
   case  8: bass = 0b11001;break;
   case  7: bass = 0b11000;break;
   case  6: bass = 0b10111;break;
   case  5: bass = 0b10110;break;
   case  4: bass = 0b10101;break;
   case  3: bass = 0b10100;break;
   case  2: bass = 0b10011;break;
   case  1: bass = 0b10010;break;
   case  0: bass = 0b10001;break; 
   case -1: bass = 0b01111;break;
   case -2: bass = 0b01110;break;
   case -3: bass = 0b01101;break;
   case -4: bass = 0b01100;break;
   case -5: bass = 0b01011;break;
   case -6: bass = 0b01010;break;
   case -7: bass = 0b01001;break;
   case -8: bass = 0b01000;break;
   case -9: bass = 0b00111;break;
   case -10: bass = 0b00110;break;
   case -11: bass = 0b00101;break;
   case -12: bass = 0b00100;break;
}
  writeWire(BASS, bass);
}

void PT2318::setTreble(int treble){
  switch(treble){
   case  8: treble = 0b11001;break;
   case  7: treble = 0b11000;break;
   case  6: treble = 0b10111;break;
   case  5: treble = 0b10110;break;
   case  4: treble = 0b10101;break;
   case  3: treble = 0b10100;break;
   case  2: treble = 0b10011;break;
   case  1: treble = 0b10010;break;
   case  0: treble = 0b10001;break; 
   case -1: treble = 0b01111;break;
   case -2: treble = 0b01110;break;
   case -3: treble = 0b01101;break;
   case -4: treble = 0b01100;break;
   case -5: treble = 0b01011;break;
   case -6: treble = 0b01010;break;
   case -7: treble = 0b01001;break;
   case -8: treble = 0b01000;break;
}
  writeWire(TREBLE, treble);
}

void PT2318::setIn(int in, bool gmu){
  switch(in){
    case 0: in = 0b111;break;
    case 1: in = 0b110;break;
    case 2: in = 0b101;break;
    case 3: in = 0b100;break;
    case 4: in = 0b000;break;
}
writeWire(SWITCH, in + (gmu << 7));}


void PT2318::writeWire(byte a, byte b){
  Wire.beginTransmission(PT2318_address);
  Wire.write (a);
  Wire.write (b);
  Wire.endTransmission();
}
