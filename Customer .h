//-|-----------------------------------------------------------------
//-| Name of File: Customer.h
//-| Group 6:      Racaria Burgess, Janei Elliston, 
//-|               Michael Mondelice, Michael Parrish
//-| Last Edited:  February 26, 2020
//-|
//-| Purpose: Our company is a major clothing manufacturer 
//-|          who sells to most major department and clothing 
//-|          stores throughout the US. Because of the size of 
//-|          our business, we extend a line of credit to all 
//-|          our customers. The purpose of this file is to  
//-|          write a program that accepts information 
//-|          that should be read for the text file  
//-|          and loaded into a objects of class Customer.
//-|         
//-|-----------------------------------------------------------------

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <iomanip>

class Customer{
    string cusNum;
    string cusName;
    double lCredit;
    Address * corperateAddress;       //pointer to address object
    
    public:                         //<-no arguement constructor 
    Customer();
    Customer(string,string,double);
    void setcusNum(string);
    string getcusNum();
    void setcusName(string);
    string getcusName;
    void setlCredit(double);
    double getlCredit();
    Address * getCusAddress();
    void setCusAddress(Address *);
};