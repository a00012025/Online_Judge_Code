#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;

int vis[maxn] ;
int p[maxn],pcnt=0 ;
void prime()
{
    for(int i=2;i*i<maxn;i++) if(!vis[i])
        for(int j=i*i;j<maxn;j+=i) vis[j]=1 ;
    for(int i=2;i<maxn;i++) if(!vis[i])
        p[++pcnt]=i ;
}

main()
{
    prime() ;
    memset(vis,0,sizeof(vis)) ;
    int T ; scanf("%d",&T) ;
    for(int vcnt=1;vcnt<=T;vcnt++)
    {
        int n,m ; scanf("%d%d",&n,&m) ;
        for(int i=1;p[i]<=m;i++)
        {
            int j=n/p[i]*p[i] ;
            while(vis[j]==vcnt) j-=p[i] ;
            if(p[i]==m) printf("%d\n",j) ;
            else vis[j]=vcnt ;
        }
    }
}
