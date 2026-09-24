#include<iostream>
#include<cmath>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
int M;
const int MAXN=305;
const int INF =0x3f3f3f3f;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int mintime[MAXN][MAXN];
bool visited[400][400]={0};
struct Node {
    int x, y, time;
};
int main()
{
    //首先对坐标进行预处理，得出每个坐标被毁坏的最短时间；
    cin>>M;
    memset(mintime,0x3f,sizeof(mintime));//int四个字节都为0x3f则总大小为0x3f3f3f3f；
    for(int i=0;i<M;i++)
    {
        int x,y,t;
        cin>>x>>y>>t;
        mintime[x][y]=min(mintime[x][y],t);//格子正中
        for(int j=0;j<4;j++)//格子四周
        {
            int nx=x+dx[j];
            int ny=y+dy[j];
            if(nx>=0&&ny>=0)
            {
                mintime[nx][ny]=min(mintime[nx][ny],t);
            }
        }
    }
    if(mintime[0][0]<=0)//起始点开始时直接被破坏
    {
        cout<<-1<<endl;
        return 0;
    }
    queue<Node> q;
    q.push({0,0,0});
    visited[0][0]=true;
    while(!q.empty())
    {
        Node c=q.front();
        q.pop();
        //先判断再向四个方向移动；
        if(mintime[c.x][c.y]==INF)//到达安全位置
        {
            cout<<c.time<<endl;
            return 0;
        }
        //尝试向四个方向移动；
        for(int i=0;i<4;i++)
        {
            int nx=c.x+dx[i];
            int ny=c.y+dy[i];
            int next_time=c.time+1;
            //判断是否在第一象限 是否走过 是否此时流星没砸下来；
            if(nx>=0&&ny>=0&&!visited[nx][ny]&&next_time<mintime[nx][ny])
            {
                visited[nx][ny]=true;
                q.push({nx,ny,next_time});
            }
        }
    }
    //队列空了还没找到；
    cout<<-1<<endl;
    return 0;
}