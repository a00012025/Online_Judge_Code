#include<bits/stdc++.h>
#define LL long long
#define pll pair<LL,LL>
#define pil pair<int,LL>
#define F first
#define S second
using namespace std;
const int maxn=1000000+10 ;

struct P{int to,dis;}nex[maxn];
vector<P> v[maxn] ;

bool used[maxn] ;
int vis[maxn],vcnt ;
int nowid ;
LL nowM ;
pil sta[maxn] ;
void dfs(int x)
{
    int now=0,sz=0 ;
    sta[sz++]=(pil){x,0} ;
    LL dis ;
    while(now<sz)
    {
        x=sta[now].F , dis=sta[now++].S ;
        vis[x]=vcnt ;
        if(dis>nowM) nowM=dis , nowid=x ;
        for(auto i : v[x])
            if(vis[i.to]!=vcnt && !used[i.to])
            sta[sz++]=(pil){i.to,dis+i.dis} ;
    }
}

pll get_long(int x)
{
    used[x]=0 ; nowM=-1 ;
    pll ret ;
    vcnt++ ; dfs(x) ; ret.F=nowM ;
    nowM=-1 ; vcnt++ ; dfs(nowid) ;
    ret.S=nowM ; used[x]=1 ;
    return ret ;
}

bool vis0[maxn] ;
LL val[2*maxn],sum[2*maxn] ;
deque<pil> dq ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        int x,dis ; scanf("%d%d",&x,&dis) ;
        nex[i]=(P){x,dis} ;
        v[i].push_back((P){x,dis}) ;
        v[x].push_back((P){i,dis}) ;
    }
    LL Ans=0 ;
    for(int x0=1;x0<=n;x0++) if(!vis[x0])
    {
        int x=x0 ; LL ans=0 ;
        for(;!vis0[x];x=nex[x].to) vis0[x]=1 ;
        for(int y=nex[x].to;;y=nex[y].to)
        {
            used[y]=1 ;
            if(y==x) break ;
        }
        int cnt=0 ;
        for(int y=nex[x].to;;y=nex[y].to)
        {
            pll tmp=get_long(y) ;
            ans=max(ans,tmp.S) ;
            val[cnt]=tmp.F ;
            sum[cnt+1]=sum[cnt]+nex[y].dis ;
            cnt++ ; if(y==x) break ;
        }
        for(int i=cnt;i<2*cnt-1;i++)
            val[i]=val[i-cnt] , sum[i+1]=sum[i+1-cnt]+sum[cnt] ;

        dq.clear() ;
        for(int i=0;i<2*cnt-1;i++)
        {
            while(!dq.empty() && dq.back().F<=i-cnt)
                dq.pop_back() ;
            if(!dq.empty()) ans=max(ans,dq.back().S+val[i]+sum[i]) ;
            while(!dq.empty() && dq.front().S<=val[i]-sum[i])
                dq.pop_front() ;
            dq.push_front((pil){i,val[i]-sum[i]}) ;
        }
        Ans+=ans ;
    }
    printf("%lld\n",Ans) ;
}
