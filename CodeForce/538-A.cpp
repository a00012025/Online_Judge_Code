#include<bits/stdc++.h>
using namespace std;
const int maxn=200 ;

char s[maxn] ;
char t[maxn]="CODEFORCES" ;
main()
{
    scanf("%s",s) ;
    int n=strlen(s) ;
    if(n>10) for(int i=0;i<=10;i++)
    {
        bool ok=1 ;
        for(int j=0;j<i;j++) if(t[j]!=s[j]) ok=0 ;
        for(int j=i;j<10;j++) if(t[j]!=s[n-10+j]) ok=0 ;
        if(ok) { printf("YES\n") ; return 0 ; }
    }
    printf("NO\n") ;
}
