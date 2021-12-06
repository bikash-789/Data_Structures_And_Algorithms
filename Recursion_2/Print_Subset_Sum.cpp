/*
Given an array A and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array.
But the order of elements should remain same as in the input array.

Note : The order of subsets are not important. Just print them in different lines.

Input format :
Line 1 : Size of input array
Line 2 : Array elements separated by space
Line 3 : K 

Sample Input:
9 
5 12 3 17 1 18 15 3 17 
6

Sample Output:
3 3
5 1
*/

#include <iostream>
using namespace std;

void printSubsetSumToK(int input[], int length, int output[],int m,  int k)
{
    //base case
    if(length==0)
    {
        if(k==0){
            for(int i=0; i<m; i++)
            {
                cout<<output[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }

    //small calculation and recursive call
    int *newArr = new int[m+1];
    int i=0;
    for(; i<m; i++)
    {
        newArr[i] = output[i];
    }
    newArr[i] = input[0];
    printSubsetSumToK(input+1, length-1, newArr, m+1, k-input[0]);
    printSubsetSumToK(input+1, length-1, output, m, k);
    
}
void printSubsetSumToK(int input[], int length, int k)
{
    int *output = new int[10000];
    printSubsetSumToK(input, length, output, 0, k);
}

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
