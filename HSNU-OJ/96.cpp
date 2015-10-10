#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=40000+10 ;
vector<int> v[maxn] ;
int d[maxn] ;
int num[6] ;

queue<int> q ;
void get_num(int st,LL &a,LL &b)
{
    a=b=0LL ;
    memset(d,-1,sizeof(d)) ;
    while(!q.empty()) q.pop() ;
    q.push(st) ; d[st]=0 ;
    while(!q.empty())
    {
        int u=q.front() ; q.pop() ;
        if(d[u]==1) a++ ;
        if(d[u]==2) { b++ ; continue ; }
        for(int i=0;i<v[u].size();i++) if(d[v[u][i]]==-1)
            d[v[u][i]]=d[u]+1 , q.push(v[u][i]) ;
    }
}

main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=m;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }

    LL a,b,c,d ;
    get_num(1,a,b) ;
    get_num(2,d,c) ;
    LL t=n-2-a-b-c-d ;
    LL ans=a*(a+1)/2+d*(d+1)/2+(t+b+c)*(t+b+c-1)/2 ;
    ans += max(a*(b+t)+d*(c),a*(b)+d*(c+t)) ;
    printf("%I64d\n",ans-m) ;
}
