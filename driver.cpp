#include "customer.h"
#include <fstream>
#define MAX_NUM_CUSTOMERS 1000

int getLoyaltyDatabase(Customer*);
int getUserIntChoice();
void displayMemberJoin();
char getUserCharChoice();
void overwriteLoyaltyDatabase(Customer*, int);
Customer createCustomer();

int main(){
Customer customerArray[MAX_NUM_CUSTOMERS];
int numCustomers = 0;

    int userCharChoice;
    int userIntChoice;
    cout << "Welcome to Meaty Meat Man's Market!" << endl << endl;
    cout << "Are you a member of the Meat Man Mob Loyalty Program? (y/n) ";

    userCharChoice = getUserCharChoice();
    if(userCharChoice == 'y' || userCharChoice == 'Y'){

    }
    else if(userCharChoice == 'n' || userCharChoice == 'N'){
        displayMemberJoin();
        userCharChoice = getUserCharChoice();
        if(userCharChoice == 'y' || userCharChoice == 'Y'){
            //getloyaltydatabase to get count
            numCustomers = getLoyaltyDatabase(customerArray);
            cout << numCustomers << endl;
            customerArray[numCustomers] = createCustomer();
            numCustomers++;
            cout << "Please Enter a Value[0-4]: ";

            //add createCustomer(call) to end of array(counter/numItems)
            //next function call
            //"Welcome First Last!"
            //"You have 50 Loyalty Points."

            /************************************/
            //same as below
            do{
            //call order menu WITHOUT POINTS
            //prompt for int vales [0-4]
            userIntChoice = getUserIntChoice();
            if(userIntChoice > 4 || userIntChoice < 0){
                cout << "Invalid option entered.";
            }
                //prompt for int vales [0-4]
                //condition to stop loop != 0
            }while(userIntChoice != 0);
            //loops ends with condition != 0
            //back to Welcome screen (Welcome meaty meat)
        }
        else if(userCharChoice == 'n' || userCharChoice == 'N'){
            do{
            //call order menu WITHOUT POINTS
            //prompt for int vales [0-4]
            userIntChoice = getUserIntChoice();
            if(userIntChoice > 4 || userIntChoice < 0){
                cout << "Invalid option entered.";
            }
            else{
                //prompt for int vales [0-4]
                //condition to stop loop != 0
            }
            }while(userIntChoice != 0);
            //loops ends with condition != 0
            //back to Welcome screen (Welcome meaty meat)
        }
    }
    else{
        
    }

overwriteLoyaltyDatabase(customerArray, numCustomers);

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
    //call rewards menu

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
