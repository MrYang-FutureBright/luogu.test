#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct passenger{
    int time;
    int nation;

};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    queue<passenger> q;
    vector<int> cnt(300005,0);
    int count=0;
    for(int i=0;i<n;i++)
    {
        int t,k;
        cin>>t>>k;
        for(int j=0;j<k;j++)
        {
            int x;
            cin>>x;
            if(cnt[x]==0)
            {
                count++;
            }
            cnt[x]++;
            q.push({.time=t,.nation=x});
        }
        while(!q.empty()&&t-q.front().time>=86400)
        {
            int oldnation=q.front().nation;
            q.pop();
            cnt[oldnation]--;
            if(cnt[oldnation]==0)
            {
                count--;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}