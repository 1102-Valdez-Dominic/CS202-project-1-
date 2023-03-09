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

MenuItem* Customer::getCurrentOrder(){
    return currentOrder;
}

void Customer::addItemToOrder(MenuItem *newItem){
    //Adds the new menuItem to the end of the order array and increments the number of items
    //item array has all values of menuItem, cost, name, pts
    if(numItemsInOrder < MAX_SIZE_ORDER){
        currentOrder[numItemsInOrder] = *newItem;
        numItemsInOrder++;
    }
}

int Customer::getNumItemsInOrder(){
    return numItemsInOrder;
}

void Customer::setNumItemsInOrder(int numItems){
    numItemsInOrder = numItems;
}

float Customer::calculateCost(){
    float tax = .0827;
    float total = 0;
    float cost = 0;
    
    for(int i = 0; i < numItemsInOrder; i++){
        cost = currentOrder[i].getCost();
        //sum items cost together
        total += cost;
    }
    total = total - (total * tax);

    return total;
}

void Customer::displayOrder(){
    float total = 0;
    float userPayment = 0;
    float userChange = 0;
    total = calculateCost();

    cout << "=====Your Order=====" << endl;
    for(int i = 0; i < numItemsInOrder; i++){
        cout << currentOrder[i].getItemName() << " ";
        cout << currentOrder[i].getCost() << endl;
    }
    cout << "Your Total Today Is: $";
    cout << fixed <<  setprecision(2) << total;
    cout << endl << endl << endl << endl;
    do{
        cout << "Please enter the amount you'd like to pay with: $";
        cin >> userPayment;
        
        userChange = userPayment - total;
        if(userChange > 0){
            cout << "Your change today is: $";
            cout << fixed <<  setprecision(2) << userChange << endl;
            cout << "Have a nice day, and thank you for choosing Meaty Meat Man's Market!";
            cout << endl << endl << endl << endl << endl << endl;
        }
        else if(userChange < 0){
            cout << "Insufficient Funds, Trying Again..." << endl << endl << endl;
        }
    }while(userChange < 0);
}

void Customer::displayCustomerInformation(){
    cout << "Welcome " << customerFirst << " " << customerLast << "!" << endl;
    cout << "You have " << numberLoyaltyPoints << " Loyalty Points." << endl << endl;
}