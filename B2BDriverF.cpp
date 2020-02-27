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
    
    vector<Address> addressVec;
    addressVec.push_back();
    
    vector<Customer> custVec;
    
    
    int countC = 0;
    Address* addy= addressVec;
    Customer* cust= custVec;
    string holder2;
    fstream inFile("customer.dat");
     while (getline(inFile, holder2)) { //creates a count of items to create pointer array
        countC++;
    }
    
    inFile.close();
    inFile.clear();
    inFile.open("customer.dat");
    
    int c =0;
    string CNum,CName, Ccredit;
    while(getline(inFile,holder2)){ //pulls string from file
        stringstream hold(holder2); //turns string into stream to allow parse
    
    for(int x=1; x < 4; x++){
        (getline(hold,holder2,'|'))
        
        if(x==3){
            Ccredit=atof(holder2.c_str());
            (*(cust+c)).setlCredit(Ccredit);
           }
        else if(x==2){
            CName=(holder2.c_str());
            (*(cust+c)).setcusNum(CName);
         }
        else if(x==1){
            CNum= (holder2.c_str());
            (*(cust+c)).setcusNum(CNum);
         }           
                    
    }
    addressVec.push_back();        
    //string _streetAdd, _city, _state, _zipCode;     
    for(int x=1; x < 5; x++){
        (getline(hold,holder2,','))
        
        if(x==4){
         addressVec[c+1].setZipCode(holder2); 
        }
        else if(x==3){
        addressVec[c+1].setState(holder2);
        }
        else if(x==2){
        addressVec[c+1].setCity(holder2);    
        }
        else if(x==1){
        addressVec[c+1].setStreetAddress(holder2);     
        }   
    }  
   addy= addressVec[c+1];  
   cust->.setCusAddress(addy);
     
  //we then validate to see if the address the user has entered is the same as a pervious address we then delete it
  for(int i =0;i < c; i++)  {
      if(*(.getCusAddress)==addressVec[i]){
          addressVec.pop_back();
          c = addressVec[i];
      }
  }    
    }      
        
        
        
        
       
    int iNum, iQTY,count = 0, iNumChoice, j, itmcount;
    double iPrice,total=0;
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
                   //validation for balance overdraft
                }
                total+= (purchaseQTY[i]*(*(productInfo+i)).getPrice());
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
    
         //RECIEPT
    cout <<"-------------------------------------------------------------------------" << endl;
    cout <<left << "B2B Shopping Cart" << endl;   
    cout <<"-------------------------------------------------------------------------" << endl; 
    cout <<left <<"Order Number: " << right <<"get"  <<endl;
    cout <<left <<"Associate: " << right << "get"<<endl;
    cout <<left <<"Customer Number: "<< right <<"get"<<endl;
    cout <<left <<"Address: "<< right << "get" <<endl;
 
    cout <<setw() << "Item No " << setw() << "Description " << setw() << "Qty" << setw() << "Total" <<endl;
    cout <<"-------------------------------------------------------------------------" << endl; 
       
    while(choice2==false){ //creates output for final order summary
        int i=0;
        while(i<count){
            int num, qty;
            string descr;
            double p, pTotal;
            if((*(productInfo+i)).getBool()==true){
                num=(*(productInfo+i)).getItemNo();
                desc=(*(productInfo+i)).getDescription();
                p=(*(productInfo+i)).getPrice();
                qty=(*(productInfo+i)).getStockQuantity();
                pTotal=purchaseQTY[i]*p;
                orderSummary << num << " " << descr <<" "<<purchaseQTY[i]<<" $"<< pTotal<<endl; // needs setprecision[2]
                cout << setw() << num << " " << descr <<" "<<purchaseQTY[i]<<" $"<< pTotal<<endl
           
                
             }
            i++;
        }
        choice2=true; 
    }
    cout <<"-------------------------------------------------------------------------" << endl; 
    orderSummary << "$" << total << endl; // prints total
    cout <<left << "Total" << setw() << "$" << total << endl;
    cout <<"-------------------------------------------------------------------------" << endl; 
    Ccredit= Ccredit - total;
    cout <<left << "Remaning Credit" << setw() << "get"<< endl;
	return 0;
}

