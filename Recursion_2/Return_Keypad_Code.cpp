/*
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.

Note :
1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.

Input Format :
Integer n

Output Format :
All possible strings in different lines

Constraints :
1 <= n <= 10^6

Sample Input:
23

Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf

*/

#include <iostream>
#include <string>
using namespace std;

int keypad(int num, string output[])
{
    //base case
    if(num==0)
    {
        output[0] = "";
        return 1;
    }

    //recursive call
    int smallOutputSize = keypad(num/10, output);

    //small calculation
    string codes[] = {"","","abc", "def", "ghi", "jkl", "mno", "pqrs","tuv", "wxyz"};

    string inputStr = codes[num%10];
    for(int k=0; k<inputStr.size(); k++)
    {
        for(int i=0; i<smallOutputSize; i++)
        {
            output[smallOutputSize*k+i] = output[i];
        }
    }
    for(int k=0; k<inputStr.size(); k++)
    {
        for(int i=0; i<smallOutputSize; i++)
        {
            output[smallOutputSize*k+i] += inputStr[k];
        }
    }
    return smallOutputSize*inputStr.size();

}
int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
