#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Monster{
    string name;
    int level;
    Monster(string n,int l)
    {
        name = n;
        level = l;
    }
};

class MonsterList{
 public:
    vector<Monster*> monsters;
    int currentLevel;
    MonsterList();
};

#endif