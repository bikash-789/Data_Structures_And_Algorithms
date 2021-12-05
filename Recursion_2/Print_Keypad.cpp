/*
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.

Note : The order of strings are not important. Just print different strings in new lines.

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

void printKey(int num, string output)
{
    //base case
    if( num==0 || num == 1)
    {
        cout<<output<<endl;
        return;
    }

    //recursive call
    string codes[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    for(int i=0; i<codes[num%10].size(); i++)
    {
        printKey(num/10, codes[num%10][i]+output);
    }
}
void printKeypad(int num)
{
    printKey(num, "");
}
int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
