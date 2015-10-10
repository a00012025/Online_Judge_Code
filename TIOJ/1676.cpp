#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=500000+10 ;

LL a[maxn] ;
LL dp[maxn],s[maxn],A[maxn],B[maxn] ;
int dq[maxn] ;

int cmp(LL a1,LL b1,LL a2,LL b2,int i)
{
    if(a1==a2) return b1==b2 ? (b1>b2 ? 1 : -1) : 0 ;
    if(a1>a2)
    {
        if(b1>=b2) return b1>b2 ? 1 : 0 ;
        LL q=(b2-b1)/(a1-a2) ;
        if(q*(a1-a2)==(b1-b2)) return 0 ;
        return q>=i ? -1 : 1 ;
    }
    else return cmp(a2,b2,a1,b1,i)*(-1) ;
}

main()
{
    int n,k ; scanf("%d%d",&n,&k) ;
    for(int i=1;i<=n;i++) scanf("%I64d",&a[n+1-i]) ;
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i] ;
    dp[0]=0LL ; A[0]=B[0]=0LL ;
    int l=0 , r=1 ; dq[0]=0 ;
    for(int i=1;i<=n;i++)
    {
        while(dq[l]+k<i) l++ ;
        while(l+1<r &&
              cmp(A[dq[l]],B[dq[l]],A[dq[l+1]],B[dq[l+1]],i)<=0)
                l++ ;
        dp[i]=-((LL)i)*((LL)i)+A[dq[l]]*i+B[dq[l]] ;
        A[i]=(LL)2*i ; B[i]=dp[i]+s[i]-((LL)i)*((LL)i) ;
        while(l+1<r && A[i]*(B[dq[r-1]]-B[dq[r-2]] )
              +B[i]*(A[dq[r-2]]-A[dq[r-1]]) <=
              A[dq[r-2]]*B[dq[r-1]]-A[dq[r-1]]*B[dq[r-2]] ) r-- ;
        dq[r++]=i ;
    }
    printf("%I64d\n",dp[n]) ;
}
