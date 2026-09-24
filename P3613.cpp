#include<iostream>
#include<map>
using namespace std;
map<pair<int,int>,int> lock;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    while(q--)
    {
        int option;
        cin>>option;
        if(option==1)
        {
            int i,j,k;
            cin>>i>>j>>k;
            if(k==0)
            {
                lock.erase({i,j});
            }
            else lock[{i,j}]=k;
        }
        else if(option==2)
        {
            int i,j;
            cin>>i>>j;
            cout<<lock[{i,j}]<<endl;
        }
    }
    return 0;
}