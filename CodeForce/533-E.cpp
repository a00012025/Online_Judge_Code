#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

char s[maxn],t[maxn] ;
main()
{
    int n ; scanf("%d%s%s",&n,s+1,t+1) ;
    int x=-1 , y=-1 ;
    for(int i=1;i<=n;i++) if(s[i]!=t[i])
        {x=i ; break ;}
    for(int i=n;i>=1;i--) if(s[i]!=t[i])
        {y=i ; break ;}

    int ans=0 , i ;
    for(i=x;i<y;i++) if(s[i]!=t[i+1]) break ;
    if(i==y) ans++ ;
    for(i=x;i<y;i++) if(t[i]!=s[i+1]) break ;
    if(i==y) ans++ ;

    printf("%d\n",ans) ;
}
