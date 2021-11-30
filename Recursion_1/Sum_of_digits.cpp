/*
Write a recursive function that returns the sum of the digits of a given integer.

Input format :
Integer N

Output format :
Sum of digits of N

Constraints :
0 <= N <= 10^9

Sample Input 1 :
12345

Sample Output 1 :
15
*/

#include <iostream>
using namespace std;


int sumOfDigits(int n) {
    //base case
    if(n>=0 && n<=9){
        return n;
    }

    //recursive call
    int smallAns = sumOfDigits(n/10);

    //small calculation
    return smallAns+n%10;
}


int main() {
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;
}
