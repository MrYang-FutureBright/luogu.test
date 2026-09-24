#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//为什么不能存字符而是存左括号的下标是因为刚开始不知道后面有没有对应的右括号
//因此在后面如果要撤销标记的话就找不到左括号在数组中对应的位置；

stack<int> a;//记录当前字符的下标;
char c[105];//记录字符需要补的对应字符；
int main()
{
    string s;
    cin>>s;
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        char ch=s[i];
        if(ch=='('||ch=='[')
        {
            a.push(i);
            if(ch=='(')
            {
                c[i]=')';
            }
            else c[i]=']';
        }
        else
        {
            if(ch==')')
            {
                if(!a.empty()&&s[a.top()]=='(')
                {
                    c[a.top()]=' ';
                    c[i]=' ';
                    a.pop();
                }
                else c[i]='(';
            }

            if(ch==']')
            {
                if(!a.empty()&&s[a.top()]=='[')
                {
                    c[a.top()]=' ';
                    a.pop();
                    c[i]=' ';
                }
                else c[i]='[';
            }
        }
    }
    for(int i=0;i<len;i++)
    {
        if(c[i]=='['||c[i]=='(')
        {
            cout<<c[i]<<s[i];
        }
        else if(c[i]==')'||c[i]==']')
        {
            cout<<s[i]<<c[i];
        }
        else cout<<s[i];
    }
    return 0;
} 