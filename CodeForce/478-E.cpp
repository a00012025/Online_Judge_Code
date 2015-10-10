#include<bits/stdc++.h>
#define LL long long
#define INF 100000000000000LL
#define KK 1000000
#define F first
#define S second
#define maxn 10000000
using namespace std;

inline bool chk2(int a,int x,int y)
{
    return a<min(x,y) || a>max(x,y) ;
}

short isu[maxn],isd[maxn],hi[maxn],hi2[maxn] ;
bool check(LL y)
{
    LL x=y/maxn ; y%=maxn ;
    if(!x) return isu[y] ;
    if(!isu[x] || !isd[y]) return 0 ;
    if(x<10) return chk2(hi[y],x,hi2[y]) ;
    return chk2(x%10,x/10%10,hi[y]) && chk2(hi[y],x%10,hi2[y]) ;
}

int now[10] ;
void process(int x)
{
    isu[x]=1 ;
    if(x<100000) return ;
    if(x<1000000)
    {
        if(now[0]<now[1]) return ;
        hi[x]=0 ; hi2[x]=now[0] ;
    }
    else
    {
        hi[x]=now[0] ; hi2[x]=now[1] ;
    }
    isd[x]=1 ;
}

void dfs(int val,int x)
{
    if(x) process(val) ;
    if(x==7) return ;
    int st=(x==0 ? 1 : 0) , ed=9 ;
    if(x>=2 && now[x-2]>now[x-1]) st=now[x-1]+1 ;
    else if(x>=2 && now[x-2]<now[x-1]) ed=now[x-1]-1 ;
    for(int i=st;i<=ed;i++) if(!x || i!=now[x-1])
        now[x]=i , dfs(val*10+i,x+1) ;
}

void solve1(LL n,LL k)
{
    int cnt=0 ;
    LL i ;
    for(i=n;i<=INF && cnt<k;i+=n) if(check(i))
        cnt++ ;
    cout << (cnt==k ? i-n : -1) ;
}

main()
{
    LL n,k ; cin >> n >> k ;
    dfs(0,0) ;
    solve1(n,k) ;
}
