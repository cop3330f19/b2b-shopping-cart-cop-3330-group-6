/*
File Name: Product.cpp
Group Number: 6
Members: Michael Parrish, Janei Elliston, Racaria Burgess, Michael Mondelice
Recent Edit Date: 2/26/2020
*/
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "Product.h"

using namespace std;

Product::Product(){
    itemNo=0;
    description="";
    price=0;
    stockQuantity=0;
    selection=false;
}
Product::Product(int itemNum,string itemDesc,double itemPrice,int itemQTY,bool select){
    itemNo=itemNum;
    description=itemDesc;
    price=itemPrice;
    stockQuantity=itemQTY;
    selection=select;
}
void Product::setItemNo(int itemNum){
    itemNo=itemNum;
}
int Product::getItemNo(){
    return itemNo;
}
void Product::setDescription(string itemDesc){
    description=itemDesc;
}
string Product::getDescription(){
    return description;
}
void Product::setPrice(double itemPrice){
    price=itemPrice;
}
double Product::getPrice(){
    return price;
}
void Product::setStockQuantity(int itemQTY){
    stockQuantity=itemQTY;
}
int Product::getStockQuantity(){
    return stockQuantity;
}
void Product::printSummary(){
    cout << getItemNo() << "|" << getDescription() << "|QTY: " << getStockQuantity() <<"|PricePerUnit: $"<<getPrice() << endl;
}
void Product::setBool(bool selec){
    selection=selec;
}
bool Product::getBool(){
    return selection;
}
