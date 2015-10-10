#include<stdio.h>
#include<algorithm>
#define LL long long
#define MOD 1000000007
using namespace std;
const int maxn=1000000+10 ;
const int X=13 ;

LL ha[maxn],pw[maxn] ;
inline LL gethash(int l,int r)
{
    LL ret=ha[r]-ha[l-1]*pw[r-l+1]%MOD ;
    return ret<0 ? ret+MOD : ret ;
}

inline bool check(int L1,int R1,int L2,int R2)
{
    return gethash(L1,R1)==gethash(L2,R2) ;
}

char s[maxn] ;
int val[maxn] ;

main()
{
    int n ; scanf("%d%s",&n,s+1) ;
    pw[0]=1 ;
    for(int i=1;i<=n;i++) pw[i]=pw[i-1]*X%MOD , ha[i]=(ha[i-1]*X+s[i]-'a')%MOD ;

    for(int i=0;i<=n;i++) val[i]=-maxn ;
    for(int i=2;i<=(n/2)*2;i++)
    {
        int x=i/2 , y=(i+1)/2 ;
        if(s[n+1-y]!=s[x] || s[n+1-x]!=s[y]) continue ;
        int l=1 , r=min(x,n/2-y+1)+1 ;
        while(r-l>1)
        {
            int mid=(r+l)/2 ;
            if(check(x-mid+1,y+mid-1,n+1-(y+mid-1),n+1-(x-mid+1))) l=mid ;
            else r=mid ;
        }
        int L=(i%2 ? 2*l : 2*l-1) ;
        val[x-l]=max(val[x-l],L+2*(x-l)) ;
    }

    int ans=0 ;
    for(int i=0,ma=-maxn;2*i<=n;i++)
    {
        ma=max(ma,val[i]) ;
        if(!i || check(1,i,n+1-i,n)) ans=max(ans,ma-2*i+i) , ans=max(ans,i) ;
    }
    printf("%d\n",ans) ;
}
