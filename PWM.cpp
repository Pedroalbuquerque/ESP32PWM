#include "ESP32PWM.h"
char tmp[100];

void PWM::initialize(  int channel, int pbasefreq , int timer , int pin){
  _channel = channel;
  basefreq = pbasefreq;
  _timer = timer;
  
  ledcSetup(_channel, basefreq, _timer);
  ledcAttachPin(pin, _channel);
}
void PWM::initialize(  int channel , int pbasefreq , int timer ){
  _channel = channel;
  basefreq = pbasefreq;
  _timer = timer;
  
  ledcSetup(_channel, basefreq, _timer);
  }

bool PWM::attach(uint8_t pin, uint32_t pvalueMax = 255){
  int err;
  _valueMax = pvalueMax ;
  ledcAttachPin(pin, _channel);
  return true;
}

void PWM::analogWrite( uint32_t value) {
  // pulse width, 8191 from 2 ^ 13 - 1
  uint32_t width = (8191 / _valueMax) * min(value, _valueMax);

  // write PWM width
  ledcWrite(_channel, width);
}


