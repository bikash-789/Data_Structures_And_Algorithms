/*
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. 
You are given a numeric string S. Write a program to print the 
list of all possible codes that can be generated from the given string.

Note : The order of codes are not important. Just print them in different lines.

Input format :
A numeric string S

Output Format :
All possible codes in different lines

Constraints :
1 <= Length of String S <= 10

Sample Input:
1123

Sample Output:
aabc
kbc
alc
aaw
kw
*/

#include <iostream>
using namespace std;

void printAllPossibleCodes(string input, string output)
{
    //base case
    int len = input.size();
    if(len==0)
    {
        cout<<output<<endl;
        return;
    }

    //recursive call
    int num=input[0]-48;
    char x = num+96;
    printAllPossibleCodes(input.substr(1), output+x);

    if(input[1]!='\0')
    {
        num=num*10+input[1]-48;
        x=num+96;
        if(num>=10 && num<=26)
        {
            printAllPossibleCodes(input.substr(2), output+x);
        }
    }
}
void printAllPossibleCodes(string input)
{
    printAllPossibleCodes(input, "");
}

int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
