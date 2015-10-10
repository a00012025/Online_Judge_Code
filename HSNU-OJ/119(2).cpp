#include<bits/stdc++.h>
#include"interactive/119.h"
using namespace std;

int a[1000000],n,A,B ;

int f(int x)
{
    if(x<0) return 0 ;
    if(x==0) return 1 ;
    if(a[x]) return a[x] ;
    return a[x]=max(f(x-A)+f(x-B),1) ;
}

main()
{
    Init(&n,&A,&B) ;
    int now=0 ;
    while(f(now)<n) now++ ;
    int l=1 , r=n ;
    while(r-l>0)
    {
        while(f(now)>=r-l+1) now-- ; now++ ;
        if(Ask('N',l+f(now-A))) r=l+f(now-A)-1 ;
        else l=l+f(now-A) ;
    }
    Answer(l) ;
}
