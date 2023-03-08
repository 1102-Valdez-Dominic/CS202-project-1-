#ifndef MENUITEM_H
#define MENUITEM_H
#include <iostream>
using namespace std;
#define MAX_NUM_INGREDIENTS 50

class MenuItem{
    private: //will be protected for food/drink
        float cost;
        string itemName;
        int pointWorth;

    public:
        //constructors
        MenuItem();
        MenuItem(string, int, float);
        MenuItem(const MenuItem&);

        //methods
        float getCost();
        void setCost(float);
        string getItemName();
        void setItemName(string);
        int getPointWorth();
        void setPointWorth(int);

};
#endif