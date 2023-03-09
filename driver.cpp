#include "customer.h"
#include <fstream>
#define MAX_NUM_CUSTOMERS 1000

int getLoyaltyDatabase(Customer *);
int getUserIntChoice();
void displayMemberJoin();
char getUserCharChoice();
void overwriteLoyaltyDatabase(Customer *, int);
Customer createCustomer();
int runLoyaltyProgram(Customer *, int &);
void displayPointRedemptionMenu();
void displayMenuItems();
void placeOrder(Customer customer);



int main(){
Customer customerArray[MAX_NUM_CUSTOMERS];
int numCustomers = 0;
int loyaltyProgram;

numCustomers = getLoyaltyDatabase(customerArray);

do{
    loyaltyProgram = runLoyaltyProgram(customerArray, numCustomers);
    cout << loyaltyProgram << endl;
    if(loyaltyProgram == -1){
        Customer customer;
        customer.setNumItemsInOrder(0);
        placeOrder(customer);
    }
    else if(loyaltyProgram == -2){
        break;
    }
    else{
        customerArray[loyaltyProgram].displayCustomerInformation();
        customerArray[loyaltyProgram].setNumItemsInOrder(0);
        placeOrder(customerArray[loyaltyProgram]);
    }

    overwriteLoyaltyDatabase(customerArray, numCustomers);

}while(loyaltyProgram != -2);

    return 0;
}

int getLoyaltyDatabase(Customer customerArray[MAX_NUM_CUSTOMERS]){
    string first, last;
    long int number, points;
    int count = 0;

    ifstream fin("loyalty.txt");
    if(fin.is_open()){
        //Note: order in file is different than contstructor
        while(fin >> number >> first >> last >> points){
            customerArray[count] = Customer(first, last, number, points);
            count++;
        }
    }
    else{
        cout << "cout not open file" << endl;
    }
    fin.close();

    return count;
}

int getUserIntChoice(){
    int userIntChoice;
    cin >> userIntChoice;
    return userIntChoice;
}

void displayMemberJoin(){
    cout << endl << endl << "Don't have a loyalty number?" << endl;
    cout << "Join today and earn a free large drink!" << endl;
    cout << "Being a member of the Meat Man Mob Loyalty Program provides the following benefits: " << endl;
    displayPointRedemptionMenu();
    cout << "Would you like to Join the Meat Man Mob Loyalty Program?(y/n) ";
}

char getUserCharChoice(){
    char userCharChoice;
    cin >> userCharChoice;
    return userCharChoice;
}

void overwriteLoyaltyDatabase(Customer customerArray[MAX_NUM_CUSTOMERS], int numCustomers){
    ofstream fout("loyalty.txt");
    if(fout.is_open()){
        for(int i = 0; i < numCustomers; i++){
            //just like getLoyaltyDatabase, values are scanned in different order than array
            fout << customerArray[i].getLoyaltyNumber() << " " << customerArray[i].getCustomerFirst() << " ";
            fout << customerArray[i].getCustomerFirst() << " " << customerArray[i].getNumberLoyaltyPoints() << endl;
        }
    }
    else{
        cout << "Could not open file" << endl;
    }

    fout.close();
}

Customer createCustomer(){
    cout << "Enrolling in the Meat Man Mob Loyalty Program is simple!" << endl;
    cout << "Just enter you 7 digit phone number without any dashes and your first and last name" << endl;
    cout << "For example: 1111111 Pete Wentz" << endl << endl;

    string first, last;
    long int number, points;
    points = 50; //default amount set 
    cin >> number >> first >> last;

    Customer newCustomer(first, last, number, points);

    return newCustomer;
}

int runLoyaltyProgram(Customer customerArray[MAX_NUM_CUSTOMERS], int &numCustomers){
    //Provides the logic for either adding a new customer to the database, or to enter their loyalty number 
    int userCharChoice;
    int userIntChoice;
    long int userLoyaltyNumber;
    int userIndex = 0;
    int programValue = 0;

    cout << "Welcome to Meaty Meat Man's Market!" << endl << endl;
    cout << "Are you a member of the Meat Man Mob Loyalty Program? (y/n) ";

    userCharChoice = getUserCharChoice();
    //exit option
    if(userCharChoice == 'e'){
        programValue = -2;
    }
    //Check if user has loyalty number
    else if(userCharChoice == 'y' || userCharChoice == 'Y'){
        cout << "Please enter your loyalty number: ";
        cin >> userLoyaltyNumber;
        cout << endl << endl << endl;
        //loop through data to find number
        for(int i = 0; i < MAX_NUM_CUSTOMERS; i++){
            if(customerArray[i].getLoyaltyNumber() == userLoyaltyNumber){
                    userIndex = i;
            }
            //once customer index is found break loop and continue
            break;
        }
        //match not found
        if(customerArray[userIndex].getLoyaltyNumber() != userLoyaltyNumber){
            //prompt user to become member
            do{
                displayMemberJoin();
                userCharChoice = getUserCharChoice();
                if(userCharChoice == 'y' || userCharChoice == 'Y'){
                    customerArray[numCustomers] = createCustomer();
                    numCustomers++;

                    programValue = numCustomers - 1;
                }
                else if(userCharChoice == 'n' || userCharChoice =='N'){
                    programValue = -1;
                }
            }while(userCharChoice != 'y' && userCharChoice != 'Y' && userCharChoice != 'n' && userCharChoice != 'N');
        }    
    }
    //user does not have loyalty number
    else if(userCharChoice == 'n' || userCharChoice == 'N'){
        //prompt user to become member
        do{
            displayMemberJoin();
            userCharChoice = getUserCharChoice();
            if(userCharChoice == 'y' || userCharChoice ==  'Y'){
                customerArray[numCustomers] = createCustomer();
                numCustomers++;
                programValue = numCustomers - 1;
            }
            else if(userCharChoice == 'n' || userCharChoice == 'N'){
                programValue = -1;
            }
        }while(userCharChoice != 'y' && userCharChoice != 'Y' && userCharChoice != 'n' && userCharChoice != 'N');
    }
    else{
        cout << endl << "Please enter a valid input" << endl;
    }
    //returns index(counter) of the customer in customer array if added to loyalty program, 
    //-1 otherwise
    return programValue;
}

void displayPointRedemptionMenu(){
    cout << "Being a member of the Meat Man Mob Loyalty Program provides the following benefits:" << endl;
    cout << "1.) Sandwich, 450 pts" << endl;
    cout << "2.) 32 oz. Drink, 50 pts" << endl;
    cout << "3.) Meat Man Meal, 500 pts" << endl;
    cout << "4.) Small Tater Tot, 75 pts" << endl;
}

void displayMenuItems(){
    cout << endl << "=====Meaty Meat Man's Restaurant Menu=====" << endl;
    cout << "1.) Smoked Meat Sandwich" << endl;
    cout << "2.) Meaty Meat Man Meal" << endl;
    cout << "3.) Fountain Drink" << endl;
    cout << "4.) Tater Tots" << endl;
    cout << "0.) Finish Order" << endl << endl;
    cout << "Please Enter a Value [0-4]: ";
}

void placeOrder(Customer customer){
    MenuItem menuItemArray[4];
    int item;
    //item 1 array index 0
    menuItemArray[0].setItemName("Smoked Meat Sandwich");
    menuItemArray[0].setCost(12.99);
    menuItemArray[0].setPointWorth(450);
    //item 2 array index 1
    menuItemArray[1].setItemName("Meaty Meat Man Meal");
    menuItemArray[1].setCost(15.99);
    menuItemArray[1].setPointWorth(500);
    //item 3 array index 2
    menuItemArray[2].setItemName("Fountain Drink");
    menuItemArray[2].setCost(2.99);
    menuItemArray[2].setPointWorth(50);
    //item 4 array index 3
    menuItemArray[3].setItemName("Tater Tots");
    menuItemArray[3].setCost(3.99);
    menuItemArray[3].setPointWorth(75);
    //add items to menu until 0
    do{
        displayMenuItems();
        cin >> item;
        switch(item){
            case 1:
                customer.addItemToOrder(&menuItemArray[0]);
                break;
            case 2:
                customer.addItemToOrder(&menuItemArray[1]);
                break;
            case 3:
                customer.addItemToOrder(&menuItemArray[2]);
                break;
            case 4:
                customer.addItemToOrder(&menuItemArray[3]);
                break;
            case 0:
                break;
            default:
                cout << "Please enter a valid value" << endl;
                break;
        };
    }while(item != 0);
    customer.displayOrder();
}