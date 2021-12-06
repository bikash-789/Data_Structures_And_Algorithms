/*
Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array.
But the order of elements should remain same as in the input array.

Note : The order of subsets are not important. Just print the subsets in different lines.

Input format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)

Constraints :
1 <= n <= 15

Sample Input:
3
15 20 12

Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12 
*/

#include <iostream>
using namespace std;

void printSubsetsOfArray(int input[], int length, int output[], int m)
{
    //base case
    if(length==0)
    {
        for(int i=0; i<m; i++)
        {
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    //copy all the elements from output array to a new array and append input[0] at last
    int *newArr = new int[m+1];
    int i=0;
    for(; i<m; i++){
        newArr[i] = output[i];
    }
    newArr[i] = input[0];

    //recursive call
    printSubsetsOfArray(input+1, length-1, newArr, m+1);
    printSubsetsOfArray(input+1, length-1, output, m);
}
void printSubsetsOfArray(int input[], int length)
{
    int *output = new int[1000000];
    printSubsetsOfArray(input, length, output, 0);
}

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
