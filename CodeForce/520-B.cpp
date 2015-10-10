#include<bits/stdc++.h>
using namespace std;
const int maxn=20000+10 ;

bool vis[maxn] ;
int d[maxn] ;
queue<int> q ;
main()
{
    int st,ed ; scanf("%d%d",&st,&ed) ;
    d[st]=0 ; vis[st]=1 ; q.push(st) ;
    while(!q.empty())
    {
        int u=q.front() ; q.pop() ;
        if(u==ed) { printf("%d\n",d[ed]) ; return 0 ; }
        if(2*u<maxn && !vis[2*u])
            d[2*u]=d[u]+1 , vis[2*u]=1 , q.push(2*u) ;
        if(u-1>0 && !vis[u-1])
            d[u-1]=d[u]+1 , vis[u-1]=1 , q.push(u-1) ;
    }
}
