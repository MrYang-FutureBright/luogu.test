// #include<iostream>
// #include<stdio.h>
// using namespace std;
// int T;
// long long L,R;
// void solve(long long L,long long R)
// {
//     while(1)
//     {
//         long long temp=1;
//         while(temp<=R)
//         {
//             temp=temp*2;
//         }
//         temp/=2;
//         if(temp>L)
//         {
//             cout<<(temp^(temp-1))<<endl;
//             return;
//         }
//         else if(temp<=L)
//         {
//             L=L-temp;
//             R=R-temp;
//         }
//     }
// }
// int main()
// {
//     cin>>T;
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     for(int i=0;i<T;i++)
//     {
//         scanf("%lld%lld",&L,&R);
//         if(L==R)
//         {
//             cout<<0<<endl;
//             continue;
//         }
//         long long temp=1;
//         if((R&(R-1))==0)
//         {
//             cout<<(R^(R-1))<<endl;
//             continue;
//         }
//         while(temp<R)
//         {
//             temp=temp*2;
//         }
//         temp/=2;
//         if(temp>L)
//         {
//             cout<<(temp^(temp-1))<<endl;
//             continue;
//         }
//         else if(temp<=L)
//         {
//            L=L-temp;
//            R=R-temp;
//            solve(L,R);
//         }
//     }
// }
// #include<iostream>
// #include<stack>
// #include<string>
// using namespace std;
// string s;

// void solve() {
//     stack<char> st1;  
//     stack<char> st2;  
//     int isnot = 0;

//     for (char i : s) {
//         if (i == '.') {
//             isnot = 1;
//             continue;
//         }
//         else if (i == '%') {
//             isnot = 2;
//             continue;
//         }
//         else if (i == '/') {
//             isnot = 3;
//             continue;
//         }

//         if (!isnot) st1.push(i);
//         else st2.push(i);
//     }

//     while (!st1.empty() && st1.top() == '0') {
//         st1.pop();
//     }

//     string temp;
//     while (!st2.empty()) {
//         temp += st2.top();
//         st2.pop();
//     }

//     while (!temp.empty() && temp.back() == '0') {
//         temp.pop_back();
//     }
//     int start = 0;
//     while (start < temp.size() && temp[start] == '0') {
//         start++;
//     }
//     temp = temp.substr(start);
//     if (st1.empty()) cout << "0";
//     else {
//         while (!st1.empty()) {
//             cout << st1.top();
//             st1.pop();
//         }
//     }

//     if (isnot == 1) cout << ".";
//     if (isnot == 2) cout << "%";
//     if (isnot == 3) cout << "/";
//     if(isnot==1&&temp.empty())
//     {
//         cout<<'0';
//         return;
//     }
//     cout << temp;
// }

// int main() {
//     cin >> s;
//     solve();
//     return 0;
// }
// #include<iostream>
// int n;
// using namespace std;
// struct student
// {
//     int a,b,c;
//     int id;
//     int sum;

// };
// int main()
// {
//     cin>>n;
//     student s[300];
//     for(int i=0;i<n;i++)
//     {
//         cin>>s[i].a>>s[i].b>>s[i].c;
//         s[i].id=i+1;
//         s[i].sum+=(s[i].a+s[i].b+s[i].c);
//     }
//     for(int i=0;i<n-1;i++)
//     {
//         for(int j=0;j<n-i-1;j++)
//         {
//             if(s[j].sum<s[j+1].sum)
//             {
//                 student t=s[j];
//                 s[j]=s[j+1];
//                 s[j+1]=t;
//             }
//             else if(s[j].sum==s[j+1].sum)
//             {
//                 if(s[j].a==s[j+1].a)
//                 {
//                     if(s[j].id>s[j+1].id)
//                     {
//                         student t=s[j];
//                         s[j]=s[j+1];
//                         s[j+1]=t;
//                     }
//                 }
//                 else if(s[j].a<s[j+1].a)
//                 {
//                     student t=s[j];
//                     s[j]=s[j+1];
//                     s[j+1]=t;
//                 }
//             }
//         }
//     }
//     for(int i=0;i<5;i++)
//     {
//         cout<<s[i].id<<' '<<s[i].sum<<endl;
//     }
//     return 0;
// }
#include<iostream>
#define m (int)(1e9+7)
using namespace std;
int main()
{
    int N,V;
    cin>>N>>V;
    int dp[1005];int way[1005];
    int w[1005];int v[1005];
    for(int i=0;i<1005;i++)
    {
        dp[i]=0;
        way[i]=0;
    }
    way[0]=1;
    for(int i=0;i<N;i++)
    {
        cin>>w[i]>>v[i];
    }
    for(int i=0;i<V;i++)
    {
        way[i]=1;
    }
    for(int i=0;i<N;i++)
    {
        for(int j=V;j>=w[i];j--)
        {
            int key=dp[j-w[i]]+v[i];
            if(key>dp[j])
            {
                dp[j]=key;
                way[j]=way[j-w[i]]%m;
            }
            else if(key==dp[j])
            {
                way[j]=(way[j]+way[j-w[i]])%m;
            }
        }
    }
    cout<<way[V]<<endl;
    return 0;
}