#include<bits/stdc++.h>
#include"lib1360.h"
using namespace std;
const int maxn=100000+10 ;

int ans[maxn] ;

void solve(int x1,int x2,int y1,int y2)
{
    if(x1>x2) return ;
    if(x1==x2)
    {
        for(int i=y1;i<=y2;i++)
            ans[x1]=max(ans[x1],Hey_Man(x1,i)) ;
        return ;
    }

    int mid=(x1+x2)/2 , id ;
    for(int i=y1;i<=y2;i++)
    {
        int val=Hey_Man(mid,i) ;
        if(val>ans[mid]) ans[mid]=val , id=i ;
    }
    solve(x1,mid-1,y1,id-1) ;
    solve(mid+1,x2,id+1,y2) ;
}

main()
{
    WarCraft() ;
    int n=Find_n() , m=Find_m() ;
    solve(0,n-1,0,m-1) ;
    for(int i=0;i<n;i++) Report(ans[i]) ;
}
