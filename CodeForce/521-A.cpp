#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;

LL power(LL x,int n)
{
    if(n==0) return 1LL ;
    if(n==1) return x ;
    LL tmp=power(x,n/2) ;
    if(n%2) return (tmp*tmp%MOD)*x%MOD ;
    else return tmp*tmp%MOD ;
}

char s[100000+10] ;
int a[4] ;
main()
{
    int n ; scanf("%d%s",&n,s) ;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='A') a[0]++ ;
        if(s[i]=='C') a[1]++ ;
        if(s[i]=='G') a[2]++ ;
        if(s[i]=='T') a[3]++ ;
    }
    int M=max(max(a[0],a[1]),max(a[2],a[3])) ;
    int num=0 ;
    for(int i=0;i<4;i++) if(a[i]==M) num++ ;
    printf("%I64d\n",power(num,n)) ;
}
