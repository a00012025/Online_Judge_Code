#include<bits/stdc++.h>
#define DB double
using namespace std;
const int maxn=50000+10 ;

struct P
{
    int id ; DB val;
    bool operator < (const P &rhs) const
    {
        return val>rhs.val ;
    }
}p[maxn];

int v[maxn] , LEN=10000000 ;
void solve1(int n)
{
    int sz=1 ;
    v[0]=1 ;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<sz;j++) v[j]*=2 ;
        for(int j=0;j<sz;j++) if(v[j]>=LEN)
        {
            v[j+1]+=v[j]/LEN ;
            v[j]%=LEN ;
            if(j==sz-1) sz++ ;
        }
    }
    for(int i=sz-1;i>=0;i--)
    {
        if(i==sz-1) printf("%d",v[i]) ;
        else printf("%07d",v[i]) ;
    }
    printf("\n") ;
}

DB a[maxn] ;
bool used[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    solve1(n) ;
    for(int i=1;i<=n;i++) scanf("%lf",&a[i]) , p[i]=(P){i,a[i]} ;
    DB now=0.0 ;
    for(int i=1;i<=n;i++) if(a[i]>now)
        printf("%d\n",i) , used[i]=1 , now=a[i] ;
    sort(p+1,p+n+1) ;
    for(int i=1;i<=n;i++) if(!used[p[i].id])
        printf("%d\n",p[i].id) ;
}
