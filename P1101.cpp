#include<iostream>
#include<queue>
using namespace std;
int n;
int dirx[8]={-1,-1,0,1,1,1,0,-1};
int diry[8]={0,1,1,1,0,-1,-1,-1};
struct Node{
    int x,y;//当前坐标
    int index;//当前匹配的下标，如果等于六记录整条路径
    int dr,dc;//移动方向
    vector<pair<int,int>> path;//记录移动路径
};
int main()
{
    cin>>n;
    vector <string> s(n);
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    string key="yizhong";
    vector<vector<bool>> keep(n,vector<bool>(n,false));//动态二维数组，用来判断哪些坐标可以输出英文字母；
    queue<Node> q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(s[i][j]=='y')//找到目标序列的第一个y
            {
                for(int d=0;d<8;d++)
                {
                    int tx=i+dirx[d];
                    int ty=j+diry[d];
                    if(tx>=0&&ty>=0&&tx<n&&ty<n&&s[tx][ty]=='i')
                    {
                        q.push({tx,ty,1,dirx[d],diry[d],{{i,j},{tx,ty}}});
                    }
                }
                while(!q.empty())
                {
                    Node curr=q.front();
                    q.pop();
                    if(curr.index==6)
                    {
                        for(auto& p : curr.path)
                        {
                            keep[p.first][p.second]=true;
                        }
                        continue;
                    }
                    int tx=curr.x+curr.dr;
                    int ty=curr.y+curr.dc;
                    int tidex=curr.index+1;
                    if(tx>=0&&ty>=0&&tx<n&&ty<n&&s[tx][ty]==key[tidex])
                    {
                        vector<pair<int,int>> tpath=curr.path;
                        tpath.push_back({tx,ty});
                        q.push({tx,ty,tidex,curr.dr,curr.dc,tpath});
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(keep[i][j]==false)
            {
                cout<<'*';
            }
            else cout<<s[i][j];
        }
        cout<<endl;
    }
    return 0;
}