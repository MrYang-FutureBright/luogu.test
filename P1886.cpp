// #include<iostream>
// #include<vector>
// #include<queue>
// using namespace std;
// vector<int>arr(1000000);
// int a[1000000];
// int b[1000000];
// queue<int> q;
// long long int N,K;
// int main()
// {
//     cin>>N>>K;
//     int max=arr[0];
//     int min=arr[0];
//     for(int i=0;i<N;i++)
//     {
//         cin>>arr[i];
//     }
//     for(int i=0;i<K;i++)
//     {
//         if(arr[i]>max)
//         {
//             max=arr[i];
//         }
//         if(arr[i]<min)
//         {
//             min=arr[i];
//         }
//         q.push(arr[i]);
//     }
//     a[0]=max;
//     b[0]=min;
//     for(int i=0;i<N-K;i++)
//     {
//         int temp=arr[i+K];
//         if(temp>max)
//         {
//             max=temp;
//         }
//         if(temp<min)
//         {
//             min=temp;
//         }
//         q.pop();
//         q.push(temp);
//         a[i+1]=max;
//         b[i+1]=min;
//     }
//     for(int i=0;i<=N-K;i++)
//     {
//         cout<<b[i]<<' ';
//     }
//     cout<<endl;
//     for(int i=0;i<=N-K;i++)
//     {
//         cout<<a[i]<<' ';
//     }
//     return 0;
// }
#include<iostream>
#include<deque>
using namespace std;
int n,k;
int arr[1000000];
void solve(bool find_min)
{
    deque<int> dq;
    for(int i=0;i<n;i++)
    {
        if(!dq.empty()&&dq.front()<=i-k)
        {
            dq.pop_front();
        }
        while(!dq.empty())
        {
            if(find_min)
            {
                if(arr[i]<arr[dq.back()])
            {
                dq.pop_back();
            }
            else break;
            }
            else
            {
                if(arr[i]>arr[dq.back()])
                {
                    dq.pop_back();
                }
                else break;
            }
        }
        dq.push_back(i);
        if(i>=k-1)
        {
            cout<<arr[dq.front()]<<' ';
        }
    }
    cout<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>arr[i];
    solve(true);
    solve(false);
    return 0;
}
