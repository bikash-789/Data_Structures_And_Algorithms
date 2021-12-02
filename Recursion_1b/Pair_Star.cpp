/*
Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".

Input format :
String S

Output format :
Modified string

Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
hello

Sample Output 1:
hel*lo
*/

#include <iostream>
using namespace std;

int len(char input[]){
    //base case
    if(input[0]=='\0'){
        return 0;
    }

    //recursive call
    int smallLen = len(input+1);

    //small calculation
    return smallLen+1;
}
void pairStar(char input[]){
    //base case
    if(len(input)==1 || len(input)==0){
        return;
    }

    //recursive call
    pairStar(input+1);

    //small calculation
    if(input[0]==input[1]){
        int lastPos = len(input);
        while(lastPos>=1){
            input[lastPos+1] = input[lastPos];
            lastPos--;
        }
        input[1]='*';
    }
}

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
