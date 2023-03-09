#include "menuItem.h"

MenuItem::MenuItem(){
    cost = 0;
    itemName = "ITEM";
    pointWorth = 0;
}

MenuItem::MenuItem(string name, int ptWorth, float Cost){
    itemName = name;
    pointWorth = ptWorth;
    cost = Cost;
}

MenuItem::MenuItem(const MenuItem& original){
    itemName = original.itemName;
    pointWorth = original.pointWorth;
    cost = original.cost;
}

float MenuItem::getCost(){
    return cost;
}

void MenuItem::setCost(float Cost){
    cost = Cost;
}

string MenuItem::getItemName(){
    return itemName;
}

void MenuItem::setItemName(string name){
    itemName = name;
}

int MenuItem::getPointWorth(){
    return pointWorth;
}

void MenuItem::setPointWorth(int ptWorth){
    pointWorth = ptWorth;
}
