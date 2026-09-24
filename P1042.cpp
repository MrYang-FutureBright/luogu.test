#include<bits/stdc++.h>
using namespace std;
string s;
char ch;
void solve(int k)
{
    int count1=0;
    int count2=0;
   for(char qh:s)
   {
    if(qh=='W')
    {
        count1++;
    }
    else if(qh=='L')
    {
        count2++;
    }
    if(max(count1,count2)>=k&&abs(count1-count2)>=2)
    {
        cout<<count1<<':'<<count2<<endl;
        count1=count2=0;
    }
   }
   cout<<count1<<':'<<count2<<endl;
   cout<<endl;
}
int main()
{
    while(cin>>ch&&ch!='E') s+=ch;
    solve(11);solve(21);
    return 0;
}