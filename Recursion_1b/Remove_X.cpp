/*

Given a string, compute recursively a new string where all 'x' chars have been removed.

Input format :
String S

Output format :
Modified String

Constraints :
1 <= |S| <= 10^3

where |S| represents the length of string S. 

Sample Input 1 :
xaxb

Sample Output 1:
ab

Sample Input 2 :
abc

Sample Output 2:
abc


*/

#include <iostream>
using namespace std;


int len(char input[]){
    int i=0;
    while(input[i]!='\0') i++;
    return i;
}

void removeX(char input[]){
    //base case
    if(len(input)==1 && input[0]!='x'){
        return;
    }

    //recursive call
    removeX(input+1);

    //small calculation
    if(input[0]=='x'){
        int lastpos=len(input);
        int i=1;
        while(i<lastpos){
            input[i-1]=input[i];
            i++;
        }
        input[lastpos-1] = '\0';
    }
}

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
