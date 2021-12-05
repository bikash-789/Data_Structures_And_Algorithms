#include <iostream>
#include <cstring>
using namespace std;


void subs(string input, string output)
{
    //base case
    if(input.size()==0)
    {
        cout<<output<<endl;
        return;
    }
    //recursive call
    subs(input.substr(1), output);
    subs(input.substr(1), output+input[0]);

}

int main()
{
    string input;
    cin>>input;
    subs(input, "");

}