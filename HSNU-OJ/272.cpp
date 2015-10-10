#include<bits/stdc++.h>
using namespace std;
const int maxn=50 ;

struct P{int to,dis;};
vector<P> v[maxn] ;
int cnt[maxn],inq[maxn],d[maxn] ;
bool Bellman(int st)
{
    memset(cnt,0,sizeof(cnt)) ;
    memset(inq,0,sizeof(inq)) ;
    fill(d,d+maxn,1e9) ;
    queue<int> q ;
    d[st]=0 ; q.push(st) ; inq[st]=1 ;
    while(!q.empty())
    {
        int u=q.front() ; q.pop() ; inq[u]=0 ;
        if(++cnt[u]==maxn) return 1 ;
        for(auto i : v[u]) if(d[i.to]>d[u]+i.dis)
        {
            d[i.to]=d[u]+i.dis ;
            if(!inq[i.to]) q.push(i.to) ;
            inq[i.to]=1 ;
        }
    }
    return 0 ;
}

int num[maxn],need[maxn] ;
bool check(int x)
{
    for(int i=0;i<maxn;i++) v[i].clear() ;
    for(int i=0;i<8;i++)
        v[24+i].push_back((P){i,x}) ,
        v[i].push_back((P){24+i,-x}) ;
    for(int i=1;i<=24;i++) v[i].push_back((P){i-1,num[i]}) ;
    for(int i=8;i<=31;i++) v[i-8].push_back((P){i,-need[(i-1)%24+1]}) ;
    for(int i=0;i<32;i++) v[32].push_back((P){i,0}) ;
    return !Bellman(32) ;
}

main()
{
    for(int i=1;i<=24;i++) scanf("%d",&need[i]) ;
    int k ; scanf("%d",&k) ;
    for(int i=1;i<=k;i++){int x ; scanf("%d",&x) ; num[x+1]++ ;}
    int l=-1 , r=k+1 ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(check(mid)) r=mid ;
        else l=mid ;
    }
    if(l==k) printf("No Solution\n") ;
    else printf("%d\n",r) ;
}
