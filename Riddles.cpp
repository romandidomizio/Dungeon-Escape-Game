#include "Riddles.h"

RiddleList::RiddleList()
{
    string line,riddle="",ans="";
    int count;
    ifstream myfile ("riddles.txt");
    while(getline(myfile,line))
    {
        riddle="",ans="";
        for(int i=0;i<line.length();i++)
        {
            if(line.at(i)=='~')
            {
                count=i+1;
                break;
            }
            riddle+=line.at(i);
        }
        for(int i=count;i<line.length();i++)
        {
            ans+=line.at(i); 
        }
        riddles.push_back(new Riddle(riddle,ans));
    }
    myfile.close();
}