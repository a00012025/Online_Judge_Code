#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=200+5 ;

int d[maxn][maxn] ;
LL a[maxn],s[maxn] ;

int n ;
LL sum(int l,int r)
{
    if(l<=r) return s[r]-(l ? s[l-1] : 0LL) ;
    return s[n-1]-(l?s[l-1]:0LL)+s[r] ;
}

LL dp(int l,int r)
{
    if(l==r) return a[l] ;
    if(d[l][r]!=-1) return d[l][r] ;
    return d[l][r]=max(a[l]+sum((l+1)%n,r)-dp((l+1)%n,r)
                       ,a[r]+sum(l,(r-1+n)%n)-dp(l,(r-1+n)%n)) ;
}

main()
{
    scanf("%d",&n) ;
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]) , s[i]= (i?s[i-1]+a[i]:a[i]) ;
    memset(d,-1,sizeof(d)) ;

    int num=0 ; LL M=0 ;
    for(int i=0;i<n;i++)
    {
        LL val=s[n-1]-dp((i+1)%n,(i-1+n)%n) ;
        if(2*val >= s[n-1]) num++ ;
        M=max(M,val) ;
    }
    if(n==1) printf("1 %lld\n",a[0]) ;
    else printf("%d %lld\n",num,M) ;
}
