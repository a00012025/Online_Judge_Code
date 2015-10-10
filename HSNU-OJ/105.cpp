#include<bits/stdc++.h>
using namespace std;

int gcd(int x,int y)
{
    return y==0 ? x : gcd(y,x%y) ;
}

bool vis[5001] ;
int cnt,n,a,b,c ;

void dfs(int x)
{
    vis[x]=1 ;
    for(int i=0;i<n;i++) if(!vis[i] && gcd(a*x*x+b*x+c,a*i*i+b*i+c)==1)
        dfs(i) ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d%d%d%d",&n,&a,&b,&c) ;
        if(gcd(gcd(a,b),c)!=1) { printf("%d\n",n) ; continue ; }
        memset(vis,0,sizeof(vis)) ;
        cnt=0 ;
        for(int i=0;i<n;i++) if(!vis[i]) dfs(i) , cnt++ ;
        printf("%d\n",cnt) ;
    }
}
