#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+10,INF=100000000 ;
struct P{int ed,dis;};
struct Q
{
    int id,dis ;
    bool operator < (const Q &rhs) const
    {
        return dis>rhs.dis ;
    }
};
vector<P> v[maxn] ;
vector<int> odd ;
int d[maxn],dis2[30][30],n ;

bool done[maxn] ;
void dijkstra(int st)
{
    memset(done,0,sizeof(done)) ;
    for(int i=1;i<=n;i++) d[i]=INF ;
    priority_queue<Q> pq ;
    d[st]=0 ; pq.push((Q){st,0}) ;
    while(!pq.empty())
    {
        Q u=pq.top() ; pq.pop() ;
        if(done[u.id]) continue ;
        done[u.id]=1 ;
        for(int i=0;i<v[u.id].size();i++)
        {
            if(d[v[u.id][i].ed] > d[u.id]+v[u.id][i].dis)
            {
                d[v[u.id][i].ed] = d[u.id]+v[u.id][i].dis ;
                pq.push((Q){v[u.id][i].ed,d[u.id]+v[u.id][i].dis}) ;
            }
        }
    }
}

bool vis[30] ;
int ans,dp[1<<20] ;

int DP(int x)
{
    if(!x) return 0 ;
    if(dp[x]!=-1) return dp[x] ;
    int &ans=dp[x] ; ans=INF ;
    for(int i=0;i<odd.size()-1;i++) if((x)&(1<<i))
    {
        for(int j=i+1;j<odd.size();j++) if((x)&(1<<j))
        {
            ans=min(ans,dis2[i][j]+DP(x-(1<<i)-(1<<j))) ;
        }
        break ;
    }
    return ans ;
}

main()
{
    int m,st,ed ;
    while(scanf("%d%d%d%d",&n,&m,&st,&ed)!=EOF)
    {
        for(int i=1;i<=n;i++) v[i].clear() ;
        int all=0 ;
        while(m--)
        {
            int x,y,d ; scanf("%d%d%d",&x,&y,&d) ;
            v[x].push_back((P){y,d}) ;
            v[y].push_back((P){x,d}) ;
            all+=d ;
        }
        odd.clear() ;
        for(int i=1;i<=n;i++)
        {
            if((i==st || i==ed) && v[i].size()%2==0) odd.push_back(i) ;
            else if(i!=st && i!=ed && v[i].size()%2) odd.push_back(i) ;
        }
        for(int i=0;i<odd.size();i++)
        {
            dijkstra(odd[i]) ;
            for(int j=i+1;j<odd.size();j++) dis2[i][j]=dis2[j][i]=d[odd[j]] ;
        }
        memset(dp,-1,sizeof(dp)) ;
        printf("%d\n",DP((1<<odd.size())-1)+all) ;
    }
}
