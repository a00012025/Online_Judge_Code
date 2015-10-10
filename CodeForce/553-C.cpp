#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
const int maxn=100000+10 ;
void err(){printf("0\n") ; exit(0) ;}

int fa[maxn],fad[maxn] ;
int getfa(int x)
{
    if(fa[x]==x) return x ;
    int f=fa[x] , t=getfa(f) ;
    fad[x]=(fad[x]+fad[f])%2 ;
    return fa[x]=t ;
}

bool join(int x,int y,int dis)
{
    int x2=getfa(x) , y2=getfa(y) ;
    dis=(dis+fad[x]+fad[y])%2 ;
    if(x2!=y2)
    {
        fa[x2]=y2 ; fad[x2]=dis ;
        return 1 ;
    }
    else return dis==0 ;
}

main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++) fa[i]=i ;
    while(m--)
    {
        int x,y,d ; scanf("%d%d%d",&x,&y,&d) ;
        if(!join(x,y,d^1)) err() ;
    }
    int ans=(MOD+1)/2 ;
    for(int i=1;i<=n;i++) if(fa[i]==i)
        ans=ans*2%1000000007 ;
    printf("%d\n",ans) ;
}
