/*
Given an input string (STR), print all possible permutations of the input string.

Note:
The input string may contain the same characters, so there will also be the same permutations.
The order of permutations doesn’t matter.

Input Format:
The only input line contains a string (STR) of alphabets in lower case

Output Format:
Print each permutations in a new line

Note:
You do not need to print anything, it has already been taken care of.
Just implement the function.  

Constraint:
1<=length of STR<=8
Time Limit: 1sec

Sample Input 1:
cba

Sample Output 1:
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

void printPermutations(string input, string output)
{
    //base case
    if(input.size()==0)
    {
        cout<<output<<endl;
        return;
    }

    //recursive call
    for(int i=0;i<input.size();i++)
    {
        printPermutations(input.substr(1),output+input[0]);
        rotate(input.begin(),input.begin()+1,input.end());
    }
}
void printPermutations(string input)
{
    printPermutations(input, "");
}

int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}