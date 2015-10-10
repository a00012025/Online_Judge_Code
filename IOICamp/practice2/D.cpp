#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+30 ;

int G1[20][maxn],G2[20][maxn],a[maxn] ;
void build_ST(int n)
{
    for(int i=0;(1<<i)<=n;i++) for(int j=1;j+(1<<i)-1<=n;j++)
        G1[i][j]= i==0?a[j]:max(G1[i-1][j],G1[i-1][j+(1<<(i-1))]) ,
        G2[i][j]= i==0?a[j]:min(G2[i-1][j],G2[i-1][j+(1<<(i-1))]) ;
}

int query1(int l,int r)
{
    int len=r-l+1 ;
    int id=(int)log2(len+0.5) ;
    return max(G1[id][l],G1[id][r-(1<<id)+1])-min(G2[id][l],G2[id][r-(1<<id)+1]) ;
}

int le[maxn],now[maxn],num ;
int a2[maxn] ;
void precal(int n)
{
    for(int i=1;i<=n;i++) a2[i]=a[i] ;
    sort(a2+1,a2+n+1) ;
    int n2=unique(a2+1,a2+n+1)-a2 ;// printf("n2=%d\n",n2) ;
    for(int i=1;i<=n;i++) a[i]=lower_bound(a2+1,a2+n2,a[i])-a2 ;

    memset(now,0,sizeof(now)) ;
    num=0 ;
    int j=n+1 ;
    for(int i=n;i>=1;i--)
    {
        while(!num && j>1)
        {
            now[a[j-1]]++ ; j-- ;
            if(now[a[j]]==4) { num=1 ; break ; }
        }
        le[i]= num ? j : -1 ;// printf("le[%d]=%d\n",i,le[i]) ;
        now[a[i]]-- ;
        if(now[a[i]]==3) num-- ;
    }
}

bool query2(int l,int r)
{
    return l>le[r] ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n,m ; scanf("%d%d",&n,&m) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        build_ST(n) ;
        precal(n) ;
        while(m--)
        {
            int l,r ; scanf("%d%d",&l,&r) ;
            if(query1(l,r)>51400) printf("N") ;
            else if(!query2(l,r)) printf("N") ;
            else printf("Y") ;
        }
        printf("\n") ;
    }
}
