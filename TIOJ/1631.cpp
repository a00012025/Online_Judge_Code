#include<bits/stdc++.h>
#include"lib1631.h"
#define LL long long
using namespace std;
const int maxn=50000+10 ;

struct pt{int x,y,c ;};

pt operator + (const pt &a,const pt &b) { return (pt){a.x+b.x,a.y+b.y,0} ; }
pt operator - (const pt &a,const pt &b) { return (pt){a.x-b.x,a.y-b.y,0} ; }
LL cross(const pt &a,const pt &b) { return (LL)a.x*b.y-(LL)a.y*b.x ; }

bool in_triangle(const pt &p,const pt &a,const pt &b,const pt &c)
{
    if(cross(b-a,c-a)>0) return
        cross(b-a,p-a)>0 && cross(c-b,p-b)>0 && cross(a-c,p-c)>0 ;
    else return
        cross(c-a,p-a)>0 && cross(b-c,p-c)>0 && cross(a-b,p-b)>0 ;
}

int n,m ;
vector<int> vec[maxn*10] ;
int vcnt=0 ;
pt p[2*maxn] ;

int tmp[2*maxn],sz ;
void solve(int a,int b,int c,const vector<int> &v)
{
    if(v.empty()) return ;
    if(p[a].c==p[b].c) swap(a,c) ;
    else if(p[a].c==p[c].c) swap(a,b) ;

    sz=0 ;
    int val=0 ;
    for(auto i : v)
    {
        val |= (p[i].c+1) ;
        if(p[i].c==p[a].c) tmp[sz++]=i ;
    }
    if(val==(p[a].c+1))
    {
        if(p[a].c==0) for(auto i : v) Report(0,a,i) ;
        else for(auto i : v) Report(1,a-n,i-n) ;
        return ;
    }
    else if(val==(p[b].c+1))
    {
        if(p[b].c==0) for(auto i : v) Report(0,b,i) ;
        else for(auto i : v) Report(1,b-n,i-n) ;
        return ;
    }

    int t=rand()%sz ;
    if(p[a].c==0) Report(0,a,tmp[t]) ;
    else Report(1,a-n,tmp[t]-n) ;

    int np=tmp[t] ;
    for(auto i : v) if(i!=np)
    {
        if(in_triangle(p[i],p[a],p[b],p[np])) vec[vcnt+1].push_back(i) ;
        else if(in_triangle(p[i],p[b],p[c],p[np])) vec[vcnt+2].push_back(i) ;
        else vec[vcnt+3].push_back(i) ;
    }
    int vval=vcnt ; vcnt+=3 ;
    solve(a,b,np,vec[vval+1]) ;
    solve(b,c,np,vec[vval+2]) ;
    solve(a,c,np,vec[vval+3]) ;
}

main()
{
    srand(time(NULL)) ;
    Init(n,m) ;
    for(int i=1;i<=n;i++) Get(0,p[i].x,p[i].y) , p[i].c=0 ;
    for(int i=n+1;i<=n+m;i++) Get(1,p[i].x,p[i].y) , p[i].c=1 ;
    for(int i=3;i<=n+m;i=(i==n?i+3:i+1))
    {
        if( p[i].x < p[1].y-p[i].y ) vec[0].push_back(i) ;
        else vec[1].push_back(i) ;
    }
    Report(0,1,2) ;
    Report(1,1,2) ;
    vcnt=1 ;
    solve(1,n+1,n+2,vec[0]) ;
    solve(1,2,n+2,vec[1]) ;
    Finish() ;
}
