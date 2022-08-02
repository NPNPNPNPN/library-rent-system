#include <iostream>

using namespace std;

class Material
{
  protected:
  int iMaterialID;
  string sTitle;

  public:
  //constructors
  Material();
  Material(int, string);
  //getters
  int getMaterialID();
  string getTitle();
  //setters
  void setMaterialID(int);
  void setTitle(string);
  //misc abstract
  virtual void toString() = 0;
  virtual int numberOfDaysRented() = 0;
};

//constructors
Material::Material()
{
  iMaterialID = -1;
  sTitle = "N/A";
}

Material::Material(int iMaterialID, string sTitle)
{
  this -> iMaterialID = iMaterialID;
  this -> sTitle = sTitle;
}

//getters
int Material::getMaterialID()
{
  return iMaterialID;
}

string Material::getTitle()
{
  return sTitle;
}

//setters
void Material::setMaterialID(int iMaterialID)
{
  this -> iMaterialID = iMaterialID;
}

void Material::setTitle(string sTitle)
{
  this -> sTitle = sTitle;
}

