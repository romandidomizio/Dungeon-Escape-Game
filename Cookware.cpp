#include "Cookware.h"

Cookware::Cookware(string n,int p,int bp,char s)
{
    name = n;
    breakProbability = bp;
    price = p;
    shortName = s;
    count=0;
}
string Cookware::getName()
{
    return name;
}
int Cookware::getbreakProbability()
{
    return breakProbability;
}
int Cookware::getPrice()
{
    return price;
}
char Cookware::getShortName()
{
    return shortName;
}
string Cookware::toString()
{
    string result = "";
    result += "(" + to_string(breakProbability) + "%) ";
    result += name + " [" + to_string(price) + " Gold]";
    return "";
}