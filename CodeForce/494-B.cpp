#include<bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define MOD 1000000007
using namespace std;

const ULL x=(ULL)123456789 ;
ULL power[100100] ;

void cal_pow()
{
    power[0]=(ULL)1 ;
    for(int i=1;i<100100;i++) power[i]=power[i-1]*x ;
}

char s[100100],t[100100] ;
ULL h[100100] ;

bool st[100100] ;
int last[100100] ;
LL dp[100100],sum[100100] ;
main()
{
    scanf("%s%s",s+1,t+1) ;
    cal_pow() ;
    int len=strlen(s+1) ; h[len+1]=(ULL)0 ;
    for(int i=len;i>=1;i--) h[i]=h[i+1]*x+s[i] ;

    int len2=strlen(t+1) ; ULL val=(ULL)0 ;
    for(int i=len2;i>=1;i--) val*=x , val+=t[i] ;

    for(int i=1;i<=len-len2+1;i++)
    {
        ULL val2=h[i]-h[i+len2]*power[len2] ;
        if(val2==val) st[i]=1 ;
    }

    last[0]=0 ;
    for(int i=1;i<=len;i++)
        last[i]= (i-len2+1>=1 && st[i-len2+1]) ? i-len2+1 : last[i-1] ;

    dp[0]=0 ; sum[0]=0 ;
    for(int i=1;i<=len;i++)
    {
        dp[i]=dp[i-1] ;
        if(last[i])
        {
            dp[i]+=((sum[last[i]-1]+last[i]) % MOD) ; dp[i]%=MOD ;
            sum[i]=(sum[i-1]+dp[i]) % MOD ;
        }
        sum[i]=(sum[i-1]+dp[i]) % MOD ;
    }
    printf("%I64d\n",dp[len]) ;
}
