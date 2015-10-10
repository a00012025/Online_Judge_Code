#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
#define ABS(x) ((x)>0?(x):(-(x)))
#define INF 2100000000
using namespace std;
const int maxn=100000+10 ;

int get(int id,const pii &p)
{
    if(id&1) return id==1 ? p.F+p.S : -p.F-p.S ;
    return id==2 ? p.F-p.S : p.S-p.F ;
}
int getdis(const pii &p,const pii &q)
{
    return ABS(p.F-q.F)+ABS(p.S-q.S) ;
}

vector<pii> v[5] ;
void insert(int id,const pii &p)
{
    if(v[id].empty()){v[id].push_back(p) ; return ;}
    if(get(id,v[id][0])>get(id,p)) return ;
    if(get(id,v[id][0])<get(id,p))
    {
        v[id].clear() ;
        v[id].push_back(p) ;
        return ;
    }
    v[id].push_back(p) ;
    if(v[id].size()==3)
    {
        sort(v[id].begin(),v[id].end()) ;
        swap(v[id][1],v[id][2]) ;
        v[id].pop_back() ;
    }
}

main()
{
    int N,M,n,m ; scanf("%d%d%d",&N,&M,&n) ;
    while(n--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        for(int i=1;i<=4;i++) insert(i,(pii){x,y}) ;
    }
    int ans=INF , id ;
    scanf("%d",&m) ;
    for(int i=1;i<=m;i++)
    {
        int x,y,val=0 ; scanf("%d%d",&x,&y) ;
        pii p(x,y) ;
        for(int j=1;j<=4;j++) for(auto k : v[j])
            val=max(val,getdis(p,k)) ;
        if(val<ans) ans=val , id=i ;
    }
    printf("%d\n%d\n",ans,id) ;
}
