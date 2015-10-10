#include<bits/stdc++.h>
#define INF 100000000
using namespace std;
const int maxn=50000+10 ;
struct P{int to,dis;};
vector<P> v[maxn] ;

bool inq[maxn] ;
int d[maxn] ;
queue<int> q ;
int SPFA(int st,int ed)
{
    memset(inq,0,sizeof(inq)) ;
    fill(d,d+maxn,INF) ;
    d[st]=0 ; q.push(st) ; inq[st]=1 ;
    while(!q.empty())
    {
        int u=q.front() ; q.pop() ; inq[u]=0 ;
        for(auto i : v[u]) if(d[i.to] > d[u]+i.dis)
        {
            d[i.to]=d[u]+i.dis ;
            if(!inq[i.to]) q.push(i.to) ;
            inq[i.to]=1 ;
        }
    }
    return d[ed] ;
}

int sz[maxn] ;
main()
{
    for(int i=0;i<maxn-1;i++) v[i].push_back((P){i+1,1}) ;
    for(int i=1;i<maxn;i++) v[i].push_back((P){i-1,0}) ;
    for(int i=0;i<maxn;i++) sz[i]=v[i].size() ;

    int T ; scanf("%d",&T) ;
    while(T--)
    {
        for(int i=0;i<maxn;i++) v[i].resize(sz[i]) ;
        int m ; scanf("%d",&m) ;
        while(m--)
        {
            int x,y,c ; scanf("%d%d%d",&x,&y,&c) ;
            x++ ; y++ ;
            v[y].push_back((P){x-1,-c}) ;
        }
        printf("%d\n",-SPFA(maxn-1,0)) ;
    }
}
