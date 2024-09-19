#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <vector>
#include "Cookware.h"
#include "Treasure.h"
#include "Weapon.h"
#include "Cookware.cpp"
#include "Treasure.cpp"
#include "Weapon.cpp"
using namespace std;

struct Companion{
    string name;
    int fullness;
    Companion(string n)
    {
        name = n;
        fullness = 50;
    }
};

class Player{
    string name;
    int gold;
    int ingredients;
    int armor;
    int fullness;
    int keys;
    Weapon* weapons[5];
    Treasure* treasures[5];
    Cookware* cookware[3];
    int numberOfCompanions;
 public:
    vector<Companion*> companions;
    int roomsCleared;
    Player();
    void buyCookware(int cw,int amount);
    void buyIngredients(int amount);
    void buyWeapon(int w,int amount);
    void buyArmor(int amount);
    int getKey();
    void hunger();
    int getRooms();
    int getFullness();
    void killCompanion();
    void roomCleared();
    void addTreasure();
    void addKey();
    void useKey();
    void sellTreasure();
    bool attackEnemy(int challengeRating);
    void cookMeal();
    void surrender();
    void move();
    void inventory();
    void companionStatus();
    void misfortune();
};

#endif