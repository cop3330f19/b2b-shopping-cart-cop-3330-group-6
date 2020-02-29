/*
B2BDriver.cpp
Group Number: 6
RaCaria Burgess, Michael Parrish, Janei Elliston, Michael Mondelice
2/27/20
The purpose of this Driver file is to incorporate the three class files together. As the associate enters the items (using the item number) and quantities, 
the system should verify that the customer still has available credit and the stock has not be depleted. The system should also verify that the a
ssociate is entering accurate information. 
Once completed, the system will display a final order summary and update the stock of the items sold.
 */


#include <iostream> 
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>
#include "Product.h"
#include "Customer.h"
#include "StringHelper.h"

using namespace std;

//ALLOWS PROGRAM TO BE ABLE TO COUNT LINES IN THE FILES 
int countFileLines(string holder)
{
    int count1=0;
    string cust;
    
    fstream inFile;
    inFile.open(holder);
       while (getline(inFile, cust)){//creates a count of items to create pointer array
        count1++;
       }
        return count1;
    inFile.close();
    
    }
//INCREASE FILE COMPACITY AS IT GROWS
int fileCount = countFileLines("customers.dat");
//GLOBAL VARIABLES

//ADDRESS
string addy, cust, _streetAddress, _state, _zipCode, _addy, _city;
//CUSTOMER
string CName, CNum;
double CreditL;

//OBJECTS
Customer custId[100];
Address addressId[100];
Product prodId[100];


//MIRROR ADDRESS CLASS VECTOR 
vector<int> mAddress;
//ADDRESS VECTOR
vector<Address> addVec;
vector<Product>prodVec;

//GENERATE RANDOM ORDER NUM
string generateOrderNum(){ //orderSummary << generateOrderNum();
    time_t now = time(0);
    string oNum;
    stringstream strstream;
    strstream << now;
    strstream >> oNum;
    return oNum;
}

//ASSIGNS CUSTOMER ADDRESS DEPENDING ON THE INDEX 
void AddressVectorAssign(){
   for(int x=0; x < mAddress.size(); x++){
       vector<Address>::iterator addA= addVec.begin();
       advance(addA, mAddress[x]);
       custId[x].setCusAddress(&(*addA));
   }
}

int AddAddress(string _streetAddress, string _city, string _state, string _zipCode)
{
 //SEE'S IF ADDRESS IS FOUND IF IT IS THEN RETURNS A INDEX
 Address temp(_streetAddress, _city, _state, _zipCode);
    
 for(int i = 0; i < addVec.size(); i++){
    if(addVec[i].getStreetAddress() == temp.getStreetAddress()){
        return i;
    }
  }
   addVec.push_back(temp);
    return addVec.size()-1;
}


void getCustumerInfo(int count, string f){
    //COLLECTS INFO AND PARSES IT
    fstream infile;
    infile.open(f);
    
    vector<string> cust;
    vector<string> addr;
    string temp;
    
    for(int x=0; x< count; x++ ){
        getline(infile, temp);
        //cout << temp << endl;
        cust = StringHelper::parse(temp, '|');
        //cout << cust[0] << endl;
        CNum=  cust[0];
        CName= cust[1];
        CreditL = stod(cust[2]);
        _addy= cust[3];
        
         addr = StringHelper::parse(_addy, ',');
        
        _streetAddress= addr[0];
        _city= addr[1];
        _state= addr[2];
        _zipCode= addr[3];
        
        custId[x].setcusName(CName);
        custId[x].setcusNum(CNum);
        custId[x].setlCredit(CreditL);
        addressId[x].setCity(_city);
        addressId[x].setState(_state);
        addressId[x].setZipCode(_zipCode);
        
         mAddress.push_back(AddAddress(_streetAddress, _city, _state, _zipCode));
         AddressVectorAssign();
   }  
}

int findCustInfo(string id)
{
   int exit;
   for(int i=0; i < fileCount; i++)
   {
       if(custId[i].getcusNum() == id)
       {
          return i;
       }
       else
          exit = -1;
   }
    return exit;
}



int main(){
    cout << "Start" << endl;
    int custIndex;
    string associate;
    string cID;
    double total = 0;
    int counts= fileCount;
  
    getCustumerInfo(counts, "customers.dat");

    //OPENS UP ORDER SUMMARY
    ofstream orderSummary;
    orderSummary.open("orderSummary.dat"); 
       
    orderSummary <<"Order Number: " << generateOrderNum()<<endl;
    string NumOrder= generateOrderNum();
    
    

    cout <<"Enter Associate's Name: "<<endl;
    cin >>associate;
    
    
    //CORPERATE NUM VALIDATION   

    cout <<"Enter Customer ID:" <<endl;
    cin  >> cID;
    custIndex = findCustInfo(cID);
    while(custIndex == -1){
        cout << "Invalid Customer Id Number" << endl;
        cout <<"Enter Customer ID:" <<endl;
        cin  >> cID;
        custIndex = findCustInfo(cID);
    }
    
    orderSummary << "Customer Number:" << (*(custId+findCustInfo(cID))).getcusNum() << endl;
    orderSummary << "Customer: " << (*(custId+findCustInfo(cID))).getcusName() << endl;
    
  
     int iNum, iQTY,count = 0, iNumChoice, j, itmcount;
     double iPrice;
     string iDescrip, holder1;
     fstream invFile("inventory.dat");
    
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
    
    
     while (choice1==false){ // item selection and quantity selection,to end loop user inputs 0
        cout << "Please select the item(s) the customer wishes to purchase (Enter Item # shown above. Enter 0 when finished with order.)" << endl;
        cin >> iNumChoice;
         int i=0;
         while (i<count){
             if(iNumChoice==(*(productInfo+i)).getItemNo()){
                bool flag=true;
                (*(productInfo+i)).setBool(flag);
                cout << "Please Enter Purchase Quantity Amount: ";
                cin >> purchaseQTY[i];
                 int qty=(*(productInfo+i)).getStockQuantity();
                
                 while((qty<purchaseQTY[i])||(purchaseQTY[i]<0)){//validation for quantity
                     cout<< "Invalid Quantity." << endl << "Please Enter A valid Purchase Quantity Amount: ";
                cin >> purchaseQTY[i];
                  
    //VALIDATION FOR BALANCE OVERDRAFT 
               }
               double itemTotal = (purchaseQTY[i]*(*(productInfo+i)).getPrice());
               total+= itemTotal;
               double creditCheck;
                creditCheck=(*(custId+findCustInfo(cID))).getlCredit();
                if (creditCheck<total){
                    cout << "Not enough credit to purchase item" << endl;
                    bool flag=false;
                    (*(productInfo+i)).setBool(flag);
                    purchaseQTY[i]=0;
                    total-=itemTotal;
                }
                int newStockQTY;
                newStockQTY = (*(productInfo+i)).getStockQuantity() - purchaseQTY[i];
                (*(productInfo+i)).setStockQuantity(newStockQTY);
                error1=true;
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
    Address * ap;
    ap =(*(custId+findCustInfo(cID))).getCusAddress();
     //RECIEPT
    cout <<"-------------------------------------------------------------------------" << endl;
    cout <<left << "B2B Shopping Cart" << endl;   
    cout <<"-------------------------------------------------------------------------" << endl; 
    cout <<left <<"Order Number: " << NumOrder <<endl;
    cout <<left <<"Associate: " << associate <<endl;
    cout <<left <<"Customer Number: "<< (*(custId+findCustInfo(cID))).getcusNum() << endl;
    cout <<left <<"Customer: " << (*(custId+findCustInfo(cID))).getcusName() << endl;
    cout <<left <<"Address: "; 
    ap->getAddress();
    cout << endl;
 
    cout <<setw(15) << "Item No " << setw(30) << "Description " << setw(20) << "Qty" << setw(20) << "Total" <<endl;
    cout <<"-------------------------------------------------------------------------" << endl; 
       
    while(choice2==false){ //creates output for final order summary
       int i=0;
       while(i<count){
          int num, qty;
          string descr;
          double p, pTotal;
            if((*(productInfo+i)).getBool()==true){
                num=(*(productInfo+i)).getItemNo();
                descr=(*(productInfo+i)).getDescription();
                p=(*(productInfo+i)).getPrice();
                qty=(*(productInfo+i)).getStockQuantity();
                pTotal=purchaseQTY[i]*p;
                 orderSummary<< fixed << setprecision(2) << num << " " << descr <<" "<<purchaseQTY[i]<<" $"<< pTotal<<endl; // needs setprecision[2]
                 cout << setw(15) << fixed << setprecision(2) << num << setw(30) << fixed<< descr <<setw(18) << fixed<<purchaseQTY[i]<<" $"<< pTotal <<endl;
        
                   }
            i++;
         }
         choice2=true; 
         double newCredit = (*(custId+findCustInfo(cID))).getlCredit() - total;
    (*(custId+findCustInfo(cID))).setlCredit(newCredit);                     
     cout <<"-------------------------------------------------------------------------" << endl; 
     orderSummary << "$" << total << endl; // prints total
     cout <<left << "Total" << setw(30) << fixed << setprecision(2) << "$" << total << endl;
     cout <<"-------------------------------------------------------------------------" << endl; 
     cout <<left << "Remaning Credit" << setw(10) << fixed << setprecision(2) << " " << newCredit << endl;
    }
    ofstream custEdit;
    custEdit.open("customers.dat");
      for(int q= 0; q< fileCount; q++){
        ap =(*(custId+q)).getCusAddress();
        
        custEdit << fixed << setprecision(2) << custId[q].getcusNum() << "|"
        << custId[q].getcusName()  << "|"
        << custId[q].getlCredit() << "|"
        << ap->getStreetAddress()  << ","
        << ap->getCity()  << ","
        << ap->getState()  << ","
        << ap->getZipCode();
        if (q<(fileCount-1))
            custEdit << endl;
    }
  invFile.open("inventory.dat");
        for(int p= 0; p< (fileCount-1); p++){
        invFile << fixed << setprecision(2) << (*(productInfo+p)).getItemNo()  << ","
         << (*(productInfo+p)).getDescription()  << ","
         << (*(productInfo+p)).getPrice()  << ","
         << (*(productInfo+p)).getStockQuantity();
         if (p<(fileCount-2))
             invFile << endl;
    }
 	return 0;
}
