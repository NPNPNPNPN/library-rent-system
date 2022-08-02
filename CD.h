#include <iostream>

using namespace std;

class CD:public Material
{
  private:
  int iDuration;

  public:
  //constructors
  CD();
  CD(int, int, string);
  //getters
  int getDuration();
  //setters
  void setDuration(int);
  //misc
  void toString();
  int numberOfDaysRented();
};

//constructors
CD::CD():Material()
{
  iDuration = -1;
}

CD::CD(int iDuration, int iMaterialID, string sTitle):Material(iMaterialID, sTitle)
{
  this ->iDuration = iDuration;
}

//getters
int CD::getDuration()
{
  return iDuration;
}

//setters
void CD::setDuration(int iDuration)
{
  this -> iDuration = iDuration;
}

//misc
void CD::toString()
{
  cout <<  iMaterialID << "   |  ";
    cout <<  iDuration << "  |  ";
  cout << sTitle << "  |  ";
  cout << endl;
}

int CD::numberOfDaysRented()
{
  return 3;
}