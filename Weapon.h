#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>
using namespace std;

class Weapon{
    string name;
    int specialBonus;
    int price;
    char shortName;
 public:
    int count;
    Weapon(string n,int s,int p,char sh);
    string getName();
    int getSpecialBonus();
    int getPrice();
    char getShortName();
    string toString();
};

#endif