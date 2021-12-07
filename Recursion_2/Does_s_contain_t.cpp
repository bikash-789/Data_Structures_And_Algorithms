#include <iostream>
using namespace std;

int findString(string s, string t)
{
    //base case
    if(t.length()==1)
    {
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]==t[0])
            {
                return i;
            }
        }
        return -1;
    }

    //recursive call
    int index=-1;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]==t[0])
        {
            index=i;
        break;
        }
    }
    if(index==-1)
    {
        return -1;
    }
    int smallAns = findString(s.substr(index+1), t.substr(1));
    return smallAns;
}

bool checkSequence(string s, string t)
{
    if(findString(s, t)==-1)
    {
        return false;
    }
    return true;
}

int main()
{
    string s, t;
    cin>>s;
    cin>>t;
    bool result = checkSequence(s, t);
    if(result) cout<<"true"<<endl;
    else cout<<"false"<<endl;
}