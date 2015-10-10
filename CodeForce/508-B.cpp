#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

char s[maxn] ;
int a[maxn],n ;
void ok(int i){swap(s[i],s[n]) ; printf("%s\n",s+1) ; exit(0) ;}
main()
{
    scanf("%s",s+1) ;
    n=strlen(s+1) ;
    for(int i=1;i<=n;i++) a[i]=s[i]-'0' ;
    bool eve=0 ;
    for(int i=1;i<n;i++) if(!(a[i]%2))
    {
        eve=1 ;
        if(a[i]<a[n]) ok(i) ;
    }
    if(!eve){printf("-1\n") ; return 0 ;}
    for(int i=n-1;;i--) if(!(a[i]%2)) ok(i) ;
}
