#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
using namespace std;

vector<int> v1,v2,tmp1,tmp2 ;
int k,ansx,ansy ;
LL ans=INF ;

bool better(LL val,int x,int y)
{
    if(val!=ans) return val<ans ;
    if(x!=ansx) return x<ansx ;
    if(y!=ansy) return y<ansy ;
    return 0 ;
}

void check(int x,int y)
{
    LL ans2=0LL ; int maxd=0 ;
    for(int i=0;i<k;i++) ans2+=2*abs(x-v1[i]) ;
    for(int i=0;i<k;i++) ans2+=2*abs(y-v2[i]) ;
    for(int i=0;i<k;i++) maxd=max(maxd,abs(x-tmp1[i])+abs(y-tmp2[i])) ;
    if(better(ans2-maxd,x,y)) ansx=x , ansy=y , ans=ans2-maxd ;
}

main()
{
    int n,m ; scanf("%d%d%d",&n,&m,&k) ;
    for(int i=1;i<=k;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v1.push_back(x) ; tmp1.push_back(x) ;
        v2.push_back(y) ; tmp2.push_back(y) ;
    }
    sort(v1.begin(),v1.end()) ;
    sort(v2.begin(),v2.end()) ;
    int x0=(k-1)/2 , y0=(k-1)/2 ;
    check(v1[x0],v2[y0]) ;
    if(x0>=1)
    {
        check(v1[x0-1],v2[y0-1]) ;
        check(v1[x0-1],v2[y0]) ;
        check(v1[x0],v2[y0-1]) ;
        if(x0+1<k)
        {
            check(v1[x0-1],v2[y0+1]) ;
            check(v1[x0],v2[y0+1]) ;
            check(v1[x0+1],v2[y0-1]) ;
            check(v1[x0+1],v2[y0]) ;
            check(v1[x0+1],v2[y0+1]) ;
        }
    }
    printf("%lld\n%d %d\n",ans,ansx,ansy) ;
}
