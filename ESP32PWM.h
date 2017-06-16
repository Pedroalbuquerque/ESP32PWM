/* ESP32 PWM Library
 * Copyright (C) 2017 by Pedro Albuquerque
 *
 *
 * This file is part of a set of tools to facilitate migration form ESP8266 code to ESP32
 *
 * This Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License v3.0
 * along with the Arduino PATinySPI Library.  If not, see
 * <http://www.gnu.org/licenses/>.
 */




#ifndef ESP32PWM_H
#define ESP32PWM_H

#include "Arduino.h"

class PWM {
  public:
  uint8_t value;
  uint16_t basefreq;
  void initialize(  int _channel, int _basefreq, int _timer, int _pin);
  void initialize( int channel, int basefreq , int timer );
  bool attach(uint8_t pin, uint32_t pvalueMax);
  void analogWrite( uint32_t value);

  protected:
  uint8_t _timer, _channel, _valueMax;
};


#endif
