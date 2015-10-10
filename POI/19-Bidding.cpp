#include<bits/stdc++.h>
#include"cliclib.h"
#define pii pair<int,int>
#define F first
#define S second
#define mkp(x,y) make_pair(x,y)
using namespace std;

inline pii cal(const pii &p,int type)
{
    if(type==1) return mkp(1,p.F+p.S) ;
    if(type==2) return mkp(2*p.F,p.S) ;
    return mkp(3*p.F,p.S) ;
}

map<pii,int> mp ;

int n ;

int solve(const pii &p)
{
    if(p.F+p.S >= n) return 0 ;
    if(mp.count(p)) return mp[p] ;
    for(int i=1;i<=3;i++)
        if(solve(cal(p,i))==0) return mp[p]=i ;
    return mp[p]=0 ;
}

main()
{
    n=inicjuj() ;
    int nowx=1 , nowy=0 ;
    while(1)
    {
        int type=solve(mkp(nowx,nowy)) ;
        alojzy(type) ;
        pii tmp=cal(mkp(nowx,nowy),type) ;
        type=bajtazar() ;
        tmp=cal(tmp,type) ;
        nowx=tmp.F , nowy=tmp.S ;
    }
}
