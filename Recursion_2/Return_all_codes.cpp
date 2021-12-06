/*
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26.
You are given a numeric string S. Write a program to return the
list of all possible codes that can be generated from the given string.

Note : The order of codes are not important. And input string does not contain 0s.

Input format :
A numeric string

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

int getCodes(string input, string output[])
{
    //find the length of string
    int len = input.size();

    //base case
    if(len==0)
    {
        output[0]="";
        return 1;
    }
    

    //convert the first char into it's corresponding code
    int num = input[0]-48;
    char x = num+96;

    //recursive call
    int smallAns1 = getCodes(input.substr(1), output);

    for(int k = 0; k < smallAns1;k++)
        output[k]= x+output[k];
    
    int smallAns2=0;

    if(input[1]!='\0')
    {
        num = num*10 + input[1]-48;
        x = num+96;
        if(num>=10 && num<=26)
        {
            smallAns2 = getCodes(input.substr(2), output+smallAns1);
            for(int i=0; i<smallAns2; i++)
            {
                output[i+smallAns1] = x+output[i+smallAns1];
            }
        }
    }
    return smallAns1+smallAns2;
}

int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
