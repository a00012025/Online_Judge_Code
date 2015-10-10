#include<bits/stdc++.h>
#include"interactive/119.h"
#define LL long long
using namespace std;

int n,A,B ;

int solve(int l,int r)
{
    if(l==r) return l ;
    int len=r-l+1 ;
    int num= ( ((LL)len)*((LL)B)+((LL)A) )/((LL)A+B) ;
    if(Ask('N',l+num)) return solve(l,l+num-1) ;
    else return solve(l+num,r) ;
}

main()
{
    Init(&n,&A,&B) ;
    Answer(solve(1,n)) ;
}
