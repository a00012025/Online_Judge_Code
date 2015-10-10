#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10,maxt=10000+10 ;
struct P
{
    int x,y ;
    bool operator < (const P &rhs) const
    {
        return x==rhs.x ? y<rhs.y : x<rhs.x ;
    }
};

P tmp[maxt] ;
void cal(vector<P> &v)
{
    sort(v.begin(),v.end()) ;
    int cnt=0 ;
    for(auto i : v)
    {
        if(!cnt) { tmp[cnt++]=i ; continue ; }
        if(tmp[cnt-1].y >= i.y) continue ;
        else if(i.x <= tmp[cnt-1].y)
            tmp[cnt-1].y=max(tmp[cnt-1].y,i.y) ;
        else tmp[cnt++]=i ;
    }
    for(int i=0;i<cnt;i++) v[i]=tmp[i] ;
    v.resize(cnt) ;
}

vector<P> v[maxn] ;
int dis[maxn][maxt] ;

main()
{
    int n,t ;
    while(scanf("%d%d",&n,&t)==2 && n+t)
    {
        for(int i=1;i<=n;i++) v[i].clear() ;
        int m ; scanf("%d",&m) ;
        while(m--)
        {
            int id,x,y ; scanf("%d%d%d",&id,&x,&y) ;
            v[id].push_back((P){x,y}) ;
        }
        for(int i=1;i<=n;i++)
        {
            if(!v[i].empty()) cal(v[i]) ;
            if(v[i].empty())
                for(int j=0;j<=t;j++) dis[i][j]=t-j ;
            else for(int j=0,now=0 ; now<=t ; j++ )
            {
                int ri= j==v[i].size() ? t : v[i][j].x ;
                while(now<=ri) dis[i][now]=ri-now , now++ ;
                if(now==t+1) break ;
                while(now<v[i][j].y) dis[i][now]=-1 , now++ ;
            }
        }

        int Q ; scanf("%d",&Q) ;
        while(Q--)
        {
            int x ; scanf("%d",&x);
            int ans=-1,id ;
            for(int i=1;i<=n;i++) if(dis[i][x]>ans)
                ans=dis[id=i][x] ;
            if(ans<=0) printf("Oh, no!\n") ;
            else printf("%d %d\n",id,ans) ;
        }
    }
}
