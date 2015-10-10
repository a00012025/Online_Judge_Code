#include<bits/stdc++.h>
#define LL long long
#define lowbit(x) (x&-x)
using namespace std;
const int maxn=25+3 ; /// 19! > 10^16

LL fac[19] ;
map<LL,int> mp[maxn] ;
int k,fac_s ;
LL ans=0LL , sum ;
LL all[1<<(maxn/2)],all2[1<<(maxn/2)] ;

void solve(const vector<int> &v,int type)
{
    int n=v.size() ;
    fac_s=0 ;
    for(int i=0;i<n;i++) if(v[i]<19)
        fac_s |= (1<<i) ;

    memset(all,0,sizeof(all)) ;
    memset(all2,0,sizeof(all2)) ;
    for(int i=0;i<(1<<n);i++) for(int j=0;j<n;j++)
        if(i&(1<<j))
    {
        all[i]+=v[j] ;
        all2[i]+= ( v[j]<=18 ? fac[v[j]] : 0LL ) ;
    }

    for(int i=0;i<(1<<n);i++)
    {
        int S0 = (i&fac_s) ;
        for(int S=S0;;S=((S-1)&S0))
        {
            LL s=all2[S]+all[i^S] ;
            int cnt=__builtin_popcount(S) ;
            if(type==1)
            {
                cnt++ ;
                while(cnt<28) mp[cnt][s]++ , cnt+=lowbit(cnt) ;
            }
            else if(cnt<=k)
            {
                int x=k-cnt+1 ;
                //ans+=mp[0][sum-s] ;
                while(x) ans+=mp[x][sum-s] , x-=lowbit(x) ;
            }
            if(!S) break ;
        }
    }
}

vector<int> v1,v2;
main()
{
    fac[0]=1LL ;
    for(int i=1;i<19;i++) fac[i]=(LL)fac[i-1]*i ;
    int n ;
    scanf("%d%d%lld",&n,&k,&sum) ;
    for(int i=0;i<n;i++)
    {
        int x ; scanf("%d",&x) ;
        if(i<n/2) v1.push_back(x) ;
        else v2.push_back(x) ;
    }

    solve(v1,1) ;
    solve(v2,2) ;
    printf("%lld\n",ans) ;
}
