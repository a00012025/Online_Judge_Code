#include<bits/stdc++.h>
using namespace std;

int k,now[10],n ;
bool decode(int x)
{
    for(int i=1;i<=n;i++)
    {
        now[i]=x%51 , x/=51 ;
        if(now[i]==k) return 1 ;
    }
    return 0 ;
}
int encode()
{
    int ret=0 ;
    for(int i=n;i>=1;i--) ret=ret*51+now[i] ;
    return ret ;
}

int cap[10] ;
map<int,int> mp ;
queue<int> q ;
main()
{
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&cap[i]) ;
    scanf("%d",&k) ;

    bool no=1 ;
    for(int i=1;i<=n;i++) if(cap[i]>=k) no=0 ;
    if(no) { printf("-1\n") ; return 0 ; }

    int g=cap[1] ;
    for(int i=2;i<=n;i++) g=__gcd(g,cap[i]) ;
    if(k%g) { printf("-1\n") ; return 0 ; }

    q.push(0) ; mp[0]=0 ;
    while(!q.empty())
    {
        int u=q.front() ; q.pop() ;
        int d=mp[u] ;
        if(decode(u)) { printf("%d\n",mp[u]) ; return 0 ; }
        int tmp[10] ; for(int i=1;i<=n;i++) tmp[i]=now[i] ;

        for(int i=1;i<=n;i++) if(now[i])
        {
            now[i]=0 ;
            int v=encode() ;
            if(!mp.count(v)) { mp[v]=d+1 ; q.push(v) ; }
            now[i]=tmp[i] ;
        }

        for(int i=1;i<=n;i++) if(now[i]!=cap[i])
        {
            now[i]=cap[i] ;
            int v=encode() ;
            if(!mp.count(v)) { mp[v]=d+1 ; q.push(v) ; }
            now[i]=tmp[i] ;
        }

        for(int i=1;i<=n;i++) if(now[i])
            for(int j=1;j<=n;j++) if(j!=i && now[j]!=cap[j])
        {
            if(tmp[i]+tmp[j]>=cap[j])
                now[i]=tmp[i]+tmp[j]-cap[j] ,
                now[j]=cap[j] ;
            else now[i]=0 , now[j]=tmp[i]+tmp[j] ;
            int v=encode() ;
            if(!mp.count(v)) { mp[v]=d+1 ; q.push(v) ; }
            now[i]=tmp[i] ; now[j]=tmp[j] ;
        }
    }
}
