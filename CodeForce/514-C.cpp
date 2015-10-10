#include<bits/stdc++.h>
#define ULL unsigned long long
#define LL long long
#define MOD 1000000007
using namespace std;
const LL x=123LL ;
const int maxn=600000+10 ;

LL power[maxn] ;
void get_pow()
{
    power[0]=1LL ;
    for(int i=1;i<maxn;i++) power[i]=power[i-1]*x%MOD ;
}

set<LL> st ;
char s[maxn] ;
main()
{
    get_pow() ;
    int n,m ; scanf("%d%d",&n,&m) ;
    while(n--)
    {
        scanf("%s",s) ; int len=strlen(s) ;
        LL h=0LL ;
        for(int i=0;i<len;i++) h=(h*x+(s[i]-'a'))%MOD ;
        st.insert(h) ;
    }
    while(m--)
    {
        scanf("%s",s) ; int len=strlen(s) ;
        LL h=0LL ;
        for(int i=0;i<len;i++) h=(h*x+(s[i]-'a'))%MOD ;
        bool ok=0 ;
        for(int i=0;!ok && i<len;i++)
        {
            LL tmp=power[len-1-i]*(s[i]-'a')%MOD ;
            h-= tmp ;
            if(h<0) h+=MOD ;
            for(int z=0;!ok && z<3;z++) if(s[i]!=z+'a')
            {
                ULL tmp2=power[len-1-i]*(z)%MOD ;
                if(st.count((h+tmp2)%MOD)) ok=1 ;
            }
            h+= tmp ; h%=MOD ;
        }
        if(ok) printf("YES\n") ;
        else printf("NO\n") ;
    }
}
