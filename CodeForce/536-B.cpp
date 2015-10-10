#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
const int maxn=1000000+10 ;

char s[maxn] ;
int Z[maxn],p[maxn] ;
bool ok[maxn] ;
main()
{
    int n,m ; scanf("%d%d%s",&n,&m,s+1) ;
    for(int i=1;i<=m;i++) scanf("%d",&p[i]) ;
    int len=strlen(s+1) ;
    Z[1]=0 ;
    for(int i=2,L=-1,R=-1;i<=len;i++)
    {
        int i2=i-L+1 ;
        if(R<i)
        {
            for(R=i;R<=len && s[R-i+1]==s[R];R++) ;
            R-- ; L=i ;
            Z[i]=R-i+1 ;
        }
        else if(Z[i2]>=R-i+1)
        {
            for(;R<=len && s[R-i+1]==s[R];R++) ;
            R-- ; L=i ;
            Z[i]=R-i+1 ;
        }
        else  Z[i]=Z[i2] ;
        if(Z[i]==len-i+1) ok[i]=1 ;
    }

    for(int i=1;i<m;i++)
        if(p[i+1]-p[i]+1<=len && !ok[p[i+1]-p[i]+1])
        {printf("0\n") ; return 0 ;}

    LL ans=1LL ;
    for(int i=1,j=0;i<=n;i++)
    {
        while(j<m && p[j+1]<=i) j++ ;
        if(!j || p[j]+len-1<i) ans=(ans*26)%MOD ;
    }
    printf("%I64d\n",ans) ;
}
