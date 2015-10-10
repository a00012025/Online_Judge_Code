#include<bits/stdc++.h>
using namespace std;

vector<int> v[1000001] ;

int n ;
int search_in_v(int id,int val)
{
    if(v[id].empty()) return n+1 ;
    if(v[id][0]>val) return v[id][0] ;
    int l=0 , r=v[id].size() ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(v[id][mid]>val) r=mid ;
        else l=mid ;
    }
    if(r==(int)v[id].size()) return n+1 ;
    else return v[id][r] ;
}

main()
{
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++) {int x ; scanf("%d",&x) ; v[x].push_back(i) ; }
    int Q ; scanf("%d",&Q) ;
    while(Q--)
    {
        int num ; scanf("%d",&num) ;
        int now=0 ;
        for(int i=1;i<=num;i++)
        {
            int x ; scanf("%d",&x) ;
            if(now==n+1) continue ;
            now=search_in_v(x,now) ;
        }
        if(now==n+1) printf("NIE\n") ;
        else printf("TAK\n") ;
    }
}
