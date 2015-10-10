#include<bits/stdc++.h>
using namespace std;
const int maxn=2000+10 ;
bool G[maxn][maxn] ;
struct P{int id,val,num ;}a[maxn];
bool cmp(const P &p,const P &q)
{
    if(p.val!=q.val) return p.val>q.val ;
    else if(p.num!=q.num) return p.num>q.num ;
    else return p.id<q.id ;
}
int pt[maxn] ;
main()
{
    int n,q,m ; scanf("%d%d%d",&n,&q,&m) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=q;j++)
    {
        scanf("%d",&G[i][j]) ;
        if(!G[i][j]) pt[j]++ ;
    }
    for(int i=1;i<=n;i++)
    {
        a[i].id=i ;
        for(int j=1;j<=q;j++) if(G[i][j])
            a[i].num++ , a[i].val+=pt[j] ;
    }
    sort(a+1,a+n+1,cmp) ;

    int i ;
    for(i=1;a[i].id!=m;i++) ;
    printf("%d %d\n",a[i].val,i) ;
}
