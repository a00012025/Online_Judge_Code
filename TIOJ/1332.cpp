#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int maxn=1000000+10 ;

struct P
{
    int x,y ;
    bool operator < (const P &rhs) const
    {
        if(x==rhs.x) return y>rhs.y ;
        return x<rhs.x ;
    }
};

map<P,int> mp ;
int ans[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        int x ; scanf("%d",&x) ;
        if(i==1) { mp[(P){1,n}]=x ; ans[x]=0 ; continue ; }
        auto it=mp.lower_bound((P){x,n+1}) ; it-- ;
        while(it->F.x>x || it->F.y<x) it-- ;
        ans[x]=it->S ;
        int L=it->F.x , R=it->F.y ;
        if(x > ans[x]) mp[(P){ans[x]+1,R}]=x ;
        else mp[(P){L,ans[x]-1}]=x  ;
    }
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]) ;
}


