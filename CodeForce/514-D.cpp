#include<bits/stdc++.h>
#define S second
#define F first
using namespace std;
const int maxn=100000+10 ;

int n,m,k,ans[5],tmp[5] ;
int a[maxn][5],G[5][20][maxn] ;

void build_ST()
{
    for(int i=0;i<m;i++) for(int j=0;(1<<j)<=n;j++)
        for(int k=1;k+(1<<j)-1<=n;k++)
        G[i][j][k]= j ? max(G[i][j-1][k],G[i][j-1][k+(1<<(j-1))]) : a[k][i] ;
}

int query(int id,int l,int r)
{
    int i= (int)log2(r-l+1+0.5) ;
    return max(G[id][i][l],G[id][i][r-(1<<i)+1]) ;
}

bool check(int x,bool b)
{
    if(!x)
    {
        for(int j=0;j<m;j++) ans[j]=0 ;
        return 1 ;
    }
    for(int i=x;i<=n;i++)
    {
        int num=0 ;
        for(int j=0;j<m;j++) num+= (tmp[j]=query(j,i-x+1,i)) ;
        if(num<=k)
        {
            if(b) for(int j=0;j<m;j++) ans[j]=tmp[j] ;
            return 1 ;
        }
    }
    return 0 ;
}

main()
{
    scanf("%d%d%d",&n,&m,&k) ;
    for(int i=1;i<=n;i++) for(int j=0;j<m;j++)
        scanf("%d",&a[i][j]) ;
    build_ST() ;
    int l=0 , r=n+1 ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(check(mid,0)) l=mid ;
        else r=mid ;
    }
    check(l,1) ;
    for(int i=0;i<m;i++) printf("%d%c",ans[i],i==m-1?'\n':' ') ;
}
