/*

Write a recursive function to convert a 
given string into the number it represents. 
That is input will be a numeric string that 
contains only numbers, you need to convert the 
string into corresponding integer and return the answer.

Input format :
Numeric string S (string, Eg. "1234")

Output format :
Corresponding integer N (int, Eg. 1234)

Constraints :
0 <= |S| <= 9
where |S| represents length of string S.

Sample Input 1 :
00001231

Sample Output 1 :
1231


*/

#include <iostream>
#include <cmath>
using namespace std;

int len(char input[]){
    int i=0;
    while(input[i]!='\0'){
        i++;
    }
    return i;
}


int stringToNumber(char input[]){
    //base case
    if(len(input)==1){
        return input[0]-48;
    }

    //recursive call
    int smallAns = stringToNumber(input+1);

    //small calculation
    int b=input[0]-48;
    int length = len(input);
    return b*pow(10, length-1)+smallAns;
}

int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
