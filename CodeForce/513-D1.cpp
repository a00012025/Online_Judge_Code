#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;
struct P{int a,b,type;}p[100010],tmp[100010] ;
struct pii
{
    int x,y ;
    bool operator < (const pii &rhs) const
    {
        return x==rhs.x ? y<rhs.y : x<rhs.x ;
    }
};

int ans[maxn] ;
pii sta[maxn],seg[maxn] ;

bool solve(int L,int R,int st,int ed,int evl,int evr)
{
    if(st>ed) return 1 ;
    int root=L ;
    if(st==ed) { ans[st]=root ; return 1 ; }

    int le=L , ri=R+1 , num=0 ;
    for(int i=evl;i<=evr;i++)
    {
        if(p[i].b==root) return 0 ;
        if(p[i].a==root)
        {
            if(p[i].type==1) le=max(le,p[i].b) ;
            else ri=min(ri,p[i].b) ;
        }
        else seg[num++]=(pii){p[i].a,p[i].b} ;
    }
    if(le>=ri) return 0 ;
    if(!num)
    {
        ans[st+le-L]=root ;
        if(!solve(L+1,le,st,st+le-L-1,1,0)) return 0 ;
        if(!solve(le+1,R,st+le-L+1,ed,1,0)) return 0 ;
        return 1 ;
    }
    sort(seg,seg+num) ;
    int sz=0 ;
    for(int i=0;i<num;i++)
    {
        if(sz && sta[sz-1].y >= seg[i].y) continue ;
        if(sz && seg[i].x<=sta[sz-1].y) sta[sz-1].y=seg[i].y ;
        else sta[sz++]=seg[i] ;
    }

    int lid=0 ;
    while(lid<sz && sta[lid].x<=le) lid++ ;
    if(lid && sta[lid-1].y>=ri) return 0 ;

    int mid= lid ? sta[lid-1].y : le ;
    int evl2=evl , evr2=evr ;
    for(int i=evl;i<=evr;i++) if(p[i].a!=root)
    {
        if(p[i].a <= mid) tmp[evl2++]=p[i] ;
        else tmp[evr2--]=p[i] ;
    }
    for(int i=evl;i<=evr;i++) p[i]=tmp[i] ;
    ans[st+mid-L]=root ;
    if(!solve(L+1,mid,st,st+mid-L-1,evl,evl2-1)) return 0 ;
    if(!solve(mid+1,R,st+mid-L+1,ed,evr2+1,evr)) return 0 ;

    return 1 ;
}

main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    bool no=0 ;
    for(int i=1;i<=m;i++)
    {
        char s[10] ; scanf("%d%d%s",&p[i].a,&p[i].b,s) ;
        if(s[0]=='L') p[i].type=1 ;
        else p[i].type=2 ;
        if(p[i].b<=p[i].a) no=1 ;
    }

    if(no || !solve(1,n,1,n,1,m)) printf("IMPOSSIBLE\n") ;
    else for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ') ;
}

