#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+10 ;

char s[maxn] ;
main()
{
    int n,k ; scanf("%s%d",s,&k) ;
    n=strlen(s) ;
    if(n%k){printf("NO\n") ; return 0 ;}
    k=n/k ;
    for(int i=0;i<n;i++)
    {
        int x=i/k*k , y=x+k-1 ;
        if(s[i]!=s[x+y-i]){printf("NO\n") ; return 0 ;}
    }
    printf("YES\n") ;
}
