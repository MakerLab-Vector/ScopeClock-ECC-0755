char DayStr[9] = ""; 
const char* daysOfWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

//==================================RTC REFRESH=================================
void rtcRefresh(){
  DateTime now = rtc.now();
  year      = now.year();
  month     = now.month();
  day       = now.day();
  
  uint8_t dayNum = now.dayOfTheWeek();
    if (dayNum > 6) {
        dayNum = 0; 
    }
    
  strcpy(DayStr, daysOfWeek[dayNum]);
};
//==============================================================================
