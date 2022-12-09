//Find a the common letter in each of the elves sacks
#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    ifstream rucksack;
    string elfOne;
    string elfTwo;
    string elfThree;
    int totalScore = 0;
    char commonItem;
    char priorityList [] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','x','z',
                          'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
   
    rucksack.open("rucksack.txt");
   
    while(rucksack >> elfOne){
        //Split the component in half
        rucksack >> elfTwo;
        rucksack >> elfThree;
         
        //Nested loop to find the common character
        for(int i = 0; i < elfOne.length(); i++)
        {
            for(int j = 0; j < elfTwo.length(); j++)
            {
                if(elfOne[i] == elfTwo[j])
                {
                    for(int k = 0; k < elfThree.length(); k++)
                    {
                        if(elfTwo[j] == elfThree[k])
                        {
                            commonItem = elfThree[k];
                            cout << elfOne[i] << " = " << elfTwo[j] << " = " << elfThree[k] << endl;
                        }
                    }
                }
            }
        }
        //Find item in priority list and add points
        for(int i = 0; i < sizeof(priorityList); i++)
        {
            if(commonItem == priorityList[i])
            {
                 totalScore += i+1;
                break;
            }
        }
    }
    cout << "Total Score: " << totalScore << endl;
}