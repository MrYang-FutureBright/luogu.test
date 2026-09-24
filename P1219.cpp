#include<iostream>
#include<vector>
using namespace std;
int n;
int count=0;
vector<int>queen(13);
bool determain(int row,int col)
{
    for(int i=0;i<row;i++)
    {
        if(queen[i]==col||abs(row-i)==abs(col-queen[i]))
        {
            return false;
        }
    }
    return true;
}
void solve(int row)
{
    
    for(int col=0;col<n;col++)
    {
        if(row==n)
        {
            count++;
            if(count<=3)
            {
                for(int i=0;i<n;i++)
                {
                    cout<<queen[i]+1<<' ';
                }
                cout<<'\n';
            }
            return;
        }
        if(determain(row,col))
        {
            queen[row]=col;
            solve(row+1);
            queen[row]=-1;
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        queen[i]=-1;
    }
    solve(0);
    cout<<count<<endl;
    return 0;
}