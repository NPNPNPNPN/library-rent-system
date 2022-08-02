#include <iostream>

using namespace std;

#pragma once

class Date
{
  private:
  int iDay;
  int iMonth;
  int iYear;

  public:
  //constructors
  Date();
  Date(int, int, int);
  //getters
  int getDay();
  int getMonth();
  int getYear();
  //setters
  void setDay(int);
  void setMonth(int);
  void setYear(int);
  //operators
  friend Date operator + (Date&, int);
  friend bool operator >= (Date, Date);
  friend bool operator > (Date, Date);
  friend bool operator <= (Date, Date);
  friend bool operator < (Date, Date);
  friend bool operator == (Date, Date);
  friend void operator >> (istream&, Date&);
  friend void operator << (ostream&, Date);
  friend bool operator != (Date, Date);
  //misc
  string nameOfMonth();
};

//constructors
Date::Date()
{
  iDay = -1;
  iMonth = -1;
  iYear = -1;
}

Date::Date(int iDay, int iMonth, int iYear)
{
  this -> iDay = iDay;
  this -> iMonth = iMonth;
  this -> iYear = iYear;
}

//getters
int Date::getDay()
{
  return iDay;
}

int Date::getMonth()
{
  return iMonth;
}

int Date::getYear()
{
  return iYear;
}

//setters
void Date::setDay(int iDay)
{
  this -> iDay = iDay;
}

void Date::setMonth(int iMonth)
{
  this -> iMonth = iMonth;
}

void Date::setYear(int iYear)
{
  this -> iYear = iYear;
}

//operators
Date operator + (Date &D1, int iD)
{
  int iDay = D1.getDay();
  int iMonth = D1.getMonth();
  int iYear = D1.getYear();
  iDay += iD;
  if ( ( (iMonth == 1) or (iMonth == 3) or (iMonth == 5) or (iMonth == 7) or (iMonth == 8) or (iMonth == 10) ) and (iDay > 31) )
  {
    iMonth += 1;
    iDay -= 31;
  }
  else if ( ( (D1.getMonth() == 4) or (iMonth == 6) or (iMonth == 9) or (iMonth == 11)) and (iDay > 30) )
  {
    iMonth +=1;
    iDay -=30;
  }
  else if ( (D1.getMonth() == 2) and (iDay > 28) )
  {
    iMonth += 1;
    iDay -= 28;
  }
  else if ( (D1.getMonth() == 12) and (iDay > 31) )
  {
    iYear += 1;
    iDay -= 31;
    iMonth -= 11;
  }
  D1.setDay(iDay);
  D1.setMonth(iMonth);
  D1.setYear(iYear);
  return D1;
}

bool operator >= (Date D1, Date D2)
{
  if ( (D1.getDay() >= D2.getDay()) and (D1.getMonth() >= D2.getMonth()) and (D1.getYear() >= D2.getYear()) )
  {
    return true;
  }
  else
  return false;
}

bool operator > (Date D1, Date D2)
{
  if ( (D1.getDay() > D2.getDay()) and (D1.getMonth() > D2.getMonth()) and (D1.getYear() > D2.getYear()) )
  {
    return true;
  }
  else
  return false;
}

bool operator <= (Date D1, Date D2)
{
  if ( (D1.getDay() <= D2.getDay()) and (D1.getMonth() <= D2.getMonth()) and (D1.getYear() <= D2.getYear()) )
  {
    return true;
  }
  else
  return false;
}

bool operator < (Date D1, Date D2)
{
  if ( (D1.getDay() < D2.getDay()) and (D1.getMonth() < D2.getMonth()) and (D1.getYear() < D2.getYear()) )
  {
    return true;
  }
  else
  return false;
}

bool operator == (Date D1, Date D2)
{
  if ( (D1.getDay() == D2.getDay()) and (D1.getMonth() == D2.getMonth()) and (D1.getYear() == D2.getYear()) )
  {
    return true;
  }
  else
  return false;
}

void operator >> (istream &is, Date &D1)
{
  int iD, iM, iY;
  cout << "Month: " << endl;
  is >> iM;
  while ( (iM != 1) and (iM != 2) and (iM !=  3) and (iM != 4) and (iM != 5) and (iM != 6) and (iM != 7) and (iM != 8) and (iM != 9) and (iM != 10) and (iM != 11) and (iM != 12) )
  {
    cout << "invalid Month: " << endl;
    is >> iM;
  }
  cout << "Day: " << endl;
  is >> iD;
  if ( (iM == 1) or (iM == 3) or (iM == 5) or (iM == 7) or (iM == 8) or (iM == 10) or (iM == 12) )
  {
    while ( (iD > 31) or (iD < 1) )
    {
      cout << "invalid day for inputed month" << endl;
       cout << "Day: " << endl;
       is >> iD;
    }
  }
  else if ( (iM == 4) or (iM == 6) or (iM == 9) or (iM == 11) )
  {
     while ( (iD > 30) or (iD < 1) )
    {
      cout << "invalid day for inputed month" << endl;
       cout << "Day: " << endl;
       is >> iD;
    }
  }
  else if (iM == 2)
  {
    while ( (iD > 28) or (iD < 1))
    {
      cout << "invalid day for inputed month" << endl;
       cout << "Day: " << endl;
       is >> iD;
    }
  }
  cout << "Year: "<< endl;
  is >> iY;
  D1.setDay(iD);
  D1.setMonth(iM);
  D1.setYear(iY);
}

void operator << (ostream &os, Date D1)
{
  os << D1.getDay() << " / " << D1.getMonth() << " / " << D1.getYear();
}

bool operator != (Date D1, Date D2)
{
  if ((D1.getDay() != D2.getDay()) and (D1.getMonth() != D2.getMonth()) and (D1.getYear() != D2.getYear()))
  {
    return true;
  }
  else
  return false;
}

//misc
string Date::nameOfMonth()
{
  string sM;
  sM = "hmm";
  if (iMonth == 1)
  {
    sM = "January";
  }
  else if (iMonth == 2)
  {
    sM = "February";
  }
  else if (iMonth == 3)
  {
    sM = "March";
  }
  else if (iMonth == 4)
  {
    sM = "April";
  }
  else if (iMonth == 5)
  {
    sM = "May";
  }
  else if (iMonth == 6)
  {
    sM = "June";
  }
  else if (iMonth == 7)
  {
    sM = "July";
  }
  else if (iMonth == 8)
  {
    sM = "August";
  }
  else if (iMonth == 9)
  {
    sM = "September";
  }
  else if (iMonth == 10)
  {
    sM = "October";
  }
  else if (iMonth == 11)
  {
    sM = "November";
  }
  else if (iMonth == 12)
  {
    sM = "December";
  }
  return sM;
}