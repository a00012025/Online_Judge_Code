#include<bits/stdc++.h>
#include"lib1455.h"
using namespace std ;
const int maxn=1000+10 ;

int las[maxn],nex[maxn],n,head ;
char s[maxn] ;
int a[maxn] ;

bool check(int x,int y,int z)
{
    return !(a[x]^a[y]^a[z]) ;
}

void CUT(int x)
{
    Cut(las[x]+1,nex[x]+1) ;
    las[nex[x]]=las[x] ;
    nex[las[x]]=nex[x] ;
    if(head==x) head=nex[x] ;
}

void solve(int num)
{
    if(num<=3) return ;
    int st ;
    for(st=head;!check(las[st],st,nex[st]);st=nex[st]) ;
    if(!check(st,nex[st],nex[nex[st]])) CUT(st) ;
    else if(!check(st,las[st],las[las[st]])) CUT(st) ;
    else CUT(nex[st]) ;
    solve(num-1) ;
}

main()
{
    TakeCake() ;
    scanf("%d%s",&n,s) ;
    for(int i=0;i<n;i++) a[i]= s[i]=='G'?1:(s[i]=='R'?2:3) ;
    How_Many_Cut(max(n-3,0)) ;
    for(int i=0;i<n;i++) las[i]=(i-1+n)%n , nex[i]=(i+1)%n ;
    head=0 ;
    solve(n) ;
    Finish() ;
}
