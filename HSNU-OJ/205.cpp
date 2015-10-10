#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
#define MOD 12345
using namespace std;
const int maxn=1500+10 ;

int n,a[maxn] ;
int bit[3][maxn] ;

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
    while(x<maxn) bit[id][x]=(bit[id][x]+add)%MOD , x+=lowbit(x) ;
}

vector<int> v ;
main()
{
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]) , v.push_back(a[i]) ;
    sort(v.begin(),v.end()) ;
    v.resize(unique(v.begin(),v.end())-v.begin()) ;

    int ans=0 ;
    for(int i=1;i<=n;i++)
    {
        a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1 ;
        int dn=query(a[i]+1,maxn-1,1) , up=query(1,a[i]-1,0) ;
        ans+= dn+up ;
        ans%=MOD ;
        int x=query(1,a[i]-1,2) , y=query(a[i]+1,maxn-1,2) ;
        modify(a[i],dn+y,0) ; modify(a[i],up+x,1) ;
        modify(a[i],1,2) ;
    }
    printf("%d\n",ans) ;
}
