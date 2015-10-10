#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1000000000 ;
main()
{
    int c,w1,v1,w2,v2 ; scanf("%d%d%d%d%d",&c,&v1,&v2,&w1,&w2) ;
    if((LL)v1*w2 < (LL)v2*w1) swap(v1,v2) , swap(w1,w2) ;

    int sq=sqrt(maxn+0.5) ;
    LL ans=0LL ;
    if(w1<=sq) for(LL i=0;i*w2<=c && i<w1;i++) ans=max(ans,i*v2+(c-i*w2)/w1*v1) ;
    else for(LL i=0;i*w1<=c;i++) ans=max(ans,i*v1+(c-i*w1)/w2*v2) ;
    printf("%lld\n",ans) ;
}
