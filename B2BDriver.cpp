/*
File Name: B2BDriver.cpp
Group Number: 6
Members: Michael Parrish, Janei Elliston, Racaria Burgess, Michael Mondelice
Recent Edit Date: 2/26/2020
*/

#include <ctime>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>
#include "Product.h"

using namespace std;

string generateOrderNum(){ //orderSummary << generateOrderNum();
    time_t now = time(0);
    string oNum;
    stringstream strstream;
    strstream << now;
    strstream >> oNum;
    return oNum;
}

int main(){
    
    ofstream orderSummary;
    orderSummary.open("orderSummary.dat"); // everyones code should be below this
    
    orderSummary <<"Order Number: " << generateOrderNum()<<endl;
    
    int iNum, iQTY,count = 0, iNumChoice, j, itmcount;
    double iPrice,total=0;
    string iDescrip, holder1;
    ifstream invFile("inventory.dat");
    
    while (getline(invFile, holder1)) { //creates a count of items to create pointer array
        count++;
    }
    
    invFile.close();
    invFile.clear();
    invFile.open("inventory.dat");
    
    Product *productInfo = new Product[count];  
    
    j=0;
    itmcount = 1;
    while(getline(invFile,holder1)){ //pulls string from file
        stringstream hold(holder1); //turns string into stream to allow parse
    while(getline(hold,holder1,',')){ //parses stringstream
        
        if (itmcount==4){
            iQTY=atoi(holder1.c_str());
            (*(productInfo+j)).setStockQuantity(iQTY);
            itmcount = 1;
            j++;
        }
        
        else if (itmcount==3){
            iPrice=atof(holder1.c_str());
            (*(productInfo+j)).setPrice(iPrice);
            itmcount = 4;
        }
        
        else if (itmcount==2){
            iDescrip=holder1;
            (*(productInfo+j)).setDescription(iDescrip);
            itmcount = 3;
        }
        
        else if (itmcount==1){
            iNum=atoi(holder1.c_str());
            (*(productInfo+j)).setItemNo(iNum);
            itmcount = 2;
        }
       
    }
    }
        
    bool choice1=false, choice2=false, error1=false; // choice 1 and 2 are used for loop traps while error1 is used for validation of Product ID
    int purchaseQTY[count];
    
    for(int i=0; i<count; i++){ // displays all items and details
        (*(productInfo+i)).printSummary();
    }
    
    
    while (choice1==false){ // item selection and quantity selection, loops user inputs 0
        cout << "Please select the item(s) the customer wishes to purchase (Enter Item # shown above. Enter 0 when finished with this step)" << endl;
        cin >> iNumChoice;
        int i=0;
        while (i<count){
            if(iNumChoice==(*(productInfo+i)).getItemNo()){
                bool flag=true;
                (*(productInfo+i)).setBool(flag);
                cout << "Please Enter Purchase Quantity Amount: ";
                cin >> purchaseQTY[i];
                int q=(*(productInfo+i)).getStockQuantity();
                while((q<purchaseQTY[i])||(purchaseQTY[i]<0)){//validation for quantity
                    cout<< "Invalid Quantity." << endl << "Please Enter Purchase Quantity Amount: ";
                cin >> purchaseQTY[i];
                error1=true;
                }
                total+= (purchaseQTY[i]*(*(productInfo+i)).getPrice());
                
            }
            else if (iNumChoice==0){
                choice1=true;
                error1=true;
            }
            i++;
        }
        if (error1==false){
            cout <<"Invalid Product ID" << endl;
        }
        
    }
    
    invFile.close();
    invFile.clear(); //closes and clears input file;
    
    while(choice2==false){ //creates output for final order summary
        int i=0;
        while(i<count){
            int num, q;
            string desc;
            double p, pTotal;
            if((*(productInfo+i)).getBool()==true){
                num=(*(productInfo+i)).getItemNo();
                desc=(*(productInfo+i)).getDescription();
                p=(*(productInfo+i)).getPrice();
                q=(*(productInfo+i)).getStockQuantity();
                pTotal=purchaseQTY[i]*p;
                orderSummary<< num << "|" << desc <<"|"<<purchaseQTY[i]<<"|$"<< pTotal<<endl; // needs setprecision[2]
                }
            i++;
        }
        choice2=true; 
    }
    
    orderSummary << "$" << total << endl; // prints total
    
    
	
	return 0;
}
