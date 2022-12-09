//Find a the common letter in each of the compartment halves
#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    ifstream rucksack;
    string component;
    string firstHalf;
    string secondHalf;
    int  totalScore = 0;
    char commonItem;
    char priorityList [] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','x','z',
                          'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
   
    rucksack.open("rucksack.txt");
   
    while(rucksack >> component){
       // cout << component << endl;
        firstHalf = component.substr(0, component.length()/2);
        secondHalf = component.substr(component.length()/2);
        //cout << firstHalf << " " << secondHalf << endl;
       
        //Nested loop to find the common character
        for(int i = 0; i < firstHalf.length(); i++)
        {
            for(int j = 0; j < secondHalf.length(); j++)
            {
                if(firstHalf[i] == secondHalf[j])
                {
                    commonItem = firstHalf[i];
                }
            }
         
        }
        //Find item in priority list and add point
        for(int i = 0; i < sizeof(priorityList); i++)
        {
            if(commonItem == priorityList[i])
            {
                totalScore += i+1;
                break;
            }
        }
    }
    cout << "Total Score: " << totalScore;
}
