#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1000000+10 ;

int a[maxn] ;
LL sum[maxn][4][4] ;
LL sum0[maxn][4] ;
int now[4] ;
main()
{
    map<char,int> mp={ {'c',0},{'h',1},{'e',2},{'f',3} } ;
    int n=0 ;
    while(1)
    {
        char c=getchar() ;
        if(c<'a' || c>'z') break ;
        a[++n]=mp[c] ;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<4;j++) sum0[i][j]= j==a[i] ? sum0[i-1][j]+1 : sum0[i-1][j] ;
        for(int j=0;j<4;j++) for(int k=0;k<4;k++)
            if(j!=k)
            sum[i][j][k]= k==a[i] ? sum[i-1][j][k]+now[j] : sum[i-1][j][k] ;
        now[a[i]]++ ;
    }

    int Q ; scanf("%d",&Q) ;
    while(Q--)
    {
        char s[3],t[3] ; int l,r ;
        scanf("%s%s%d%d",s,t,&l,&r) ;
        int x=mp[s[0]] , y=mp[t[0]] ;
        LL ans=sum[r][x][y]-sum[l-1][x][y] ;
        ans-=sum0[l-1][x]*(sum0[r][y]-sum0[l-1][y]) ;
        printf("%lld\n",ans) ;
    }
}
