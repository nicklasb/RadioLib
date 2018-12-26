#ifndef _KITELIB_MODULE_H
#define _KITELIB_MODULE_H

#include <SPI.h>
//#include <Wire.h>
#include <SoftwareSerial.h>

#include "TypeDef.h"

class Module {
  public:
    Module(int cs, int int0, int int1);
    Module(int cs, int tx, int rx, int int0, int int1);
    
    SoftwareSerial* ModuleSerial;
    
    uint32_t baudrate = 9600;
    const char* AtLineFeed = "\r\n";
    
    uint8_t SPIreadCommand = 0b00000000;
    uint8_t SPIwriteCommand = 0b10000000;
    
    void init(uint8_t interface, uint8_t gpio);
    
    void ATemptyBuffer();
    bool ATgetResponse();
    bool ATsendCommand(const char* cmd);
    bool ATsendData(uint8_t* data, uint32_t len);
    
    int16_t SPIgetRegValue(uint8_t reg, uint8_t msb = 7, uint8_t lsb = 0);
    int16_t SPIsetRegValue(uint8_t reg, uint8_t value, uint8_t msb = 7, uint8_t lsb = 0, uint8_t checkInterval = 2);
    
    void SPIreadRegisterBurst(uint8_t reg, uint8_t numBytes, uint8_t* inBytes);
    uint8_t SPIreadRegister(uint8_t reg);
    
    void SPIwriteRegisterBurst(uint8_t reg, uint8_t* data, uint8_t numBytes);
    void SPIwriteRegister(uint8_t reg, uint8_t data);
    
    int cs() const { return(_cs); }
    int int0() const { return(_int0); }
    int int1() const { return(_int1); }
    
  private:
    int _cs;
    int _tx;
    int _rx;
    int _int0;
    int _int1;
    
    uint32_t _ATtimeout = 15000;
};

#endif
