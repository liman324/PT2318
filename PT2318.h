// liman324@yandex.ru rcl-radio.ru

#ifndef PT2318_H
#define PT2318_H

#define PT2318_address     0x40
#define VOLUME             0x00
#define FADER_FRONT_RIGHT  0x01
#define FADER_FRONT_LEFT   0x02
#define FADER_REAR_RIGHT   0x03
#define FADER_REAR_LEFT    0x04
#define BASS               0x05
#define TREBLE             0x06
#define SWITCH             0x07

#include <Arduino.h>
class PT2318
{
  public:
    PT2318();
    void setVolume(int vol, bool loud, bool zcm);  
    // int 12...63 === -31...+20 dB
    // Loudness 0 = on, 1 = off
    // не менять
    void setFader_FR(int fr);  // int 0...63 
    void setFader_FL(int fl);  // int 0...63 
    void setFader_RR(int rr);  // int 0...63 
    void setFader_RL(int rl);  // int 0...63 
    void setBass(int bass);    // int -12...0...+12
    void setTreble(int treble);// int -8...0...+8
    void setIn(int in, bool gmu); 
    // IN = int 0...3, MONO = int 4
    // MUTE 0 = off, 1 = on

 private:
    void writeWire(byte a, byte b);
};
	
#endif //PT2318_H
