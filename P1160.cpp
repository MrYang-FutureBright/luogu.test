#include<iostream>
using namespace std;
const int m=1e5+10;
struct S{
    int l,r;
    int d;
}t[m]={0};
void add(int i,int k,int p)
{
    if(p==0)
    {
        t[i].r=k;
        t[i].l=t[k].l;
        t[t[k].l].r=i;
        t[k].l=i;
    }
    else
    {
        t[i].l=k;
        t[i].r=t[k].r;
        t[t[k].r].l=i;
        t[k].r=i;

    }
}
int main()
{
    int N;
    cin>>N;
    int k,p;
    t[0].r=0;
    t[0].l=0;
    add(1,0,1);
    for(int i=2;i<=N;i++)
    {
        cin>>k>>p;
        add(i,k,p);
    }
    int m,x;
    cin>>m;
    while(m--)
    {
        cin>>x;
        t[x].d=1;
    }
    for(int i=t[0].r;i;i=t[i].r)
    {
        if(t[i].d==0)
        {
            cout<<i<<' ';
        }
    }
    return 0;
}













// #include<iostream>
// using namespace std;
// struct stu{
//     int id;
//     stu* next;
// }st[100000];
// void del(int x)
// {

// }
// void insertl(int cur,int k)
// {
//     st[cur].next=&(st[k]);
// }
// void insertr(int cur,int k)
// {
//     st[k].next=&(st[cur]);
// }
// int main()
// {
//     int N;
//     stu* head;
//     for(int i=0;i<N;i++)
//     {
//         st[i].id=i+1;
//         st[i].next=NULL;
//     }
//     for(int i=0;i<N;i++)
//     {
//         int k,p;
//         cin>>k>>p;
//         if(p==0)
//         {
//             insertl(i,k);
//         }
//         else insertr(i,k);
//     }

// }