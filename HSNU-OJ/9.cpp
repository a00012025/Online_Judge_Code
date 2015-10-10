#include<bits/stdc++.h>
#define DB double
#define LD long double
#define LL long long
#define eps (1e-5)
#define INF 100.0
using namespace std;
struct P{int ed ; DB dis ;};
vector<P> v[2001] ;

int n ;
DB d[2001] ;
bool inq[2001] ;
int cnt[2001] ;
int Bellman_Ford(int st,int ed)
{
    for(int i=1;i<=n;i++) d[i]=INF ; d[st]=0.0 ;
    memset(inq,0,sizeof(inq)) ;
    memset(cnt,0,sizeof(cnt)) ;
    queue<int> q ; q.push(st) ; inq[st]=1 ;
    while(!q.empty())
    {
        int u=q.front() ; q.pop() ; inq[u]=0 ;
        for(int i=0;i<v[u].size();i++)
        {
            if(d[v[u][i].ed] > d[u]+v[u][i].dis + eps)
            {
                d[v[u][i].ed] = d[u]+v[u][i].dis ;
                if(!inq[v[u][i].ed]) q.push(v[u][i].ed) ;
                inq[v[u][i].ed]=1 ;
                if(++cnt[v[u][i].ed]>n) return -1 ;
            }
        }
    }
    return 1 ;
}

main()
{
    int m ; DB V ; int st,ed ;
    scanf("%d%d%lf%d%d",&n,&m,&V,&st,&ed) ;
    while(m--)
    {
        int x,y ; DB dis ;
        scanf("%d%d%lf",&x,&y,&dis) ;
        v[x].push_back((P){y,log(dis)}) ;
    }
    if(Bellman_Ford(st,ed)==-1) printf("0\n") ;
    else printf("%.0lf\n",V*exp(d[ed])) ;
}
