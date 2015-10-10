#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;
int a[2*maxn] ;

main()
{
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        int s=0 , ans=0 ;
        memset(a,-1,sizeof(a)) ;
        a[maxn]=0 ;
        for(int i=1;i<=n;i++)
        {
            int x ; scanf("%d",&x) ;
            if(x) s+=(x>0 ? 1 : -1) ;
            if(a[s+maxn]!=-1) ans=max(ans,i-a[s+maxn]) ;
            else a[s+maxn]=i ;
        }
        printf("%d\n",ans) ;
    }
}
