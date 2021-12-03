/*
Sort an array A using Quick Sort.
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
#include<iostream>
using namespace std;

int partition(int input[], int startIn, int endIn)
{
    int less_than_first=0, i=startIn+1,j=endIn;
    //count all elements which are less than first element
    while(i<=endIn)
    {
        if(input[i]<=input[startIn])
        {
            less_than_first++;
        }
        i++;
    }

    //replace the element at pIndex with first element
    int pIndex = startIn+less_than_first;
    int first_elem = input[startIn];
    input[startIn]=input[pIndex];
    input[pIndex] = first_elem;

    //now move all elements to left which are less than
    //element at pIndex and elements to right which are greater
    i=startIn;
    while(i<pIndex && j>pIndex)
    {
        while(input[i]<=first_elem)
        {
            i++;
        }

        while(input[j]>first_elem)
        {
            j--;
        }

        if(i<pIndex && j>pIndex)
        {
            int temp = input[i];
            input[i] = input[j];
            input[j] = temp;
            i++;
            j--;
        }
    }

    //return the pivot index 
    return pIndex;
}

void qs(int input[], int startIn, int endIn)
{
    //base case
    if(startIn>=endIn)
    {
        return;
    }

    //find partition element index
    int p = partition(input, startIn, endIn);

    //recursive call
    qs(input, startIn, p-1);
    qs(input, p+1, endIn);
}

void quickSort(int input[], int n)
{
    qs(input, 0, n-1);
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


