#include<stdio.h>
#include<set>
#define LL long long
using namespace std;
set<LL> restrict ;
LL ans[200],now[200] ;
int maxd,found ;

LL gcd(LL x,LL y)
{
    return y==0 ? x : gcd(y,x%y) ;
}

LL get_first(LL x,LL y)
{
    if(y%x==0) return y/x ;
    else return (y/x)+1LL ;
}

bool better()
{
    for(int i=maxd;i>=1;i--) if(ans[i]!=now[i]) return now[i]<ans[i] ;
    return 0 ;
}

bool iddfs(int num,LL from,LL a,LL b)
{
        //printf("%d,%lld\n",num,now[num]) ;
    if(num==maxd)
    {
        if(a==0)
        {
            if(!found || better())
                for(int i=1;i<=num;i++) ans[i]=now[i] ;
            found=1 ;
            return 1 ;
        }
        else return 0 ;
    }
    else if(a==0) return 0 ;
    bool ret=0 ;
    from=max(from,get_first(a,b)) ;
    for(LL i=from;;i++)
    {
        if(a*i > b*(maxd-num)) break ;
        if(maxd-num>1 && a*i == b*(maxd-num)) break ;
        if(restrict.count(i)) continue ;
        LL a2=i*a-b , b2=b*i , g=gcd(a2,b2) ;
        now[num+1]=i ; //printf("now[%d]=%d\n",num+1,i) ;
        if(iddfs(num+1,i+1,a2/g,b2/g)) ret=1 ;
    }
    return ret ;
}

main()
{
    int T,tc=0;
    scanf("%d",&T) ;
    while(T--)
    {
        int k ;
        LL a,b ;
        scanf("%lld%lld%d",&a,&b,&k) ;
        restrict.clear() ;
        while(k--)
        {
            LL m ; scanf("%lld",&m) ;
            restrict.insert(m) ;
        }
        found=0 ;
        for(maxd=1;;maxd++)
        {
            if(iddfs(0,get_first(a,b),a,b)) break ;
        }
        printf("Case %d: %lld/%lld=",++tc,a,b) ;
        for(int i=1;i<=maxd;i++) printf("1/%lld%c",ans[i],i==maxd?'\n':'+') ;
    }
}
