#include<bits/stdc++.h>
#define lowbit(x) (x&-x)
using namespace std;
const int maxn=1000+10 ;

int n,bit[maxn][maxn] ;

void modify(int x,int y,int val)
{
    for(int i=x;i<=n;i+=lowbit(i))
        for(int j=y;j<=n;j+=lowbit(j))
        bit[i][j]=max(bit[i][j],val) ;
}

int query(int x,int y)
{
    int ret=0 ;
    for(int i=x;i;i-=lowbit(i))
        for(int j=y;j;j-=lowbit(j))
        ret=max(ret,bit[i][j]) ;
    return ret ;
}

int x[maxn*maxn],y[maxn*maxn] ;
main()
{
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
    {
        int num ; scanf("%d",&num) ;
        x[num]=i ; y[num]=j ;
    }
    for(int i=1;i<=n*n;i++)
        modify(x[i],y[i],query(x[i],y[i])+1) ;
    printf("%d\n",query(n,n)) ;
}
