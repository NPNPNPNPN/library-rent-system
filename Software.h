#include <iostream>

using namespace std;

class Software:public Material
{
  private:
  string sOperatingSystem;

  public:
  //constructors
  Software();
  Software(string, int, string);
  //getters
  string getOperatingSystem();
  //setters
  void setOperatingSystem(string);
  //misc
  void toString();
  int numberOfDaysRented();
};

//constructors
Software::Software():Material()
{
  sOperatingSystem = "N/A";
}

Software::Software(string sOperatingSystem, int iMaterial, string sTitle):Material(iMaterial, sTitle)
{
  this -> sOperatingSystem = sOperatingSystem;
}

//getters
string Software::getOperatingSystem()
{
  return sOperatingSystem;
}

//setters
void Software::setOperatingSystem(string sOperatingSystem)
{
  this -> sOperatingSystem = sOperatingSystem;
}

//misc
void Software::toString()
{
  cout <<  iMaterialID << "  |  ";
    cout <<  sOperatingSystem << "  |  ";
  cout << sTitle << "  |  ";
  cout << endl;
}

int Software::numberOfDaysRented()
{
  return 1;
}