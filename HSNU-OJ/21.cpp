#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1000000+10 ;
int w[maxn],x[maxn],per[maxn] ;
bool vis[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    int mi=1000000 ;
    for(int i=1;i<=n;i++) scanf("%d",&w[i]) , mi=min(mi,w[i]) ;
    for(int i=1;i<=n;i++) scanf("%d",&x[i]) ;
    for(int i=1;i<=n;i++)
    {
        int y ; scanf("%d",&y) ;
        per[x[i]]=y ;
    }

    LL ans=0LL ;
    for(int i=1;i<=n;i++) if(per[i]!=i && !vis[i])
    {
        int m=70000000 , num=0 ;
        LL sum=0LL ;
        for(int j=per[i];;j=per[j])
        {
            vis[j]=1 ; num++ ;
            sum+=w[j] ;
            m=min(m,w[j]) ;
            if(j==i) break ;
        }
        ans+=min(sum+((LL)m)*((LL)num-2),sum+((LL)mi)*((LL)num+1)+m) ;
    }
    printf("%I64d\n",ans) ;
}
