#include<bits/stdc++.h>
#define LL long long
#define INF 100000000
using namespace std;
const int maxn=100000+10 ;

vector<int> v[maxn],v2[maxn],tmp ;
int d1[maxn],d2[maxn] ;
queue<int> q ;
int type[maxn] ;
main()
{
    int n,m,st ;
    LL a,b ; scanf("%d%d%d%lld%lld",&n,&m,&st,&a,&b) ;
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
        v2[x].push_back(y) ;
        v2[y].push_back(x) ;
    }

    fill(d1,d1+n+1,INF) ;
    d1[st]=0 ; q.push(st) ;
    while(!q.empty())
    {
        int u=q.front() ; q.pop() ;
        for(int i=0;i<v[u].size();i++) if(d1[v[u][i]]==INF)
        {
            d1[v[u][i]]=d1[u]+1 ;
            q.push(v[u][i]) ;
        }
    }

    fill(d2,d2+n+1,INF) ;
    d2[st]=0 ; q.push(st) ;
    int cnt=0 ;
    while(!q.empty())
    {
        int u=q.front() ; q.pop() ; cnt++ ;
        for(int i=0;i<v[u].size();i++) type[v[u][i]]=cnt ;
        for(int i=0;i<v[u].size();i++)
        {
            tmp.clear() ;
            int u2=v[u][i] ;
            for(int j=0;j<v2[u2].size();j++)
            {
                if(v2[u2][j]==u) continue ;
                if(type[v2[u2][j]]==cnt) tmp.push_back(v2[u2][j]) ;
                else if(d2[v2[u2][j]]==INF)
                    d2[v2[u2][j]]=d2[u]+1 , q.push(v2[u2][j]) ;
            }
            v2[u2]=tmp ;
        }
    }
    for(int i=1;i<=n;i++)
    {
        LL ans=min(a*d1[i], b*(d1[i]/2) + (d1[i]%2)*a) ;
        ans=min(ans,b*d2[i]) ;
        printf("%lld\n",ans) ;
    }
}
