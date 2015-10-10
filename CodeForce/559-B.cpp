#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10 ;

void solve(char *s,int n)
{
    if(n%2) return ;
    solve(s,n/2) ; solve(s+n/2,n/2) ;
    bool ch=0 ;
    for(int i=0;i<n/2;i++) if(s[i]!=s[i+n/2])
    {
        if(s[i]<s[i+n/2]) return ;
        ch=1 ; break ;
    }
    if(ch) for(int i=0;i<n/2;i++) swap(s[i],s[i+n/2]) ;
}
char s[maxn],t[maxn] ;
main()
{
    scanf("%s%s",s,t) ;
    int n=strlen(s) ;
    solve(s,n) ; solve(t,n) ;
    for(int i=0;i<n;i++) if(s[i]!=t[i])
        {printf("NO\n") ; return 0 ;}
    printf("YES\n") ;
}
