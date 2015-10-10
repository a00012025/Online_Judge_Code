#include<bits/stdc++.h>
using namespace std;
const int maxn=4000+5 ;
struct P
{
    int c,v,t ;
    bool operator < (const P &rhs) const
    {
        return t<rhs.t ;
    }
}a[maxn];
int n,p ;
int dpl[maxn][maxn],dpr[maxn][maxn] ;
int pos[maxn] ;
void build()
{
    sort(a+1,a+n+1) ;
    for(int i=1;i<=n;i++) pos[i]=a[i].t ;
    for(int i=1;i<=n;i++)
    {
        if(i==1 || (a[i-1].t-1)/p != (a[i].t-1)/p)
            for(int j=a[i].c;j<maxn;j++)
                dpl[i][j]=a[i].v ;
        else for(int j=0;j<maxn;j++)
            dpl[i][j]=(j>=a[i].c ?
            max(dpl[i-1][j-a[i].c]+a[i].v,dpl[i-1][j]) :
                dpl[i-1][j]) ;
    }
    for(int i=n;i>=1;i--)
    {
        if(i==n || (a[i+1].t-1)/p != (a[i].t-1)/p)
            for(int j=a[i].c;j<maxn;j++)
                dpr[i][j]=a[i].v ;
        else for(int j=0;j<maxn;j++)
            dpr[i][j]=(j>=a[i].c ?
            max(dpr[i+1][j-a[i].c]+a[i].v,dpr[i+1][j]) :
                dpr[i+1][j]) ;
    }
}

main()
{
    scanf("%d%d",&n,&p) ;
    for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i].c,&a[i].v,&a[i].t) ;
    build() ;
    int Q ; scanf("%d",&Q) ;
    while(Q--)
    {
        int t,c ; scanf("%d%d",&t,&c) ;
        int l=max(t-p+1,1) , r=t ;
        l=lower_bound(pos+1,pos+n+1,l)-pos ;
        r=upper_bound(pos+1,pos+n+1,r)-pos-1 ;
        if(r<l || l==n+1){printf("0\n") ; continue ;}

        if((a[l].t-1)/p == (a[r].t-1)/p)
        {
            printf("%d\n",(r==n||(a[r+1].t-1)/p != (a[r].t-1)/p)
                   ? dpr[l][c] : dpl[r][c]) ;
            continue ;
        }
        int ans=0 ;
        for(int i=0;i<=c;i++) ans=max(ans,dpr[l][i]+dpl[r][c-i]) ;
        printf("%d\n",ans) ;
    }
}
