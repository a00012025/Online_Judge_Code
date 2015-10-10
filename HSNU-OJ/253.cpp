#include<bits/stdc++.h>
using namespace std;
int n,w[700],h[700] ;

int d[700][700] ;
int dp(int W,int H)
{
    if(W==0 || H==0) return 0 ;
    if(d[W][H]!=-1) return d[W][H] ;
    int &ans=d[W][H] ; ans=W*H ;
    for(int i=1;i<=n;i++) if(W>=w[i] && H>=h[i])
    {
        ans=min(ans,dp(w[i],H-h[i])+dp(W-w[i],H)) ;
        ans=min(ans,dp(W-w[i],h[i])+dp(W,H-h[i])) ;
    }
    return ans ;
}

main()
{
    int W,H ; scanf("%d%d%d",&W,&H,&n) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&w[i],&h[i]) ;
    memset(d,-1,sizeof(d)) ;
    printf("%d\n",dp(W,H)) ;
}
