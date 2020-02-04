//
// TODO Created by Carson on 01/17/20.
//

#pragma once
#include <iostream>
using namespace std;

class TimeSpan {
  friend ostream &operator<<(ostream& output, const TimeSpan& timespan);

public:
  // explicit TimeSpan(int hours = 0, int minutes = 0, int seconds = 0);
  explicit TimeSpan(double hours = 0, double minutes = 0, double seconds = 0);
  
  TimeSpan operator-(const TimeSpan& timespan) const;
  //subtraction
  TimeSpan operator+(const TimeSpan& timespan) const;
  // adds
  TimeSpan operator+=(const TimeSpan& timespan) const;
  //Addition
  TimeSpan operator-=(const TimeSpan& timespan) const;
  //subtraction
  bool operator<(const TimeSpan& timespan) const;
  //less than
  bool operator>(const TimeSpan& timespan) const;
  //greater than
  bool operator>=(const TimeSpan& timespan) const;
  //greater than or equal to
  bool operator<=(const TimeSpan& timespan) const;
  //less than or equal to
  bool operator==(const TimeSpan& timespan) const;
  // check equality
  bool operator!=(const TimeSpan& timespan) const;
  // check if not equal
  TimeSpan operator<<(const TimeSpan& timespan) const;

    TimeSpan operator*(int number);
    // multiply timespan by a number

private:
    int timeInSec;
    int ho;
    int min;
    int sec;
    
};
