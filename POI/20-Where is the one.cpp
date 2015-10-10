#include<bits/stdc++.h>
#include"cgdzlib.h"
using namespace std;
const int maxn=500000+10 ;

vector<int> v[4*maxn] ;
int vcnt=0 ;

void solve(const vector<int> &vec,int d,int m,int &mi,int &ma)
{
    if(vec.size()==2) { mi=vec[0] ; ma=vec[1] ; return ; }
    v[vcnt].push_back(vec[0]) ;
    for(int i=1;i<vec.size();i++)
    {
        if(f(vec[i],vec[0],2*d)) v[vcnt].push_back(vec[i]) ;
        else v[vcnt+1].push_back(vec[i]) ;
    }
    int tmp=vcnt ; vcnt+=2 ;
    if(v[tmp].size()!=v[tmp+1].size())
    {
        if(v[tmp].size()>v[tmp+1].size())
            solve(v[tmp],2*d,m,mi,ma) ;
        else
            solve(v[tmp+1],2*d,m,mi,ma) ;
        return ;
    }

    int a[2],b[2] ;
    solve(v[tmp],2*d,m-d,a[0],a[1]) ;
    solve(v[tmp+1],2*d,m-d,b[0],b[1]) ;
    for(int i=0;i<2;i++) for(int j=0;j<2;j++)
        if(f(a[i],b[j],m))
    {
        mi=a[i] ; ma=b[j] ;
        return ;
    }
}

main()
{
    int n=inicjuj() ;
    if(n==1) odpowiedz(1) ;

    for(int i=1;i<=n;i++) v[0].push_back(i) ;
    vcnt++ ;
    int a,b ;
    solve(v[0],1,n-1,a,b) ;
    if(g(a,b)) odpowiedz(b) ;
    else odpowiedz(a) ;
}
