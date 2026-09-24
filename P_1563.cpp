#include<iostream>
using namespace std;
int a[100005];//小人朝向
string s[100005];//小人名字
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    int d,k;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>s[i];
    }
    int key=0;
    for(int i=0;i<m;i++)
    {
        cin>>d>>k;
        if(d==a[key])
        {
            key=(key-k%n+n)%n;
        }
        else key=(key+k%n)%n;
    }
    cout<<s[key];
}