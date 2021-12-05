#include <iostream>
#include <cmath>
using namespace std;

int subs(string input, string output[])
{
    //base case
    if(input.size()==0)
    {
        output[0]="";
        return 1;
    }

    //recursive call
    int smallOutput = subs(input.substr(1), output);

    //small calculation
    for(int i=0; i<smallOutput; i++)
    {
        output[i+smallOutput] = input[0] + output[i];
    }

    return 2*smallOutput;
}

int main()
{
    string input;
    cin>>input;

    int sizeOfSubSeq = pow(2, input.size());
    string *output = new string[sizeOfSubSeq];
    int ans = subs(input, output);

    for(int i=0; i<ans; i++)
    {
        cout<<output[i]<<endl;
    }

}