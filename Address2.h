//-|-----------------------------------------------------------------
//-| Name of File: Address.h
//-| Group 6:      Racaria Burgess, Janei Elliston, 
//-|               Michael Mondelice, Michael Parrish
//-| Last Edited:  February 26, 2020
//-|
//-| Purpose: The purpose of this class is to return the customer's 
//-|          address.
//-|-----------------------------------------------------------------

#include <string>

class Address{
 private:
    std::string streetAddress;
	std::string city;
	std::string state;
	std::string zipCode;

 public:
    /**************************************************************
	 *                          Address                           *
	 *                                                            *
	 * Passed   : No arguments                                    *
	 * Purpose  : Constructor that does not accept                *
	 *            member variables                                *          
	 **************************************************************/
	Address();

    /**************************************************************
	 *                          Address                           *
	 *                                                            *
	 * Passed   : 4 arguments: 4 strings                          *
	 * Purpose  : Constructor that accepts member variables       *
	 **************************************************************/
    Address(std::string, std::string, std::string, std::string);

    //-|------------------------------------------------------------
    //-| Accessor and Mutator functions
    //-|------------------------------------------------------------

    /**************************************************************
	 *                          setStreetAddress                  *
	 *                                                            *
	 * Passed   : 1 argument: a string                            *
	 * Purpose  : Set the person's street address                 *              
	 **************************************************************/
	void setStreetAddress(std::string);

    /**************************************************************
	 *                          setCity                           *
	 *                                                            *
	 * Passed   : 1 argument: a string                            *
	 * Purpose  : Set the name of city that the person lives in   *
	 **************************************************************/
	void setCity(std::string);

    /**************************************************************
	 *                          setState                          *
	 *                                                            *
	 * Passed   : 1 argument: a string                            *
	 * Purpose  : Set the name of the state that the person lives *
	 *            in                                              *       
	 **************************************************************/    
	void setState(std::string);

    /**************************************************************
	 *                          setZipCode                        *
	 *                                                            *
	 * Passed   : 1 argument: a string                            *
	 * Purpose  : Set the zip code                                *
	 **************************************************************/    
	void setZipCode(std::string);

    /**************************************************************
	 *                          getStreetAddress                  *
	 *                                                            *
	 * Passed   : 1 argument: 1 string                            *
	 * Purpose  : Returns the street address                      *
	 * Returns  : String                                          *
	 **************************************************************/    
	std::string getStreetAddress();

    /**************************************************************
	 *                          getCity                           *
	 *                                                            *
	 * Passed   : 1 argument: 1 string                            *
	 * Purpose  : Returns the city that the person lives in       *
	 * Returns  : String                                          *
	 **************************************************************/    
	std::string getCity();

    /**************************************************************
	 *                          getState                          *
	 *                                                            *
	 * Passed   : 1 argument: 1 string                            *
	 * Purpose  : Returns the state that the person lives in      *
	 * Returns  : String                                          *
	 **************************************************************/    
	std::string getState();

    /**************************************************************
	 *                          getZipCode                        *
	 *                                                            *
	 * Passed   : 1 argument: 1 string                            *
	 * Purpose  : Returns the  city that the person lives in      *
	 * Returns  : String                                          *
	 **************************************************************/    
	std::string getZipCode();

    /**************************************************************
	 *                          getAddress                        *
	 *                                                            *
	 * Passed   : 1 argument: 1 string                            *
	 * Purpose  : Prints the person's  full address               *
	 **************************************************************/    
    void getAddress();

}
