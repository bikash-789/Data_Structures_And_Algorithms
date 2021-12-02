/*

Given a string S, remove consecutive duplicates from it recursively.

Input Format :
String S

Output Format :
Output string

Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string

Sample Input 1 :
aabccba

Sample Output 1 :
abcba

Sample Input 2 :
xxxyyyzwwzzz

Sample Output 2 :
xyzwz

*/
#include <iostream>
using namespace std;

int len(char input[]){
    if(input[0]=='\0') return 0;
    int smallLen = len(input+1);
    return smallLen+1;
}
void removeConsecutiveDuplicates(char input[]){
    //base case
    if(len(input)==0||len(input)==1){
        return;
    }

    //recursive call
    removeConsecutiveDuplicates(input+1);

    //small calculation
    if(input[0]==input[1]){
        int lastPos = len(input);
        int i=1;
        while(i<=lastPos){
            input[i]=input[i+1];
            i++;
        }
        return;
    }
}
int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}