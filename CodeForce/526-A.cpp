#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10 ;

char s[maxn] ;
int n ;
bool check()
{
    for(int i=1;i<=n;i++) for(int j=1;i+4*j<=n;j++)
    {
        bool ok=1 ;
        for(int k=0;k<5;k++) if(s[i+k*j]!='*')
            {ok=0 ; break ;}
        if(ok) return 1 ;
    }
    return 0 ;
}

main()
{
    scanf("%d%s",&n,s+1) ;
    if(check()) printf("yes\n") ;
    else printf("no\n") ;
}
