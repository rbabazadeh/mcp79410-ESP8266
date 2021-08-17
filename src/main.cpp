#include <Arduino.h>
#include "Wire.h"
#include "MCP7941x.h"

// Create new instance of class:
MCP7941x rtc = MCP7941x();
byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
//!--------------------------------------------------------------------------------------
void displayDateTime(byte second,byte minute,byte hour,byte dayOfWeek,byte dayOfMonth,byte month,byte year) 
{
  Serial.print(year, DEC);
  Serial.print("/");
  if (month < 10)  Serial.print("0") ;  
  Serial.print(month, DEC);
  Serial.print("/");
  if (dayOfMonth < 10) Serial.print("0");
  Serial.print(dayOfMonth, DEC);
  Serial.print("  ");

  if (hour < 10)Serial.print("0");
  Serial.print(hour, DEC);
  Serial.print(":");
  if (minute < 10)Serial.print("0");
  Serial.print(minute, DEC);
  Serial.print(":");
  if (second < 10) Serial.print("0");
  Serial.println(second, DEC);
}
//!--------------------------------------------------------------------------------------
void rtc_setup()
{
  rtc.enableBattery();
  rtc.enableClock();
  

  // Set the time?
  boolean setTime =false;
  second = 0;
  minute = 12;
  hour = 1;
  dayOfWeek = 3;   // 1 = Sunday, 7 = Saturday
  dayOfMonth = 10;
  month = 10;
  year = 21;
  if (setTime == true)  rtc.setDateTime(second, minute, hour, dayOfWeek, dayOfMonth, month, year);
}
//!--------------------------------------------------------------------------------------
void rtc_p()
{
  rtc.getDateTime(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month, &year);
  displayDateTime(second, minute, hour, dayOfWeek, dayOfMonth, month, year);
    
}
//!--------------------------------------------------------------------------------------
void setup()
{
  Serial.begin(9600);
  rtc_setup();
}
//!--------------------------------------------------------------------------------------
void loop()
{
  rtc_p();
  delay(1000);
}

