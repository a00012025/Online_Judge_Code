#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;
struct P
{
    int id,x,y ;
    bool operator < (const P &rhs) const
    {
        return x==rhs.x ?
            (y==rhs.y ? id<rhs.id : y>rhs.y) : x<rhs.x ;
    }
};

P tmp[2*maxn] ;
void cal(vector<P> &v)
{
    sort(v.begin(),v.end()) ;
    int cnt=0 ;
    for(auto i : v)
    {
        if(!cnt) { tmp[cnt++]=i ; continue ; }
        if(tmp[cnt-1].y >= i.y) continue ;
        else if(i.x <= tmp[cnt-1].y)
            tmp[cnt-1].y=max(tmp[cnt-1].y,i.y) ;
        else tmp[cnt++]=i ;
    }
    for(int i=0;i<cnt;i++) v[i]=tmp[i] ;
    v.resize(cnt) ;
}

vector<P> v[maxn],seg ;
int n,t ;

void cal_seg()
{
    seg.clear() ;
    for(int i=1;i<=n;i++)
    {
        if(v[i].empty())
            {seg.push_back((P){i,0,t}) ; continue ;}
        int sz=v[i].size() ;
        if(v[i][0].x) seg.push_back((P){i,0,v[i][0].x}) ;
        for(int j=0;j<sz-1;j++)
            seg.push_back((P){i,v[i][j].y,v[i][j+1].x}) ;
        if(v[i][sz-1].y < t) seg.push_back((P){i,v[i][sz-1].y,t}) ;
    }
    sort(seg.begin(),seg.end()) ;
    int cnt=0 ;
    for(auto i : seg)
    {
        if(!cnt) { tmp[cnt++]=i ; continue ; }
        if(i.y < tmp[cnt-1].y) continue ;
        if(i.y == tmp[cnt-1].y)
        {
            if(i.x==tmp[cnt-1].x) continue ;
            if(i.id > tmp[cnt-1].id) continue ;
        }
        tmp[cnt++]=i ;
        if(tmp[cnt-2].y < tmp[cnt-1].y)
            tmp[cnt-2].x=min(tmp[cnt-2].x,tmp[cnt-1].x) ;
    }
    for(int i=0;i<cnt;i++) seg[i]=tmp[i] ;
    seg.resize(cnt) ;
}

main()
{
    while(scanf("%d%d",&n,&t)==2 && n+t)
    {
        for(int i=1;i<=n;i++) v[i].clear() ;
        int m ; scanf("%d",&m) ;
        while(m--)
        {
            int id,x,y ; scanf("%d%d%d",&id,&x,&y) ;
            v[id].push_back((P){id,x,y}) ;
        }
        for(int i=1;i<=n;i++) if(!v[i].empty()) cal(v[i]) ;

        cal_seg() ;

        int Q ; scanf("%d",&Q) ;
        while(Q--)
        {
            int x ; scanf("%d",&x) ;
            if(seg.empty()) { printf("Oh, no!\n") ; continue ; }
            else if(seg[0].x > x) { printf("Oh, no!\n") ; continue ; }
            int l=0 , r=seg.size() ;
            while(r-l>1)
            {
                int mid=(r+l)/2 ;
                if(seg[mid].x <= x) l=mid ;
                else r=mid ;
            }
            if(seg[l].y<=x) printf("Oh, no!\n") ;
            else printf("%d %d\n",seg[l].id,seg[l].y-x) ;
        }
    }
}
