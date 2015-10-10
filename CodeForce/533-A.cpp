#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
const int maxn=500000+10 ;

vector<int> v[maxn] ;
int h[maxn],hm[maxn] ;
void dfs0(int x,int f,int nowh)
{
    hm[x]=nowh ;
    for(auto i : v[x]) if(i!=f)
        dfs0(i,x,min(nowh,h[i])) ;
}

struct P
{
    int id,hm ;
    bool operator < (const P &rhs) const
    {
        return hm<rhs.hm ;
    }
}cave[maxn];

int tmp[maxn],tcnt ;
void dfs2(int x,int f,int nowhm)
{
    tmp[tcnt++]=nowhm ;
    for(auto i : v[x]) if(i!=f)
    {
        int newhm=min(nowhm,h[i]) ;
        if(newhm > hm[i]) dfs2(i,x,newhm) ;
    }
}

multiset<int> st ;
int st_tmp[maxn],scnt ;
bool check()
{
    if(tcnt < st.size()) return 0 ;
    scnt=0 ;
    for(int i=0;!st.empty() && i<tcnt;i++)
    {
        auto it=st.upper_bound(tmp[i]) ;
        if(it!=st.begin())
            it-- , st_tmp[scnt++]=*it , st.erase(it) ;
    }
    int sz=st.size() ;
    for(int i=0;i<scnt;i++) st.insert(st_tmp[i]) ;
    return sz==0 ;
}

int LIM ;
bool dfs(int x,int f,int add)
{
    if(h[x]<=LIM)
    {
        int newhm= (f==-1 ? h[x]+add : min(hm[f],h[x]+add)) ;
        if(newhm>hm[x])
        {
            tcnt=0 ;
            dfs2(x,f,newhm) ;
            if(check()) return 1 ;
        }
    }
    for(auto i : v[x]) if(i!=f && dfs(i,x,add))
        return 1 ;
    return 0 ;
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&h[i]) ;
    for(int i=1;i<n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }
    dfs0(1,-1,h[1]) ;

    int k ; scanf("%d",&k) ;
    for(int i=1,x;i<=k;i++) scanf("%d",&x) , st.insert(x) ;
    for(int i=k+1;i<=n;i++) st.insert(0) ;
    for(int i=1;i<=n;i++) cave[i]=(P){i,hm[i]} ;
    sort(cave+1,cave+n+1) ;

    LIM=-1 ;
    for(int i=1;i<=n;i++)
    {
        auto it=st.upper_bound(cave[i].hm) ;
        if(it!=st.begin()) st.erase(--it) ;
        else if(LIM==-1) LIM=cave[i].hm ;
    }
    if(st.empty()) {printf("0\n") ; return 0;}
    if(!dfs(1,-1,INF)) {printf("-1\n") ; return 0 ;}

    int l=0 , r=INF ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(dfs(1,-1,mid)) r=mid ;
        else l=mid ;
    }
    printf("%d\n",r) ;
}
