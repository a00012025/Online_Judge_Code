#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int maxn=500+10 ;

int n,m,num ;
int res[maxn][maxn] ;
int s[maxn],q[maxn],d[maxn],c[maxn] ;
int now[maxn] ;
vector<int> v[maxn] ;
priority_queue<pii,vector<pii>,greater<pii> > pq ;
bool check(int val)
{
    memset(now,0,sizeof(now)) ;
    while(!pq.empty()) pq.pop() ;
    int need=0 ;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
    {
        if(j==1) need=val ;
        int x=m*(i-1)+j ;
        for(auto it : v[x]) pq.push(pii(res[it][1],it)) ;
        if(pq.empty() || need==m-j+1){need-- ; continue ;}
        pii u=pq.top() ; pq.pop() ;
        int id=u.S ;
        if(res[id][now[id]+1]<x) return 0 ;
        now[id]++ ;
        if(now[id]!=q[id]*c[id]) pq.push(pii(res[id][now[id]+1],id)) ;
    }
    return pq.empty() ;
}

int solve()
{
    scanf("%d%d%d",&n,&m,&num) ;
    for(int i=0;i<maxn;i++) v[i].clear() ;
    for(int i=1;i<=num;i++)
    {
        scanf("%d%d%d%d",&s[i],&q[i],&d[i],&c[i]) ;
        for(int j=1;j<=q[i];j++) for(int k=1;k<=c[i];k++)
            res[i][c[i]*(j-1)+k]=s[i]+j*d[i]-c[i]-1+k ;
        v[s[i]].push_back(i) ;
    }
    int l=0 , r=m+1 ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(check(mid)) l=mid ;
        else r=mid ;
    }
    return l ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--) printf("%d\n",solve()) ;
}
