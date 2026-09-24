#include<iostream>
using namespace std;
struct people{
    int id;//编号
    int isnot;//是否出圈
}p[105];
int main()
{
    int n,m;
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        p[i].id=i+1;
        p[i].isnot=1;
    }


    int remaining = m; // 剩余人数
    int count = 0;     // 报数计数器
    int k = 0;         // 当前扫描到的数组索引

    while (remaining > 0) {
        if (p[k].isnot == 1) { // 只有还在圈内的人才能报数
            count++;
            if (count == n) {  // 报到 n 的人出圈
                cout << p[k].id << ' ';
                p[k].isnot = 0;
                count = 0;     // 重置报数
                remaining--;   // 剩余人数减 1
            }
        }
        
        // 移动到下一个位置（形成环形结构）
        k = (k + 1) % m;
    }

    return 0;
}