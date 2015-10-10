#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10 ;

char s[maxn] ;
int a[maxn] ;
main()
{
    int n,m ; scanf("%s%d",s+1,&m) ;
    n=strlen(s+1) ;
    for(int i=1;i<=m;i++) scanf("%d",&a[i]) ;
    sort(a+1,a+m+1) ;
    for(int i=1,j=1;2*i<=n+1;i++)
    {
        while(j<=m && a[j]<=i) j++ ;
        if((j-1)%2) swap(s[i],s[n+1-i]) ;
    }
    printf("%s\n",s+1) ;
}
