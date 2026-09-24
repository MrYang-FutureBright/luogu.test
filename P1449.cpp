#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
    long long num=0;
    stack <long long> n;
    string ss;
    int key=0;
    if(!getline(cin,ss)) return 0;
    for(int i=0;ss[i]!='@';i++)
    {
        char ch=ss[i];
        if(ch>='0'&&ch<='9')
        {
            num=num*10+(ch-'0');
        }
        else if(ch=='.')
        {
            n.push(num);
            num=0;
            continue;
        }
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
        {
            int n2=n.top();n.pop();
            int n1=n.top();n.pop();
            if(ch=='+')
            {
                key=n1+n2;
                n.push(key);
            }
            if(ch=='-')
            {
                key=n1-n2;
                n.push(key);
            }
            if(ch=='*')
            {
                key=n1*n2;
                n.push(key);
            }
            if(ch=='/')
            {
                key=n1/n2;
                n.push(key);
            }
        }
    }
    cout<<n.top()<<endl;
    return 0;
}