#include <iostream>
#include "Date.h"

using namespace std;

class Reservation
{
  private:
  int iMaterial;
  int iClientID;
  Date reservationDate;

  public:
  //constructors
  Reservation();
  Reservation(int, int, Date);
  //getters
  int getMaterial();
  int getClientID();
  Date getDate();
  //setters
  void setMaterial(int);
  void setClientID(int);
  void setDate(Date);
  //misc
  Date calculateEndOfReservation(int);
  //trial
  void toString();
};

//constructors
Reservation::Reservation()
{
  iMaterial = -1;
  iClientID = -1;
}

Reservation::Reservation(int iMaterial, int iClientID, Date reservationDate)
{
  this -> iMaterial = iMaterial;
  this -> iClientID = iClientID;
  this -> reservationDate = reservationDate;
}

//getters
int Reservation::getMaterial()
{
  return iMaterial;
}

int Reservation::getClientID()
{
  return iClientID;
}

Date Reservation::getDate()
{
  return reservationDate;
}

//setters
void Reservation::setMaterial(int iMaterial)
{
  this -> iMaterial = iMaterial;
}

void Reservation::setClientID(int iClientID)
{
  this -> iClientID = iClientID;
}

void Reservation::setDate(Date reservationDate)
{
  this -> reservationDate = reservationDate;
}

//misc
Date Reservation::calculateEndOfReservation(int iDatys)
{
  reservationDate = reservationDate + iDatys;
  return reservationDate;
}

//trial

void Reservation::toString()
{
  cout << "     " << iMaterial << "      |   ";
  cout << iClientID << "     |   ";
  cout << reservationDate;
}