/*
Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.

Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)

Output format :
Array elements in increasing order (separated by space)

Constraints :
1 <= n <= 10^3

Sample Input 1 :
6 
2 6 8 5 4 3

Sample Output 1 :
2 3 4 5 6 8
*/

#include <iostream>
using namespace std;

void merge(int input[], int startIn, int endIn){
    //find the mid element
    int mid = (startIn+endIn)/2;

    //create a new array of size endIn-startIn+1
    int *newArr = new int[endIn-startIn+1];

    int i=startIn, j=mid+1, k=0;

    while(i<=mid && j<=endIn){
        if(input[i]<input[j]){
            newArr[k++]=input[i++];
        }
        else newArr[k++]=input[j++];
    }

    while(i<=mid){
        newArr[k++]=input[i++];
    }
    while(j<=endIn){
        newArr[k++]=input[j++];
    }

    //copy all sorted elements from newArr to input array
    i=startIn;
    while(i<=endIn){
        input[i]=newArr[i-startIn];
        i++;
    }

    //delete the new array
    delete []newArr;
}
void merge_sort(int input[], int startIn, int endIn){
    //base case
    if(startIn>=endIn){
        return;
    }

    //find mid element
    int mid = (startIn+endIn)/2;

    //recursive call on first half
    merge_sort(input, startIn, mid);
    
    //recursive call on second half
    merge_sort(input, mid+1, endIn);

    //merge two sorted arrays
    merge(input, startIn, endIn);
}
void mergeSort(int input[], int length){
    merge_sort(input, 0, length-1);
}
int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}