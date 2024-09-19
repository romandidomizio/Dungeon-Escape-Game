#ifndef TREASURE_H
#define TREASURE_H

#include <iostream>
#include <string>
using namespace std;

class Treasure{
    string name;
    int price;
    char shortName;
 public:
    int count;
    Treasure(string n,int p,char s);
    string getName();
    int getPrice();
    char getShortName();
    string toString();
};

#endif