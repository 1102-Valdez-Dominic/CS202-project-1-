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
        MenuItem currentOrder[MAX_SIZE_ORDER];
        int numItemsInOrder;
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

        MenuItem* getCurrentOrder();
        void addItemToOrder(MenuItem*);
        int getNumItemsInOrder();
        void setNumItemsInOrder(int);
        float calculateCost();
        void displayOrder();
        void displayCustomerInformation();
};
#endif