# AVR_DS3231_DRIVER
A driver  for RTC DS3231 using AVR micro-controller

### SETTING RTC TIME
To set the DS3231 RTC time to your current time we use a struct to contain all the required parameters.

          RTC_value rtc;
          rtc.second = 00; //seconds
          rtc.minute = 10; //minutes
          rtc.hour = 23; //hours in 24 hour system
          rtc.day = 1 ; // monday = 1 , tuesday = 2 , wednesday = 3 , thursday = 4, friday = 5 , saturday = 6 , sunday = 7
          rtc.month = 11 ; //November 
          rtc.year = 2019 ; //current year;
  
To set the time details defined into the  DS3231 we creat an object of the RTC class and initialize it, we then get to use the set_time(RTC_value rtc) method.
          
          RTC DS3231; //create object of the RTC class
          DS3231.init(); //initialize the RTC module
          DS3231.set_time(rtc); //we pass in the rtc struct to the function to set the time
          
 ### Getting RTC TIME
 To get time from the rtc module we use a struct as discussed in the setting section, the module is then initialized and get_time() methode is used to get the time.
 
          RTC_value rtc;
          rtc = DS3231.get_time();
          
 To access the data retreived from DS3231 module.
 
        uint8_t second = rtc.second;
        uint8_t minute = rtc.minute;
        uint8_t hour = rtc.hour;
        uint8_t day = rtc.day;
        uint8_t date = rtc.date;
        uint8_t month = rtc.month;
        uint8_t year = rtc.year;
          
