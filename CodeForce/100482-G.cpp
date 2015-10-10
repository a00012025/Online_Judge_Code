#include<stdio.h>
#include<map>
#include<algorithm>
#define LL long long
using namespace std;
const LL maxn=1000000007 ;
typedef struct {LL x,y ;} P ;
P rec(LL a,LL b)
{
    if(a==b || b==0) return (P){(LL)1,(LL)0} ;
    P p=rec(b,a%b) ;
    return (P){p.y%maxn,(p.x-(a/b)*p.y)%maxn} ;
}
main()
{
    int T,tc=0;
    map<int,int> m ;
    scanf("%d",&T) ;
    while(++tc && T--)
    {
        int n ;
        scanf("%d",&n) ;
        m.clear() ;
        for(int i=1;i<=n;i++)
        {
            int a ; scanf("%d",&a) ;
            if(!m.count(a)) m[a]=1 ;
            else m[a]++ ;
        }
        map<int,int>::iterator it ; int ans=0;
        for(it=m.begin();it!=m.end();it++)
        {
            if(!(it->second)) continue ;
            LL a=(LL)(it->first),b ;
            P now=rec(maxn,a) ;
            b=now.y ; while(b<0) b+=maxn ;
            b=b%maxn ; b=(int)b ;
            if(!m.count(b) || !m[b]) continue ;
            if(a!=b)
            {
                int x=min(m[a],m[b]) ;
                ans+=x ; m[a]-=x ; m[b]-=x ;
            }
            else
            {
                int x=m[a]/2 ;
                ans+=x ; m[a]-=2*x ;
            }
        }
        printf("Case #%d: %d\n",tc,ans) ;
    }
}
