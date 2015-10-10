#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
const int maxn=100000+10 ;

LL pow(LL x,LL n,int mod)
{
    if(n<=1) return n ? x : 1LL ;
    LL t=pow(x,n/2,mod) ;
    if(n&1) return (t*t%mod)*x%mod ;
    else return t*t%mod ;
}
LL pw[maxn] ;

char s[maxn],t[maxn] ;
int n,d[maxn] ;
string st[maxn] ;
LL len[maxn],val[maxn] ;
main()
{
    pw[0]=1 ;
    for(int i=1;i<maxn;i++) pw[i]=pw[i-1]*10%MOD ;
    scanf("%s%d",s,&n) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",t) ;
        d[i]=t[0]-'0' ;
        st[i]=string(t+3,t+strlen(t)) ;
    }
    for(int i=0;i<10;i++) len[i]=1 , val[i]=i ;
    for(int i=n;i>=1;i--)
    {
        int sz=st[i].size() ;
        LL l2=0LL , val2=0LL ;
        for(int j=sz-1;j>=0;j--)
        {
            val2=(val2+val[st[i][j]-'0']*pow(10,l2,MOD))%MOD ;
            l2=(l2+len[st[i][j]-'0'])%(MOD-1) ;
        }
        len[d[i]]=l2 , val[d[i]]=val2 ;
    }
    LL ans=0LL ;
    for(int i=strlen(s)-1,nowl=0;i>=0;i--)
    {
        ans+=val[s[i]-'0']*pow(10,nowl,MOD) ;
        ans%=MOD ;
        nowl=(nowl+len[s[i]-'0'])%(MOD-1) ;
    }
    printf("%I64d\n",ans) ;
}
