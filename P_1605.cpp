#include<iostream>
using namespace std;
int n,m,t;
int sx,sy,fx,fy;
bool obstacle[20][20];
bool visited[20][20];
int x[4]={0,0,-1,1};
int y[4]={1,-1,0,0};
int count=0;
void DFS(int xx,int yy)
{
    if(xx==fx&&yy==fy)
    {
        count++;
        return;
    }
    for(int i=0;i<4;i++)
    {
        int nx=xx+x[i];
        int ny=yy+y[i];
        if(nx>=1&&ny>=1&&nx<=n&&ny<=m)
        {
            if(!visited[nx][ny]&&!obstacle[nx][ny])
            {
                visited[nx][ny]=true;
                DFS(nx,ny);
                visited[nx][ny]=false;
            }
        }
    }
    return;
}
int main()
{
    cin>>n>>m>>t;
    cin>>sx>>sy>>fx>>fy;
    int px,py;
    for(int i=0;i<t;i++)
    {
        cin>>px>>py;
        obstacle[px][py]=true;
    }
    visited[sx][sy]=true;
    DFS(sx,sy);
    cout<<count<<endl;
    return 0;
}