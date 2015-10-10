#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=10000000+10 ;
bool vis[maxn] ;
int p[670000],pcnt=0 ;
void make_prime()
{
    for(int i=2;i*i<maxn;i++) if(!vis[i])
        for(int j=i*i;j<maxn;j+=i)
            vis[j]=1 ;
    for(int i=2;i<maxn;i++) if(!vis[i])
        p[++pcnt]=i ;
}

vector<LL> di ;
LL pr[30] ;
int num[30] ;

void dfs(int x,LL now)
{
    if(x==0) { di.push_back(now) ; return ; }
    LL now2=now ;
    for(int i=0;i<=num[x];i++)
    {
        dfs(x-1,now2) ;
        now2*=pr[x] ;
    }
}

void get_div(LL val)
{
    int cnt=0 ;
    for(int i=1;val!=1 && i<=pcnt;i++)
    {
        if(val<maxn && !vis[val]) break ;
        if(val%p[i]==0)
        {
            cnt++ ; pr[cnt]=p[i] ;
            while(val%p[i]==0) val/=p[i] , num[cnt]++ ;
        }
    }
    if(val!=1) cnt++ , pr[cnt]=val , num[cnt]=1 ;
    dfs(cnt,1LL) ;
    sort(di.begin(),di.end()) ;
}

LL a[250001] ;
vector<LL> v ;
main()
{
    make_prime() ;
    LL n ; int k ;
    scanf("%I64d%d",&n,&k) ;
    for(int i=1;i<=k;i++) scanf("%I64d",&a[i]) ;

    LL val=__gcd(n,a[k]) ;
    get_div(val) ;

    for(int i=1;i<k;i++) v.push_back(__gcd(val,a[i])) ;
    sort(v.begin(),v.end()) ;
    v.resize(unique(v.begin(),v.end())-v.begin()) ;

    for(auto i : di)
    {
        bool ok=1 ;
        for(auto j : v) if(j%i==0)
            { ok=0 ; break ; }
        if(ok) { printf("%I64d\n",n/i) ; return 0 ; }
    }
}
