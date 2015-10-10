#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
#define MOD 12345
using namespace std;

int n,a[1501] ;
int bit[3][30100] ; ///  0:down , 1:up , 2:rank

int query(int l,int r,int id)
{
    int ret1=0 , ret2=0 ;
    l-- ;
    while(l) ret1=(ret1+bit[id][l])%MOD , l-=lowbit(l) ;
    while(r) ret2=(ret2+bit[id][r])%MOD , r-=lowbit(r) ;
    return (((ret2-ret1)%MOD)+MOD)%MOD ;
}

void modify(int x,int add,int id)
{
    while(x<=30100) bit[id][x]=(bit[id][x]+add)%MOD , x+=lowbit(x) ;
}

main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) , a[i]+=5 ;
        memset(bit,0,sizeof(bit)) ;
        int ans=0 ;
        for(int i=1;i<=n;i++)
        {
            int dn=query(a[i]+1,30100,1) , up=query(1,a[i]-1,0) ;
            ans+= dn+up ;
            ans%=MOD ;
            int x=query(1,a[i]-1,2) , y=query(a[i]+1,30100,2) ;
            modify(a[i],dn+y,0) ; modify(a[i],up+x,1) ;
            modify(a[i],1,2) ;
        }
        printf("%d\n",ans) ;
    }
}
