#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;

char s[maxn] ;
int a[maxn],sum[maxn] ;
main()
{
    scanf("%s",s) ;
    int n=1 , len=strlen(s) ;
    for(int i=0;i<len;i++) a[(i && s[i]!=s[i-1]) ? ++n : n]++ ;
    LL dif=0,s1=0,s2=0 ; // dif = even - odd
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i] , dif-=(a[i]+1)/2 ;
        (i%2 ? s1 : s2)+=a[i] ;
    }
    LL tot=(LL)len*(len+1)/2-s1*s2 ;
    for(int i=1,num1=0,num2=0;i<=n;i+=2) if(a[i]%2)
    {
        if(sum[i]%2) dif+=num1-num2 ;
        else dif+=num2-num1 ;
        (sum[i-1]%2 ? num1 : num2)++ ;
    }
    for(int i=2,num1=0,num2=0;i<=n;i+=2) if(a[i]%2)
    {
        if(sum[i]%2) dif+=num1-num2 ;
        else dif+=num2-num1 ;
        (sum[i-1]%2 ? num1 : num2)++ ;
    }
    printf("%I64d %I64d\n",(tot+dif)/2,(tot-dif)/2) ;
}
