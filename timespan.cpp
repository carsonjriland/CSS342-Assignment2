//
// Created by Carson on 01/17/20.
//

#include "timespan.h"
#include<iostream>
#include<string>
using namespace std;
//                                   Midway Notes:
//                                   ------------
//After converting to seconds, convert it back to hours, minutes, and seconds. This way
//it will get rid of all the negatives. Then youll need to adjust your other methods so it adds and subtracts.
//Which just means youll have to make variebales in your constructor that represent hours minutes seconds for all values in ts.
//Or you could make a method that converts seconds to hours and mintues, and backwards. That way you can do all 
// all your operations with seconds then convert them back ;)

TimeSpan::TimeSpan(double hours, double minutes, double seconds) {  
      
      timeInSec = static_cast<int>(hours * 3600 + minutes * 60 + seconds);
      ho = timeInSec / 3600;
      min = (timeInSec % 3600) / 60;
      sec = (timeInSec % 3600) % 60;
}
//I use alot of if statments to make sure that the time is 
//formatted in the correct ways for the tests to work
ostream& operator<<(ostream& output, const TimeSpan& timespan) {
    string comp = to_string(timespan.ho) + ':';
    if (timespan.min == 0) {
        comp = comp + "00" + ':';
    }
    else if (timespan.min <= 9 && timespan.min >= 0) {
        comp = comp + "0" + to_string(timespan.min) + ':';
    }
    else if (timespan.min < 0 && timespan.min >= -9) {
        comp = '-' + comp + '0' + to_string(timespan.min * -1);
    }
    else if (timespan.min <= -10) {
        comp = '-' + comp + to_string(timespan.min * -1);
    }
    else {
        comp = comp + to_string(timespan.min) + ':';
    }

    if (timespan.sec == 0) {
        comp = comp + "00";
    }
    else if(timespan.sec < 0 && timespan.sec >= -9) {
        comp = '-' + comp + '0' + to_string(timespan.sec * -1);
    }
    else if (timespan.sec <= -10) {
        comp = '-' + comp + to_string(timespan.sec * -1);
    }
    else if (timespan.sec <= 9 && timespan.sec >= 0) {
        comp = comp + "0" + to_string(timespan.sec);
    }  
    else {
        comp = comp + to_string(timespan.sec);
    }
    output << comp;
     return output;
} 

TimeSpan TimeSpan::operator+(const TimeSpan& timespan) const {
    int t = timeInSec + timespan.timeInSec;
  TimeSpan ts(0, 0, t);
  return ts;
} //change down here according to constructor

TimeSpan TimeSpan::operator-(const TimeSpan& timespan) const {
    int t = timeInSec - timespan.timeInSec;
    TimeSpan ts(0, 0, t);
    return ts;
}

TimeSpan TimeSpan::operator*(int number) {
    int t = timeInSec * number;
    TimeSpan ts(0, 0, t);
  return ts;
}

TimeSpan TimeSpan::operator+=(const TimeSpan& timespan) const {
    int t = timeInSec + timespan.timeInSec;
    TimeSpan ts(0, 0, t);
    return ts;
}

TimeSpan TimeSpan::operator-=(const TimeSpan& timespan) const {
    int t = timeInSec - timespan.timeInSec;
    TimeSpan ts(0, 0, t);
    return ts;
}

bool TimeSpan::operator==(const TimeSpan& timespan) const {
    bool isEqual = (timeInSec == timespan.timeInSec);
    return isEqual;
}

bool TimeSpan::operator!=(const TimeSpan& timespan) const {
    bool isEqual = (timeInSec != timespan.timeInSec);
    return isEqual;
}
 //for below methods, if the expressions are correct it shall return true
bool TimeSpan::operator<(const TimeSpan& timespan) const {
    bool isEqual = (timeInSec < timespan.timeInSec);
    return isEqual;
}

bool TimeSpan::operator>(const TimeSpan& timespan) const {
    bool isEqual = (timeInSec > timespan.timeInSec);
    return isEqual;
}

bool TimeSpan::operator>=(const TimeSpan& timespan) const {
    bool isEqual = (timeInSec >= timespan.timeInSec);
    return isEqual;
}

bool TimeSpan::operator<=(const TimeSpan& timespan) const {
    bool isEqual = (timeInSec <= timespan.timeInSec);
    return isEqual;
}
