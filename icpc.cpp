#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    char s[10005];int count=0;int m=n;
    if(n%4==0&&(n-k)%4==0)
    {
        while(m!=0)
    {
        s[count]='1';++count;
        s[count]='2';++count;
        s[count]='3';++count;
        s[count]='4';++count;
        m=m-4;
    }
    cout<<s;
    }
    else cout<<-1;
    return 0;
}