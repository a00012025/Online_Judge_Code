#include<stdio.h>
#include<vector>
#define LL long long
using namespace std;
LL power(LL a,int b)
{
    LL ret=1 ;
    while(b--) ret*=a ;
    return ret ;
}

int digit(LL n,int pos)
{
    LL x=n/power(10,pos) ;
    x*=10 ;
    LL y=n/power(10,pos-1) ;
    return y-x ;
}

bool ok(LL n)
{
    if(n<10) return true ;
    vector<int> v ;
    while(n) {v.push_back(n%10) ; n/=10 ;}
    for(int i=0;i<v.size();i++) if(v[i]!=v[v.size()-1-i]) return false ;
    return true ;
}

LL rev(LL n)
{
    LL k=1 , ret=0 ; int num=0 ;
    while(power(10,num)-1<n) num++ ;
    for(int i=1;i<=num;i++) ret+=digit(n,i)*power(10,num-i) ;
    return ret ;
}

main()
{
    int T,tc=0;
    scanf("%d",&T);
    while(T--)
    {
        int ans=0 ;
        LL n ;
        scanf("%lld",&n) ; LL m=n ;
        while(ans==0 || !ok(n))
        {
            n+=rev(n) ;
            ans++ ;
        }
        printf("%d %lld\n",ans,n) ;
    }
}
