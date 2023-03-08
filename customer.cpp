#include "customer.h"

Customer::Customer(){
    customerFirst = "FIRST";
    customerLast = "LAST";
    loyaltyNumber = 0;
    numberLoyaltyPoints = 9999;
}

Customer::Customer(string first, string last, long int number, long int points){
    customerFirst = first;
    customerLast = last;
    loyaltyNumber = number;
    numberLoyaltyPoints = points;
}

Customer::Customer(const Customer& oldCustomer){
    customerFirst = oldCustomer.customerFirst;
    customerLast = oldCustomer.customerLast;
    loyaltyNumber = oldCustomer.loyaltyNumber;
    numberLoyaltyPoints = oldCustomer.numberLoyaltyPoints;
}

string Customer::getCustomerFirst(){
    return customerFirst;
}

void Customer::setCustomerFirst(string first){
    customerFirst = first;
}

string Customer::getCustomerLast(){
    return customerLast;
}

void Customer::setCustomerLast(string last){
    customerLast = last;
}

long int Customer::getLoyaltyNumber(){
    return loyaltyNumber;
}

void Customer::setLoyaltyNumber(long int number){
    loyaltyNumber = number;
}

long int Customer::getNumberLoyaltyPoints(){
    return numberLoyaltyPoints;
}

void Customer::setNumberLoyaltyPoints(long int points){
    numberLoyaltyPoints = points;
}
