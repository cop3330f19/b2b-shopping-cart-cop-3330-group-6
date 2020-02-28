#include <ctime>
#include <sstream>
#include <iostream> 
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>
#include "Product.h"
#include "Address.h"
#include "Customer.h"
#include "StringHelper.h"

using namespace std;

//OBJECTS
Customer custId[fileCount];
Address addressId[fileCount];
Product prodId[fileCount];

//GLOBAL VARIABLES
//INCREASE FILE COMPACITY AS IT GROWS
int fileCount;
//ADDRESS
string addy, cust _streetAddress, _state, _zipCode, _addy;
//CUSTOMER
string CName, CNum;
double CreditL;

//MIRROR ADDRESS CLASS VECTOR 
vector<int> mAddress;
//ADDRESS VECTOR
vector<Address> addVec;

//GENERATE RANDOM ORDER NUM
string generateOrderNum(){ //orderSummary << generateOrderNum();
    time_t now = time(0);
    string oNum;
    stringstream strstream;
    strstream << now;
    strstream >> oNum;
    return oNum;
}
 //ALLOWS PROGRAM TO BE ABLE TO COUNT LINES IN THE FILES 
int countFileLines(string holder)
{
    int count;
   
    fstream inFile;
    infile.open(holder)
       while (getline(inFile, cust))  //creates a count of items to create pointer array
        count++;
    return count;
    
    infile.close();
    }

//ASSIGNS CUSTOMER ADDRESS DEPENDING ON THE INDEX 
void AddressVectorAssign(){
   for(int x=0; x < mAddress.size(); x++){
       vector<Address>::iterator addA= addVec.begin();
       advance(addA, mAddress[x]);
       custId[i].setCusAddress(&(*addA));
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
    
    for(int x=0; x< count; x++ ){
        getline(infile, cust);
        
        CNum=  StringHelper::parse(cust,'|')[0];
        CName= StringHelper::parse(cust,'|')[1];
        CreditL=stod(StringHelper::parse(cust,'|')[2]);
        _addy= StringHelper::parse(cust,'|')[3];
        _streetAddress= StringHelper::parse(addy,',')[0];
        _city= StringHelper::parse(addy,',')[1];
        _state= StringHelper::parse(addy,',')[2];
        _zipCode= StringHelper::parse(addy,',')[3];
        
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

getCustInfo(int id)
{
   for(int i=0; i < fileCount; i++)
   {
       if(custId[x].getcusNum(CNum) == id)
       {
          return i;
       }
       return -1;
            
          
    
}



int main(){
    int custIndex;
    string associate;
    int cID;
    //OPENS UP ORDER SUMMARY
    ofstream orderSummary;
    orderSummary.open("orderSummary.dat"); 
    int filecount = countFileLines("customer.dat")
        
    getCustumerInfo(fileCount,"customer.dat")
    orderSummary <<"Order Number: " << generateOrderNum()<<endl;
    string NumOrder= generateOrderNum();
 do{
    cout <<"Enter Associate's Name: "<<endl;
    cin >>associate;
    
    
    //CORPERATE NUM VALIDATION
   
 
  
    cout <<"Enter Customer ID:" <<endl;
      cin  >> cID;
      custIndex = getCustInfo(cid);
            }
    
if(custIndex == -1){
    cout << "Invalid Customer Id Number" << endl;
}
else
{
    custId[custIndex].getcusName()
}
//     int iNum, iQTY,count = 0, iNumChoice, j, itmcount;
//     double iPrice,total=0;
//     string iDescrip, holder1;
//     fstream invFile("inventory.dat");
    
//     while (getline(invFile, holder1)) { //creates a count of items to create pointer array
//         count++;
//     }
    
//     invFile.close();
//     invFile.clear();
//     invFile.open("inventory.dat");
    
//     Product *productInfo = new Product[count];  
    
//     j=0;
//     itmcount = 1;
//     while(getline(invFile,holder1)){ //pulls string from file
//         stringstream hold(holder1); //turns string into stream to allow parse
//     while(getline(hold,holder1,',')){ //parses stringstream
        
//         if (itmcount==4){
//             iQTY=atoi(holder1.c_str());
//             (*(productInfo+j)).setStockQuantity(iQTY);
//             itmcount = 1;
//             j++;
//         }
        
//         else if (itmcount==3){
//             iPrice=atof(holder1.c_str());
//             (*(productInfo+j)).setPrice(iPrice);
//             itmcount = 4;
//         }
        
//         else if (itmcount==2){
//             iDescrip=holder1;
//             (*(productInfo+j)).setDescription(iDescrip);
//             itmcount = 3;
//         }
        
//         else if (itmcount==1){
//             iNum=atoi(holder1.c_str());
//             (*(productInfo+j)).setItemNo(iNum);
//             itmcount = 2;
//         }
       
//     }
//     }
        
//     bool choice1=false, choice2=false, error1=false; // choice 1 and 2 are used for loop traps while error1 is used for validation of Product ID
//     int purchaseQTY[count];
    
//     for(int i=0; i<count; i++){ // displays all items and details
//         (*(productInfo+i)).printSummary();
//     }
    
    
//     while (choice1==false){ // item selection and quantity selection,to end loop user inputs 0
//         cout << "Please select the item(s) the customer wishes to purchase (Enter Item # shown above. Enter 0 when finished with order.)" << endl;
//         cin >> iNumChoice;
//         int i=0;
//         while (i<count){
//             if(iNumChoice==(*(productInfo+i)).getItemNo()){
//                 bool flag=true;
//                 (*(productInfo+i)).setBool(flag);
//                 cout << "Please Enter Purchase Quantity Amount: ";
//                 cin >> purchaseQTY[i];
//                 int qty=(*(productInfo+i)).getStockQuantity();
                
//                 while((qty<purchaseQTY[i])||(purchaseQTY[i]<0)){//validation for quantity
//                     cout<< "Invalid Quantity." << endl << "Please Enter A valid Purchase Quantity Amount: ";
//                 cin >> purchaseQTY[i];
//                    //VALIDATION FOR BALANCE OVERDRAFT 
//                 }
//                 total+= (purchaseQTY[i]*(*(productInfo+i)).getPrice());
//                 error1=true;
//             }
//             else if (iNumChoice==0){
//                 choice1=true;
//                 error1=true;
//             }
//             i++;
//         }
//         if (error1==false){
//             cout <<"Invalid Product ID" << endl;
//         }
        
//     }
    
//     invFile.close();
//     invFile.clear(); //closes and clears input file;
    
//          //RECIEPT
//     cout <<"-------------------------------------------------------------------------" << endl;
//     cout <<left << "B2B Shopping Cart" << endl;   
//     cout <<"-------------------------------------------------------------------------" << endl; 
//     cout <<left <<"Order Number: " << NumOrder <<endl;
//     cout <<left <<"Associate: " << <<endl;
//     cout <<left <<"Customer Number: "<< custId[custIndex].getcusNum()<<endl;
//     cout <<left <<"Address: "<< custId <<endl;
 
//     cout <<setw() << "Item No " << setw() << "Description " << setw() << "Qty" << setw() << "Total" <<endl;
//     cout <<"-------------------------------------------------------------------------" << endl; 
       
//     while(choice2==false){ //creates output for final order summary
//         int i=0;
//         while(i<count){
//             int num, qty;
//             string descr;
//             double p, pTotal;
//             if((*(productInfo+i)).getBool()==true){
//                 num=(*(productInfo+i)).getItemNo();
//                 desc=(*(productInfo+i)).getDescription();
//                 p=(*(productInfo+i)).getPrice();
//                 qty=(*(productInfo+i)).getStockQuantity();
//                 pTotal=purchaseQTY[i]*p;
//                 orderSummary << num << " " << descr <<" "<<purchaseQTY[i]<<" $"<< pTotal<<endl; // needs setprecision[2]
//                 cout << setw() << num << " " << descr <<" "<<purchaseQTY[i]<<" $"<< pTotal<<endl
           
                
//              }
//             i++;
//         }
//         choice2=true; 
//     }
//     cout <<"-------------------------------------------------------------------------" << endl; 
//     orderSummary << "$" << total << endl; // prints total
//     cout <<left << "Total" << setw() << "$" << total << endl;
//     cout <<"-------------------------------------------------------------------------" << endl; 
//     cout <<left << "Remaning Credit" << setw() << endl;*/
 	return 0;
}