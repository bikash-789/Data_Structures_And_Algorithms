//check for palindrome 
/*

Check whether a given String S is a palindrome using recursion. Return true or false.

Input Format :
String S

Output Format :
'true' or 'false'

Constraints :
0 <= |S| <= 1000

where |S| represents length of string S.

Sample Input 1 :
racecar

Sample Output 1:
true


*/
#include <iostream>
using namespace std;

bool helperFunc(char input[], int start, int end){
    //base case
    if(start==end){
        return true;
    }

    else if(input[start]!=input[end]){
        return false;
    }

    //recursive call
    bool smallAns = helperFunc(input, start+1, end-1);

    //small calculation
    return smallAns && input[start]==input[end];
}

bool checkPalindrome(char input[]){
    //calculate length of string
    int length_of_string = 0;
    while(input[length_of_string]!='\0'){
        length_of_string++;
    }
    return helperFunc(input, 0, length_of_string-1);
}
int main(){
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}