/*
Given a string S, find and return all the possible permutations of the input string.

Note 1 : The order of permutations is not important.

Note 2 : If original string contains duplicate characters, 
permutations will also be duplicates.

Input Format :
String S

Output Format :
All permutations (in different lines)

Sample Input :
abc

Sample Output :
abc
acb
bac
bca
cab
cba
*/

#include <iostream>
#include <string>
using namespace std;

int returnPermutations(string input, string output[])
{
    //base case
    if(input.size()==0)
    {
        output[0]="";
        return 1;
    }

    //recursive call
    string smOutput[10000];
    int smallOutput = returnPermutations(input.substr(1), smOutput);

    //small calculaion
    int k=0;
    for(int i=0; i<smallOutput; i++)
    {
        for(int j=0; j<=smOutput[i].size(); j++)
        {
            output[k++] = smOutput[i].substr(0, j)+input[0]+smOutput[i].substr(j);
        }
    }
    return k;
}

int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
