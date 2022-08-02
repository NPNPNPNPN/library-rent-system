#include <iostream>

using namespace std;

class Book: public Material
{
  private:
  int iNumOfPages;
  string sAuthor;

  public:
  //constructors
  Book();
  Book(int, string, int, string);
  //getters
  int getNumOfPages();
  string getAuthor();
  //setters
  void setNumOfPages(int);
  void setAuthor(string);
  //misc
  void toString();
  int numberOfDaysRented();
};

//constructors
Book::Book():Material()
{
  iNumOfPages = -1;
  sAuthor = "N/A";
}

Book::Book(int iNumOfPages, string sAuthor, int iMaterialID, string sTitle):Material(iMaterialID, sTitle)
{
  this -> iNumOfPages = iNumOfPages;
  this -> sAuthor = sAuthor;
}

//getters
int Book::getNumOfPages()
{
  return iNumOfPages;
}

string Book::getAuthor()
{
  return sAuthor;
}

//setters
void Book::setNumOfPages(int iNumOfPages)
{
  this -> iNumOfPages = iNumOfPages;
}

void Book::setAuthor(string sAuthor)
{
  this -> sAuthor = sAuthor;
}

//misc
void Book::toString()
{
  cout << " " << iMaterialID << "  |   " ;
  cout << iNumOfPages << "   |   " ;
  cout << sAuthor << "  |  " ;
  cout << sTitle << "  |  " ;
  cout << endl;
}

int Book::numberOfDaysRented()
{
  return 10;
}