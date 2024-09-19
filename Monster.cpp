#include "Monster.h"

MonsterList::MonsterList()
{
    string line,name="",level="";
    ifstream myfile ("monsters.txt");
    while(getline(myfile,line))
    {
        name="",level="";
        for(int i=0;i<line.length();i++)
        {
            if(line.at(i) == ',')
            {
                level = line.at(i+1);
                break;
            }
            name+=line.at(i);
        }
        monsters.push_back(new Monster(name,stoi(level)));
    }
    currentLevel = 1;
    myfile.close();
}