/*
Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
Do this recursively. Indexing in the array starts from 0.

Input Format :

Line 1 : An Integer N i.e. size of array

Line 2 : N integers which are elements of the array, separated by spaces

Line 3 : Integer x

Output Format :
indexes where x is present in the array (separated by space)

Constraints :
1 <= N <= 10^3

Sample Input :
5
9 8 10 8 8
8

Sample Output :
1 3 4


*/

#include<iostream>
using namespace std;


int allIndexes(int input[], int n, int x, int output[]){
    //base case
    if(n==0){
        return 0;
    }
    //recursive call
    int smallAns = allIndexes(input+1, n-1, x, output);

    //increase the output array values by one because it does not store actual location of num
    int i=0;
    while(i<smallAns){
        output[i]++;
        i++;
    }

    //small calculation
    if(input[0]==x){ //if first element is equal to x, shift all the elements in output array to right and insert index of first element at first in output array
        int size = smallAns-1;
        while(size>=0){
            output[size+1] = output[size];
            size--;
        }
        output[0] = 0;
        smallAns++;
    }
    return smallAns; //return size of output array
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    
}


