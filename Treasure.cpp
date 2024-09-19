#include "Treasure.h"

Treasure::Treasure(string n, int p,char s)
{
    name = n;
    price = p;
    shortName = s;
    count=0;
}
string Treasure::getName()
{
    return name;
}
int Treasure::getPrice()
{
    return price;
}
char Treasure::getShortName()
{
    return shortName;
}
string Treasure::toString()
{
    string result = "";
    result += name + " [" + to_string(price) + " Gold]";
    return "";
}