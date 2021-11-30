/*

Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".

Constraints :
1 <= |S| <= 50

where |S| represents the length of string S. 

Sample Input 1 :
xpix

Sample Output :
x3.14x

Sample Input 2 :
pipi

Sample Output :
3.143.14

*/

#include <iostream>
using namespace std;

int len(char input[]){
    int i=0;
    while(input[i]!='\0'){
        i++;
    }
    return i;
}



void replacePi(char input[]){
    //base case
    if(len(input)==1){
        return;
    }

    //recursive call
    replacePi(input+1);

    //small calculation
    if(input[0]=='p' && input[1]=='i'){
        int lastpos=len(input)-1;
        while(lastpos>=2){
            input[lastpos+2] = input[lastpos];
            lastpos--;
        }
        input[0]='3';
        input[1]='.';
        input[2]='1';
        input[3]='4';
    }
}



int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
