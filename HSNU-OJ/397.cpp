#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;

int fail[2*maxn] ;
int s[2*maxn],t[2*maxn] ;

main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++) scanf("%d",&s[i]) ;
    for(int i=1;i<=m;i++) scanf("%d",&t[i]) ;
    for(int i=n+1;i<=n+m;i++) s[i]=s[i-n] ;
    fail[1]=0 ;
    int j=0 ;
    for(int i=2;i<=m;i++)
    {
        while(j && t[j+1]!=t[i]) j=fail[j] ;
        if(t[j+1]==t[i]) j++ ;
        fail[i]=j ;
    }
    int num=0 ; j=0 ;
    for(int i=1;i<m+n;i++)
    {
        while(j && t[j+1]!=s[i]) j=fail[j] ;
        if(t[j+1]==s[i]) j++ ;
        if(j==m) { num++ ; j=fail[j] ; }
    }
    if(!num) printf("QAQ\n") ;
    else
    {
        int g=__gcd(num,n) ;
        printf("%d/%d\n",num/g,n/g) ;
    }
}
