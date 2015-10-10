#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1000000+10 ;
bool d[maxn] ;
int ans[maxn] ;

int f(int n)
{
    return n*(n+1)*(2*n+1)/6 ;
}

main()
{
    int n = 1001 ;
    memset(ans,-1,sizeof(ans)) ;
    d[0]=1 ;
    for(int i=1;i<=n;i++) for(int j=maxn-1;j>=i*i;j--)
        if(!d[j] && d[j-i*i]) d[j]=1 , ans[j]=i ;

    for(int i=1;i<maxn;i++) if(!d[i]) printf("%d\n",i) ;

//    for(LL i=1,j=0;j>=0;j+=i*i,i++) if(j>pow(10,18)) printf("%lld\n",j) ;

    n=11 ; int cnt=0 ;
    for(int i=f(n);i<=f(n+1);i++) printf("ans[%d]=%d\n",i,ans[i]) ;
//    for(int i=1;i<=m;i++) if(ans[i]==n+1)
//        {printf("ans[%d]=%d\n",i,ans[i]) ; }
//        {printf("%d\n",m-i) ; cnt++ ; } printf("cnt = %d\n",cnt) ;
//    for(int i=100;i<10000;i++)
//        if(ans[i]<ans[i-1]) printf("ans[%d]=%d , ans[%d]=%d\n",i-1,ans[i-1],i,ans[i]) ;
//        printf("ans[%d]=%d\n",i,ans[i]) ;
}
