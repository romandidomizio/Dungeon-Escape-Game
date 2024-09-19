#ifndef COOKWARE_H
#define COOKWARE_H

#include <iostream>
#include <string>
using namespace std;

class Cookware{
    string name;
    int price;
    int breakProbability;
    char shortName;
 public:
    int count;
    Cookware(string n,int p,int bp,char s);
    string getName();
    int getbreakProbability();
    int getPrice();
    char getShortName();
    string toString();
};

#endif