#include<iostream>
#include<queue>
using namespace std;
int N,A,B;
int a[210];
int b[210]={0};
queue<int> q1;
int main()
{
    cin>>N>>A>>B;
    for(int i=1;i<=N;i++)
    {
        cin>>a[i];
    }
    if(A==B)
    {
        cout<<0<<endl;
        return 0;
    }
    q1.push(A);
    b[A]=1;
    int mmin=0;
    while(++mmin)
    {
        int x=q1.size();
        if(x==0)
        {
            cout<<-1<<endl;
            return 0;
        }
        for(int i=1;i<=x;i++)
        {
            int q=q1.front();
            q1.pop();
            if(q+a[q]<=N)
            {
                if(!b[q+a[q]])
                {
                    if(q+a[q]==B)
                    {
                        cout<<mmin<<endl;
                        return 0;
                    }
                    q1.push(q+a[q]);
                    b[q+a[q]]=1;
                }
            }
            if(q-a[q]>=1)
            {
                if(!b[q-a[q]])
                {
                    if(q-a[q]==B)
                    {
                        cout<<mmin<<endl;
                        return 0;
                    }
                    q1.push(q-a[q]);
                    b[q-a[q]]=1;
                }
            }
        }
    }
}
