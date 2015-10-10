#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=4000+10 ;

char s[maxn],t[maxn] ;
int a[26],b[26],num[26][26] ;
bool add(int x,int y)
{
    if(a[x]!=-1 && a[x]!=y) return 0 ;
    if(b[y]!=-1 && b[y]!=x) return 0 ;
    a[x]=y ; b[y]=x ;
    num[x][y]++ ;
    return 1 ;
}

void sub(int x,int y)
{
    num[x][y]-- ;
    if(!num[x][y]) a[x]=b[y]=-1 ;
}

int n,m ;
LL solve(int dif)
{
    memset(a,-1,sizeof(a)) ;
    memset(b,-1,sizeof(b)) ;
    memset(num,0,sizeof(num)) ;
    int st=(dif>=0 ? 0 : -dif) ;
    LL ret=0LL ;
    for(int i=st,j=st;i<n && i+dif<m;i++)
    {
        if(j<i) j=i ;
        while(j<n && j+dif<m && add(s[j]-'a',t[j+dif]-'a')) j++ ;
        int maxl=min(n-i,m-(i+dif)) , l=j-i+1 ;
        ret+=(maxl+l)*(maxl-l+1)/2 ;
        sub(s[i]-'a',t[i+dif]-'a') ;
    }
    return ret ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%s%s",s,t) ;
        n=strlen(s) ; m=strlen(t) ;
        LL ans=0LL ;
        for(int i=-n+1;i<m;i++) ans+=solve(i) ;
        printf("%lld\n",ans) ;
    }
}
