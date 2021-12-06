/*
Given an array A of size n and an integer K, return all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.

Note : The order of subsets are not important.

Input format :
Line 1 : Integer n, Size of input array
Line 2 : Array elements separated by space
Line 3 : K 

Constraints :
1 <= n <= 20

Sample Input :
9 
5 12 3 17 1 18 15 3 17 
6

Sample Output :
3 3
5 1
*/

#include <iostream>
using namespace std;

int subsetSumToK(int input[], int length, int output[][50], int k)
{
    //base case
    if(length==0)
    {
        if(k==0)
        {
            output[0][0] = 0;
            return 1;
        }
        else{
            return 0;
        }
    }

    //recursive call

    //do not include first element
    int ans1 = subsetSumToK(input+1, length-1, output, k);

    //include first element
    int ans2 = subsetSumToK(input+1, length-1, output+ans1, k-input[0]);

    int i=ans1;
    int smallOutputSize = ans1+ans2;

    for(;i<smallOutputSize; i++)
    {
        int lastPos = output[i][0];
        while(lastPos>=1)
        {
            output[i][lastPos+1] = output[i][lastPos];
            lastPos--;
        }
        output[i][1] = input[0];
        output[i][0]++;
    }

    return smallOutputSize;
}

int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
