/* 
* RTC.cpp
*
* Created: 10/24/2019 8:04:25 AM
* Author: MCLEANS
*/


#include "RTC.h"

TWI i2c;

// default constructor
RTC::RTC()
{
	i2c.init();
} //RTC

// default destructor
RTC::~RTC()
{
} //~RTC

void RTC::init(){
		i2c.start(RTC_ADDR_WRITE);
		i2c.write(0x0E);
		i2c.write(0x20);
		i2c.write(0x08);
		i2c.stop();
}

RTC_value RTC::get_time(){
	RTC_value rtc;
	i2c.start(RTC_ADDR_WRITE);
	i2c.write(SECONDS_ADDR);
	i2c.stop();
	
	i2c.start(RTC_ADDR_READ);
	rtc.second = i2c.BCD_to_decimal(i2c.readACK() & 0x7f);
	rtc.minute = i2c.BCD_to_decimal(i2c.readACK());
	rtc.hour = i2c.BCD_to_decimal(i2c.readACK() & 0x3f);
	rtc.day = i2c.BCD_to_decimal(i2c.readACK());
	rtc.date = i2c.BCD_to_decimal(i2c.readACK());
	rtc.month = i2c.BCD_to_decimal(i2c.readACK());
	rtc.year = i2c.BCD_to_decimal(i2c.readNACK());
	
	i2c.stop();
	
	return rtc;
}

void RTC::set_time(RTC_value rtc){
	i2c.start(RTC_ADDR_WRITE);
	i2c.write(SECONDS_ADDR);
	i2c.write(i2c.decimal_to_BCD(rtc.second));
	i2c.write(i2c.decimal_to_BCD(rtc.minute));
	i2c.write(i2c.decimal_to_BCD(rtc.hour));
	i2c.write(i2c.decimal_to_BCD(rtc.day));
	i2c.write(i2c.decimal_to_BCD(rtc.date));
	i2c.write(i2c.decimal_to_BCD(rtc.month));
	i2c.write(i2c.decimal_to_BCD(rtc.year));
	i2c.stop();
}
