#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10 ;

char s[maxn] ;
main()
{
    int n,a=0,b=0 ; scanf("%d%s",&n,s+1) ;
    for(int i=1;i<=n;i++) (s[i]=='0'?a:b)++ ;
    printf("%d\n",a>=b?a-b:b-a) ;
}
