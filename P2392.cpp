#include<iostream>
using namespace std;
int a[70];int b[70];int c[70];int d[70];
int s1,s2,s3,s4;
int sum=0;
int max(int a,int b)
{
    return a>b?a:b;
}
int min(int a,int b)
{
    return a<b?a:b;
}
void dfs(int left,int right,int si,int count,int* p,int &time)
{
   if(count==si)
   {
        time=min(time,max(left,right));
        return;
   }
   dfs(left+p[count],right,si,count+1,p,time);
   dfs(left,right+p[count],si,count+1,p,time);
}
int main()
{
    cin>>s1>>s2>>s3>>s4;
    for(int i=0;i<s1;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<s2;i++)
    {
        cin>>b[i];
    }
    for(int i=0;i<s3;i++)
    {
        cin>>c[i];
    }
    for(int i=0;i<s4;i++)
    {
        cin>>d[i];
    }
    int time=1e9;
    dfs(0,0,s1,0,a,time);
    sum+=time;
    time=1e9;
    dfs(0,0,s2,0,b,time);
    sum+=time;
    time=1e9;
    dfs(0,0,s3,0,c,time);
    sum+=time;
    time=1e9;
    dfs(0,0,s4,0,d,time);
    sum+=time;
    cout<<sum<<endl;
}