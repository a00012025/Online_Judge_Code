#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;
const int INF=10000000 ;
struct P {int ed,w ;};
vector<P> v[201] ;
int data[201],d[201],cnt[201],n ;
bool inq[201],done[201] ;

int cub(int a)
{
    return a*(a*a) ;
}

void bellmanford(int st)
{
    queue<int> q ;
    for(int i=1;i<=n;i++) d[i]=INF ;
    memset(cnt,0,sizeof(cnt)) ;
    memset(inq,0,sizeof(inq)) ;
    memset(done,0,sizeof(done)) ;
    d[st]=0 ; q.push(st) ; inq[st]=1 ;
    while(!q.empty())
    {
        int u=q.front() ; q.pop() ; inq[u]=0 ;
        for(int i=0;i<v[u].size();i++)
            if(!done[v[u][i].ed] && d[v[u][i].ed] > d[u]+v[u][i].w)
        {
            d[v[u][i].ed] = d[u]+v[u][i].w ;
            if(!inq[v[u][i].ed]) q.push(v[u][i].ed) ;
            inq[v[u][i].ed]=1 ;
            if(++cnt[v[u][i].ed]>n) {d[v[u][i].ed]=-INF ; done[v[u][i].ed]=1 ;}
        }
    }

}

main()
{
    int tc=0;
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++) scanf("%d",&data[i]) ;
        for(int i=1;i<=n;i++) v[i].clear() ;
        int m;
        scanf("%d",&m) ;
        while(m--)
        {
            int a,b ;
            scanf("%d%d",&a,&b) ;
            v[a].push_back((P){b,cub(data[b]-data[a])}) ;
        }
        bellmanford(1) ;
        printf("Set #%d\n",++tc) ;
        int Q;
        scanf("%d",&Q) ;
        while(Q--)
        {
            int q;
            scanf("%d",&q) ;
            if(d[q]<3 || d[q]==INF) printf("?\n") ;
            else printf("%d\n",d[q]) ;
        }
    }
}
