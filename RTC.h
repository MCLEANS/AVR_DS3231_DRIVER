/* 
* RTC.h
*
* Created: 10/24/2019 8:04:26 AM
* Author: MCLEANS
*/


#ifndef __RTC_H__
#define __RTC_H__

#define  RTC_ADDR_WRITE 0b11010000
#define  SECONDS_ADDR 0x00
#define  RTC_ADDR_READ 0b11010001

#include "i2c.h"

struct RTC_value{
	
	uint8_t second;
	uint8_t minute;
	uint8_t hour;
	uint8_t day;
	uint8_t date;
	uint8_t month;
	uint8_t year;
	
	
};
	

class RTC
{
//variables
public:
protected:
private:
	

//functions
public:
	RTC();
	~RTC();
	void init();
	void set_time(RTC_value rtc);
	RTC_value get_time();
protected:
private:
	RTC( const RTC &c );
	RTC& operator=( const RTC &c );

}; //RTC

#endif //__RTC_H__
