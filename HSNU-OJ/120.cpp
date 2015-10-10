#include<bits/stdc++.h>
#include"interactive/120.h"
using namespace std;
vector<int> v ;

int solve(int st,int k)
{
    int sz=v.size() ;
    if(sz==1) return v[0] ;
    if(sz==2)
    {
        int t=Med3(v[0],v[1],st) ;
        if(k==1) return t ;
        else return v[0]+v[1]-t ;
    }

    int x,y ;
    while(1)
    {
        x=((rand()%sz)+sz)%sz ;
        y=((rand()%sz)+sz)%sz ;
        if(v[x]!=st && v[y]!=st && x!=y) break ;
    }
    x=v[x] ; y=v[y] ;
    if(Med3(st,x,y)!=x) swap(x,y) ;

    vector<int> v1,v2,v3 ;
    for(int i=0;i<sz;i++) if(v[i]!=x && v[i]!=y)
    {
        int z=Med3(x,y,v[i]) ;
        if(z==x) v1.push_back(v[i]) ;
        if(z==v[i]) v2.push_back(v[i]) ;
        if(z==y) v3.push_back(v[i]) ;
    }
    int a=v1.size() , b=v2.size() , c=v3.size() ;
    if(k==a+1) return x ;
    if(k==a+b+2) return y ;

    v.clear() ;
    if(k<=a)
    {
        for(int i=0;i<v1.size();i++) v.push_back(v1[i]) ;
        return solve(st,k) ;
    }
    else if(k<=a+b+1)
    {
        for(int i=0;i<v2.size();i++) v.push_back(v2[i]) ;
        return solve(st,k-a-1) ;
    }
    else
    {
        for(int i=0;i<v3.size();i++) v.push_back(v3[i]) ;
        return solve(st,k-a-b-2) ;
    }
}

main()
{
    srand(time(NULL)) ;
    int n=GetN() ;
    if(n==3) Answer(Med3(1,2,3)) ;

    int x=1 , y=2 ;
    for(int i=3;i<=n;i++)
    {
        int z=Med3(x,y,i) ;
        if(z==x) x=i ;
        if(z==y) y=i ;
    }

    for(int i=1;i<=n;i++) v.push_back(i) ;
    int ans=solve(x,(n+1)/2) ;
    Answer(ans) ;
}
