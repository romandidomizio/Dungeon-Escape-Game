#ifndef RIDDLES_H
#define RIDDLES_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Riddle{
    string riddle;
    string ans;
    Riddle(string n,string ans)
    {
        riddle = n;
        ans = ans;
    }
};

class RiddleList{
 public:
    vector<Riddle*> riddles;
    RiddleList();
};

#endif