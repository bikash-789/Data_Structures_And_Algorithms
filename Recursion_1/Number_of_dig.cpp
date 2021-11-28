/*
Given the code to find out and return the number of digits present in a number recursively. But it contains few bugs, that you need to rectify such that all the test cases should pass.

Input Format :
Integer n

Output Format :
Count of digits

Constraints :
1 <= n <= 10^6

Sample Input 1 :
 156
Sample Output 1 :
 3

*/

#include<iostream>
using namespace std;

int count(int num){
    //base case
    if(num>=1 && num<=9){
        return 1;
    }

    //recursive call
    int small_ans = count(num/10);

    //small calculation
    return small_ans+1;
}

int main(){
    int n;
    cin >> n;
  
    cout << count(n) << endl;
}


