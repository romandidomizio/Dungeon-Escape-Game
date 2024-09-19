#include "Weapon.h"

Weapon::Weapon(string n, int s, int p,char sh)
{
    name = n;
    specialBonus = s;
    shortName = sh;
    price = p;
    count=0;
}
string Weapon::getName()
{
    return name;
}
int Weapon::getSpecialBonus()
{
    return specialBonus;
}
int Weapon::getPrice()
{
    return price;
}
char Weapon::getShortName()
{
    return shortName;
}
string Weapon::toString()
{
    string result = "";
    if (specialBonus > 0)
    {
        result += "(" + to_string(specialBonus) + ") ";
    }
    result += name + " [" + to_string(price) + " Gold]";
    return "";
}