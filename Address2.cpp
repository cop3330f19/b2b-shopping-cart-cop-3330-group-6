//-|-----------------------------------------------------------------
//-| Name of File: Address.h
//-| Group 6:      Racaria Burgess, Janei Elliston, 
//-|               Michael Mondelice, Michael Parrish
//-| Last Edited:  February 26, 2020
//-|
//-| Purpose: The purpose of this class is to return the customer's
//-|          address.
//-|-----------------------------------------------------------------

#include <iostream>
#include <string>
#include "Address.h"

using namespace std;

    /**************************************************************
	 *                          Address                           *
	 *                                                            *
	 * Passed   : No arguments                                    *
	 * Purpose  : Constructor that does not accept                *
	 *            member variables                                *          
	 **************************************************************/
     Address::Address(){}

    /**************************************************************
	 *                          Address                           *
	 *                                                            *
	 * Passed   : 4 arguments: 4 strings                          *
	 * Purpose  : Constructor that accepts member variables       *
	 **************************************************************/
     Address::Address(string SA, string C, string S, 
                      string Z){
     streetAddress = SA;
     city = C;
     state = S;
     zipCode = Z;
     }

    //-|------------------------------------------------------------
    //-| Accessor and Mutator functions
    //-|------------------------------------------------------------

    /**************************************************************
	 *                          setStreetAddress                  *
	 *                                                            *
	 * Passed   : 1 argument: a string                            *
	 * Purpose  : Set the person's street address                 *              
	 **************************************************************/
     void Address::setStreetAddress(string adrs){
     streetAddress = adrs;  
     }

    /**************************************************************
	 *                          setCity                           *
	 *                                                            *
	 * Passed   : 1 argument: a string                            *
	 * Purpose  : Set the name of city that the person lives in   *
	 **************************************************************/
     void Address::setCity(string ct){
     city = ct; 
     } 

    /**************************************************************
	 *                          setState                          *
	 *                                                            *
	 * Passed   : 1 argument: a string                            *
	 * Purpose  : Set the name of the state that the person lives *
	 *            in                                              *       
	 **************************************************************/ 
     void Address::setState(string st){
     state = st;  
     }

    /**************************************************************
	 *                          setZipCode                        *
	 *                                                            *
	 * Passed   : 1 argument: a string                            *
	 * Purpose  : Set the zip code                                *
	 **************************************************************/ 
     void Address::setZipCode(string zip){
     zipCode = zip; 
     }

    /**************************************************************
	 *                          getStreetAddress                  *
	 *                                                            *
	 * Passed   : 1 argument: 1 string                            *
	 * Purpose  : Returns the street address                      *
	 * Returns  : String                                          *
	 **************************************************************/
     string Address::getStreetAddress(){return streetAddress;}

    /**************************************************************
	 *                          getCity                           *
	 *                                                            *
	 * Passed   : 1 argument: 1 string                            *
	 * Purpose  : Returns the city that the person lives in       *
	 * Returns  : String                                          *
	 **************************************************************/
     string Address::getCity(){return city;}

    /**************************************************************
	 *                          getState                          *
	 *                                                            *
	 * Passed   : 1 argument: 1 string                            *
	 * Purpose  : Returns the state that the person lives in      *
	 * Returns  : String                                          *
	 **************************************************************/
     string Address::getState(){return state;}

    /**************************************************************
	 *                          getZipCode                        *
	 *                                                            *
	 * Passed   : 1 argument: 1 string                            *
	 * Purpose  : Returns the  city that the person lives in      *
	 * Returns  : String                                          *
	 **************************************************************/
     string Address::getZipCode(){return zipCode;}

    /**************************************************************
	 *                          getAddress                        *
	 *                                                            *
	 * Passed   : 1 argument: 1 string                            *
	 * Purpose  : Prints the person's  full address               *
	 **************************************************************/
      void Address::getAddress(){
      cout << streetAddress << " |" << endl << city <<
          ", " << state << " " << zipCode;
      }
