#include<bits/stdc++.h>
#define DB double
using namespace std;
const int maxn=100000+10 ;
const DB eps=1e-9 ;
void ex1(){printf(">\n") ; exit(0) ;}
void ex2(){printf("<\n") ; exit(0) ;}

char s[maxn],t[maxn] ;
int a[maxn] ;
main()
{
    int n,m ; scanf("%s%s",s,t) ;
    n=strlen(s) , m=strlen(t) ;
    for(int i=0;i<n;i++) a[n-1-i]+=s[i]-'0' ;
    for(int i=0;i<m;i++) a[m-1-i]-=t[i]-'0' ;
    for(int i=maxn-1;i>=2;i--) if(a[i])
    {
        if(a[i]>=2) ex1() ;
        if(a[i]<=-2) ex2() ;
        a[i-1]+=a[i] ; a[i-2]+=a[i] ;
        a[i]=0 ;
    }
    DB x=a[1]*(sqrt(5)+1)/2+a[0] ;
    if(x>eps) ex1() ;
    if(x<-eps) ex2() ;
    printf("=\n") ;
}
