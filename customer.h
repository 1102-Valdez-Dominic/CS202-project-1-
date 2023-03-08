#ifndef CUSTOMER_H
#define CUSTOMER_H
#define MAX_SIZE_ORDER 50
#include <iostream>
#include <iomanip>
#include "menuItem.h"
using namespace std;

class Customer{
    private:
        string customerFirst, customerLast;
        long int loyaltyNumber, numberLoyaltyPoints;

    public:
        //constructors
        Customer();
        Customer(string, string, long int, long int);
        Customer(const Customer&);

        //methods
        string getCustomerFirst();
        void setCustomerFirst(string);
        string getCustomerLast();
        void setCustomerLast(string);
        long int getLoyaltyNumber();
        void setLoyaltyNumber(long int);
        long int getNumberLoyaltyPoints();
        void setNumberLoyaltyPoints(long int);

};
#endif