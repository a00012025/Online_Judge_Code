#include<stdio.h>
#include<string.h>
#include<algorithm>
#define LL long long
#define MOD 1000000009
using namespace std;
const int maxn=500000+10 ;
const int X=30007 ;

LL ha[maxn],pw[maxn] ;
inline LL gethash(int l,int r)
{
    return (ha[r]-ha[l]*pw[r-l]%MOD+MOD)%MOD ;
}

bool check(int l,int r,int num)
{
    if(num==1) return 1 ;
    int len=(r-l+1)/num ;
    return gethash(l,r-len)==gethash(l+len,r) ;
}
char s[maxn] ;
int sum[maxn][26] ;
main()
{
    int n ; scanf("%d%s",&n,s+1) ;
    int L=strlen(s+1) ;
    for(int i=0;i<=L;i++)
        pw[i]= i ? pw[i-1]*X%MOD : 1 ,
        ha[i]=(ha[i-1]*X+s[i]-'a')%MOD ;
    for(int j=1;j<=L;j++) for(int i=0;i<26;i++)
        sum[j][i]=sum[j-1][i]+(s[j]=='a'+i) ;

    int Q ; scanf("%d",&Q) ;
    while(Q--)
    {
        int l,r ; scanf("%d%d",&l,&r) ;
        int len=r-l+1 , g=len ,ans=0 ;
        for(int i=0;i<26;i++) g=__gcd(g,sum[r][i]-sum[l-1][i]) ;
        for(int i=1;i*i<=g;i++)
        {
            if(check(l,r,i)) ans=max(ans,i) ;
            if(check(l,r,g/i)) ans=max(ans,g/i) ;
        }
        printf("%d\n",len/ans) ;
    }
}
