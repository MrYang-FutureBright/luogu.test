#include<iostream>
#include<queue>
using namespace std;
queue<int> q;
bool query(int x,queue<int> q)
{
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        if(k==x)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int M,N;
    cin>>M>>N;
    int count=0;//外查词典的次数
    int sum=0;//存入的单词个数
    int x;//单词
    while(N--)
    {
        cin>>x;
        if(query(x,q))
        {
            continue;
        }
        else
        {
            if(sum==M)
            {
                q.pop();
                q.push(x);
                count++;
                continue;
            }
            q.push(x);
            count++;
            sum++;
        }
    }
    cout<<count<<endl;
    return 0;
}