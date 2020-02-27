//-|-----------------------------------------------------------------
//-| Name of File: Customer.cpp
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
#include "Customer.h"



using namespace std;

Customer::Customer(){               //no arguement constructor
    cusNum="";
    cusName="";
    lCredit=0.0;
}

Customer::Customer(string cN,string cNa, double lC){    //constructor
    setcusNum(x);
    setcusName(y);                                      //mutator function
    setlCredit(z);
}
void Customer::setcusNum(string cN){
    customerNumber=cN;
}

string Customer::getcusNum(){                            //accessor function 
    return cusNum;
}

void Customer::setcusName(string cNa){
    customerName=cNa;
}

string Customer::getcusName(){
    return cusName;
}

void Customer::setlCredit(double lC){
    lineOfCredit=lC;
}

double Customer::getlCredit(){
    return lCredit;
}

void Customer::setCusAddress(Address * address){ 
    corperateAddress = addresss;
}

Address * Customer::getCusAddress(){
    return corperateAddress;
}



