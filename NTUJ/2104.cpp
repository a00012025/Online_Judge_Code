#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=600 ;

bitset<maxn> b[maxn],b2 ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n,m ; scanf("%d%d",&n,&m) ;
        for(int i=0;i<n;i++) b[i].reset() ;
        while(m--)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            b[x][y]=1 ; b[y][x]=1 ;
        }

        LL ans=0LL ;
        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++)
        {
            b2=b[i]&b[j] ;
            LL val=b2.count() ;
            ans+=val*(val-1) ;
        }
        printf("%lld\n",ans) ;
    }
}
