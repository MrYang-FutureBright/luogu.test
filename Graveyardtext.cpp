#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    double ans;int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
         ans=0.0;
         for(int i=1;i<n;i++)
         {
            double pla=(double)i/n*(n+m);
            ans+=fabs(pla-floor(pla+0.5))/(n+m);
         }
         printf("%.4lf\n",ans*10000);
    }
    return 0;
}