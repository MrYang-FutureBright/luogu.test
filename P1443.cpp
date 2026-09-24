#include<bits/stdc++.h>
using namespace std;
int arr[401][401];int a[401][401];

int main()
{
    for(int i=0;i<401;i++)
    {
        for(int j=0;j<401;j++)
        {
            a[i][j]=-1;
            arr[i][j]=-1;
        }
    }
    int n,m,x,y;
    int mrr[8]={1,1,2,2,-1,-1,-2,-2};
    int prr[8]={2,-2,1,-1,2,-2,1,-1};
    cin>>n>>m>>x>>y;
    queue<int>q1,q2;//行、列；
    q1.push(x);q2.push(y);
    a[x][y]=1;
    arr[x][y]=0;
    while(!q1.empty())
    {
        for(int i=0;i<8;i++)
        {
            int sx=q1.front()+mrr[i];
            int sy=q2.front()+prr[i];
            if(sx<=n&&sy<=m&&sx>0&&sy>0&&a[sx][sy]==-1)
            {
                a[sx][sy]=1;
                arr[sx][sy]=arr[q1.front()][q2.front()]+1;
                q1.push(sx);
                q2.push(sy);
            }
        }
        q1.pop();
        q2.pop();
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            printf("%d",arr[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}