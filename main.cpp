#include <iostream>
#include <fstream>
#include "Reservation.h"
#include "Date.h"
#include "Material.h"
#include "Book.h"
#include "CD.h"
#include "Software.h"

using namespace std;

int main() 
{
  ifstream ifFile;
  //material variables
  int iMaterialID;
  string sTitle;
  int iNumOfDaysRented;
  //book
  int iNumOfPages;
  string sAuthor;
  //CD
  int iDuration;
  //Software
  string sOperatingSystem;
  //Date
  int iDay, iMonth, iYear;
  //Reservation
  int iClientID;
  //misc
  int iNumberOfAccounts;
  int iNumberOfReservations;
  char cMaterialType;
  char cOption;
  //objects
  Material *listOfMaterials[20];
  Reservation *listOfReservations[50];
  Date reservationDate;
  Date endOfReservation;

  int iC = 0;
  iNumberOfAccounts = 0;
  ifFile.open("material.txt");
  while (!ifFile.eof())
  {
    ifFile >> iMaterialID;
    ifFile >> sTitle;
    ifFile >> cMaterialType;

    //reading the file and creating an object according to its type
    if (cMaterialType == 'B')
    {
      ifFile >> iNumOfPages;
      ifFile >> sAuthor;
      listOfMaterials[iC] = new Book(iNumOfPages, sAuthor, iMaterialID, sTitle);
      iC++;
      iNumberOfAccounts++;
    }
    else if (cMaterialType == 'C')
    {
      ifFile >> iDuration;
      listOfMaterials[iC] = new CD(iDuration, iMaterialID, sTitle);
      iC++;
      iNumberOfAccounts++;
    }
    else if (cMaterialType == 'S')
    {
      ifFile >> sOperatingSystem;
      listOfMaterials[iC] = new Software(sOperatingSystem, iMaterialID, sTitle);
      iC++;
      iNumberOfAccounts++;
    }
  }
  ifFile.close();

  iNumberOfReservations = 0;

  ifFile.open("reservations.txt");
  while(!ifFile.eof())
  {
    ifFile >> iDay;
    ifFile >> iMonth;
    ifFile >> iYear;
    ifFile >> iMaterialID;
    ifFile >> iClientID;
    listOfReservations[iNumberOfReservations] = new Reservation(iMaterialID, iClientID, Date(iDay, iMonth, iYear));
    iNumberOfReservations++;
  }
  ifFile.close();

  do
  {
    cout << endl;
    cout << "Library menu : " << endl;
    cout << "a. Display available materials for rent" << endl;
    cout << "b. Display list of Reservations" << endl;
    cout << "c. Display the reservations of a given material" << endl;
    cout << "d. Display the reservations made on a given date" << endl;
    cout << "e. Reservate a material" << endl;
    cout << "f. Exit the program" << endl;
    cin >> cOption;

     switch(cOption)
    {
      case 'a': {
                  cout << "__iD__" << "|__Pages__" << "|____________Author__________" << "|_______________Title_____________" << endl;
                  for (int iQ = 0; iQ < 10; iQ++)
                  {
                    listOfMaterials[iQ] -> toString();
                  }
                  cout << endl << endl;

                  cout << "__iD__" << "|_Duration_" << "|___Title___" << endl;
                  for (int iP = 10; iP < 15; iP++)
                  {
                    listOfMaterials[iP] -> toString();
                  }
                  cout << endl << endl;
                  cout << "__iD__" << "|___OS___" << "|____Title____" << endl;
                  for (int iT = 15; iT < 20; iT++)
                  {
                    listOfMaterials[iT] -> toString();
                  }
                  cout << endl << endl;               
                cout << endl << endl;
                break;
      }
      case 'b': {    cout << "|_Material iD_" << "|__Client iD__" << "|_reservation Date_" << "|_reservation end date_"<< "|_Material Title_" << endl;
                for(int iW = 0; iW < iNumberOfReservations; iW++)
                {
                  iMaterialID = listOfReservations[iW] -> getMaterial();
                  for(int iR = 0; iR < iNumberOfAccounts; iR++)
                  {
                    if (iMaterialID == listOfMaterials[iR] -> getMaterialID())
                    {
                      sTitle = listOfMaterials[iR] -> getTitle();
                      iNumOfDaysRented = listOfMaterials[iR] -> numberOfDaysRented();
                    }
                  }
                  reservationDate = listOfReservations[iW] -> getDate();
                  listOfReservations[iW] -> toString();
                  endOfReservation = reservationDate + iNumOfDaysRented;
                  cout << "  |  ";
                  cout << endOfReservation;
                  cout << "     |  " << sTitle << endl;
                }
                break;
      }
      case 'c': { cout << "Please input the iD of the material: " << endl;
                cin >> iMaterialID;
                int iCount;
                bool bCycle = false;
                //and iCount tatement created so that if multiple reservations were made for the same material
                //it doesnt stop at the first one
                while (bCycle == false and iCount != iNumberOfReservations)
                {
                for(int iR = 0; iR < iNumberOfReservations; iR++)
                {
                  if ( iMaterialID == listOfReservations[iR] -> getMaterial())
                  {
                    for (int iT = 0; iT < iNumberOfAccounts; iT++)
                    {
                      if ( iMaterialID == listOfMaterials[iT] -> getMaterialID() )
                      {
                        iNumOfDaysRented = listOfMaterials[iT] -> numberOfDaysRented();
                        sTitle = listOfMaterials[iT] -> getTitle();
                      }
                    }
                    cout << endl;
                    if (iNumOfDaysRented == 1)
                    {
                      cout << "Software title:  ";
                    }
                    else if (iNumOfDaysRented == 3)
                    {
                      cout << "CD title:   ";
                    }
                    else
                    {
                      cout << "Book title:  ";
                    }
                    cout << sTitle << endl;
                    cout << "_material iD__" << "|__client iD__" << "|_reservation date_" << "|_reservation end date_" << endl;
                    listOfReservations[iR] -> toString();
                    endOfReservation = listOfReservations[iR] -> calculateEndOfReservation(iNumOfDaysRented);
                    cout << " |   ";
                    cout << endOfReservation;
                    cout << endl;
                    bCycle = true;
                  }
                  iCount++;
                }
                if (bCycle == false) //cycles loop if the iD was not found
                 {
                  cout << "Please input an existing iD" << endl;
                  cin >> iMaterialID;
                 }
                }
                break;
      }
      case 'd': { cout << "Please input the day on which the reservation was made: " << endl;
                 cin >> iDay;
                 cout << "Please input the month on which the reservation was made: " << endl;
                 cin >> iMonth;
                 cout << "Please input the year on which the reservation was made: " << endl;
                 cin >> iYear;
                 //no date validation since this option is more "organic"
                 reservationDate.setDay(iDay);
                 reservationDate.setMonth(iMonth);
                 reservationDate.setYear(iYear);
                 bool bConfirmation = false;
                 for (int iY = 0; iY < iNumberOfReservations; iY++)
                 {
                   if ( reservationDate ==  listOfReservations[iY] -> getDate() )
                   {
                     iMaterialID = listOfReservations[iY] -> getMaterial();
                     iClientID = listOfReservations[iY] -> getClientID();
                     for (int iP = 0; iP < iNumberOfAccounts; iP++)
                     {
                       if ( iMaterialID == listOfMaterials[iP] -> getMaterialID() )
                       {
                         sTitle = listOfMaterials[iP] -> getTitle();
                         iNumOfDaysRented = listOfMaterials[iP] -> numberOfDaysRented();
                       }
                     }
                     if (iNumOfDaysRented == 1)
                     {
                       cout << "Software :  ";
                     }
                    else if (iNumOfDaysRented == 3)
                     {
                       cout << "CD :   ";
                     }
                    else
                     {
                       cout << "Book :  ";
                     }
                     cout << sTitle << endl;
                     cout << "Material iD: " << iMaterialID << endl;
                     cout << "Client iD: " << iClientID << endl << endl;
                     bConfirmation = true;
                   }
                 }
                 if (bConfirmation == false)
                 {
                   cout << "No reservations made on given date" << endl;
                 }
                 break;
      }
      case 'e':  bool bValidMaterial = false;
                  bool bValidDate = false;
                  bool dummyBool = true;
                  bool dummyBool2 = false;
                  Date dummyDate;
                 cout << "Please input the client iD: " << endl;
                 cin >> iClientID;
                 //loop that will keep asking for a correct material iD until one is given
                 while (bValidMaterial == false)
                 {
                  cout << "Please input the material iD of which you wish to reserve: " << endl;
                  cin >> iMaterialID;
                  for ( int iF = 0; iF < iNumberOfAccounts; iF++ )
                   {
                     if (iMaterialID == listOfMaterials[iF] -> getMaterialID())
                     {
                       //obtaining number of days that this material can be rented
                       iNumOfDaysRented = listOfMaterials[iF] -> numberOfDaysRented();
                       bValidMaterial = true;
                     }
                   }
                   if (bValidMaterial == false)
                   {
                   cout << "Nonexistent or invalid material iD" << endl;
                   }
                 }
                 //making sure that the inputed date does not land on the days
                 //that the material has already been rented
                 //ex. if the material is rented for 3 days on 20/11/2017
                 //it wont allow the user to rent it for the next 3 days 
                 while (bValidDate == false)
                 {
                   cin >> reservationDate;
                   for (int iH = 0; iH < iNumberOfReservations; iH++)
                   {
                     if (iMaterialID == listOfReservations[iH] -> getMaterial())
                     {
                       dummyDate = listOfReservations[iH] -> getDate(); 
                        //cout << "dummy date: ";
                        //cout << dummyDate;
                         cout << endl;                  
                       for (int iJ = 0; iJ < iNumOfDaysRented; iJ++)
                       {
                         endOfReservation = dummyDate + iJ;
                         //cout << "dummy date: ";
                         //cout << dummyDate;
                         //cout << endl;
                         //cout << "endOfReservation: ";
                         //cout << endOfReservation;
                         //cout << endl;
                         if (endOfReservation == reservationDate)
                         {
                           //dummybool used since I wanted to loop this until an
                           //available date was inputed
                           dummyBool = false;
                       }
                     }                     
                   }
                   }
                   if (dummyBool == true)
                   {
                     bValidDate = true;
                   }
                   else if (dummyBool == false)
                   {
                     cout << "Material already reserved during requested period" << endl;
                     cout << "Please choose another date" << endl;
                     dummyBool = true;
                   }    
                 }
                  if (bValidDate)
                  {
                     listOfReservations[iNumberOfReservations] = new Reservation(iMaterialID, iClientID, reservationDate);
                     cout << endl << "succesful reservation" << endl;
                     iNumberOfReservations++;
                  }
                  break;   
    }
  }while (cOption != 'f' and cOption != 'F');


return 0;
}