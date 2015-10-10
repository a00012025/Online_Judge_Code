#include<bits/stdc++.h>
#define LL long long
#define DB double
using namespace std;
const int maxn=200000+10 ;

int a[maxn],T ;
LL s[maxn] ;
DB m[maxn],c ;
main()
{
    int n ; scanf("%d%d%lf",&n,&T,&c) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]) ;
        s[i]=s[i-1]+a[i] ;
        m[i]=(m[i-1]+a[i]*1.0/T)/c ;
    }
    int Q ; scanf("%d",&Q) ;
    while(Q--)
    {
        int p ; scanf("%d",&p) ;
        DB x=(s[p]-s[p-T])*1.0/T ;
        DB y=m[p] ;
        printf("%.6f %.6f %.6f\n",x,y,fabs(x-y)/x) ;
    }
}
