#include<bits/stdc++.h>
using namespace std;
const int maxn=100000 ;
char s[maxn],t[maxn] ;
main()
{
    freopen("out1","r",stdin) ;
    int n=0 ; char c ;
    while((c=getchar())!=EOF) s[n++]=c ;
    freopen("out2","r",stdin) ;
    n=0 ;
    while((c=getchar())!=EOF) t[n++]=c ;
    for(int i=0;i<maxn;i++) assert(s[i]==t[i]) ;
}
