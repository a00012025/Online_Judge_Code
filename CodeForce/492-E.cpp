#include<bits/stdc++.h>
using namespace std;
const int maxn=100001 ;
int x[maxn],y[maxn],cnt[10*maxn] ;
int k[10*maxn] ;
main()
{
    int n,m,dx,dy ; scanf("%d%d%d%d",&n,&m,&dx,&dy) ;
    for(int i=1;i<=m;i++) scanf("%d%d",&x[i],&y[i]) ;
    int nowx=0 , nowy=0 ;
    for(int i=1;i<=n;i++)
    {
        k[nowx]=nowy ;
        nowx=(nowx+dx)%n ;
        nowy=(nowy+dy)%n ;
    }
    for(int i=1;i<=m;i++)
    {
        int val= y[i]-k[x[i]] ;
        if(val<0) val+=n ;
        cnt[val]++ ;
    }
    int M=-1 , id ;
    for(int i=0;i<n;i++) if(cnt[i]>M) M=cnt[id=i] ;

    for(int i=1;i<=m;i++)
    {
        int val= y[i]-k[x[i]] ;
        if(val<0) val+=n ;
        if(val==id) { printf("%d %d\n",x[i],y[i]) ; return 0 ; }
    }
}
