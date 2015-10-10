#include<bits/stdc++.h>
#define LL long long
#define DB double
using namespace std;
const int maxn=500000+100 ;

char s[maxn] ;
int n,a[maxn] ;
LL sum1[maxn],sum2[maxn],sum[maxn] ;
main()
{
    scanf("%s",s+1) ;
    set<char> st={'A','E','I','O','U','Y'} ;
    n=strlen(s+1) ;
    for(int i=1;i<=n;i++)
        a[i]= st.count(s[i]) ? 1 : 0 ;

    sum[0]=sum1[0]=0LL ;
    for(int i=1;i<=n;i++)
        sum1[i]=sum1[i-1]+i*a[i] ,
        sum[i]=sum[i-1]+a[i] ;
    sum2[n+1]=0LL ;
    for(int i=n;i>=1;i--) sum2[i]=sum2[i+1]+(n+1-i)*a[i] ;

    DB ans=0.0 ;
    for(int len=1;len<=n;len++)
    {
        LL add=0LL ;
        if(n>=2*len-1)
        {
            add+=sum1[len-1] ;
            add+=sum2[n-len+2] ;
            add+=(sum[n-len+1]-sum[len-1])*len ;
        }
        else
        {
            int t=n-len ;
            add+=sum1[t] ;
            add+=sum2[n-t+1] ;
            add+=(sum[n-t]-sum[t])*(n-len+1) ;
        }
        DB add2= ((DB)add)/((DB)len) ;
        ans+=add2 ;
    }
    printf("%.10f\n",ans) ;
}
