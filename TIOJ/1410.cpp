#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;
struct P
{
    int x,t ;
    bool operator < (const P &rhs) const
    {
        return x==rhs.x ? t<rhs.t : x<rhs.x ;
    }
}a[2*maxn];

main()
{
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&a[2*i].x,&a[2*i+1].x) ;
            a[2*i].t=1 ; a[2*i+1].t=2 ;
        }
        sort(a,a+2*n) ;
        int ans=0 , now=0 ;
        for(int i=0;i<2*n;i++)
        {
            if(a[i].t==1) now++ ;
            else now-- ;
            ans=max(ans,now) ;
        }
        printf("%d\n",ans) ;
    }
}
