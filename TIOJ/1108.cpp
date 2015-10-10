#include<bits/stdc++.h>
using namespace std;
const int maxn=100 ;

char s[maxn],t[maxn] ;

void solve(int x1,int y1,int x2,int y2)
{
    if(x1>y1) return ;
    if(x1==y1) { printf("%c",s[x1]) ; return ; }
    for(int i=x2;i<=y2;i++) if(t[i]==s[x1])
    {
        solve(x1+1,x1+i-x2,x2,i-1) ;
        solve(x1+i-x2+1,y1,i+1,y2) ;
    }
    printf("%c",s[x1]) ;
}

main()
{
    while(scanf("%s%s",s,t)!=EOF)
    {
        int n=strlen(s) , m=strlen(t) ;
        solve(0,n-1,0,m-1) ;
        printf("\n") ;
    }
}
