#include"lib1044.h"
#include<bits/stdc++.h>
using namespace std;

void solve(int l,int r)
{
    if(l==r) Report(l) ;
    int mid=(l+r)/2 ;
    if(Guess(mid)) solve(l,mid) ;
    else solve(mid+1,r) ;
}

main()
{
    int n=Initialize() ;
    solve(1,n) ;
}
