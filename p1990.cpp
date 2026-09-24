#include<iostream>
using namespace std;
const int MAXN=1000002;
const int mol=10000;
int f[MAXN];//f[n]=f[n-1]+f[n-2]+2*g[n-2];
int g[MAXN];//g[n-2]=f[n-3]+g[n-3];g[n]=g[n-1]+f[n-1];
int main()
{
    int n;//f[n]表示填满前n*2面积的方法数；
    cin>>n;//g[n]表示填满前2*(n+1)面积的墙且第n+1行有一个格子已经被填的方法数
    g[0]=0;
    g[1]=1;
    f[1]=f[0]=1;//f[0]表示只有一种方法即什么都不做；
    for(int i=2;i<=n;i++)
    {
        g[i]=(f[i-1]+g[i-1])%mol;
        f[i]=(f[i-1]+f[i-2]+2*g[i-2])%10000;
    }
    cout<<f[n]%mol;
}