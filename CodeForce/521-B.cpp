#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
#define mkp(x,y) make_pair(x,y)
#define LL long long
#define MOD 1000000009
using namespace std;
const int maxn=100000+10 ;

map<pii,int> mp ;
vector<int> v[maxn],v2[maxn] ;
int x[maxn],y[maxn],deg[maxn] ;
int dx[]={-1,0,1} , dy[]={1,1,1} , dx2[]={-2,-1,1,2} ;
set<int> s1 ;
set<int,greater<int> > s2 ;
bool done[maxn] ;

int cal(int id)
{
    int ret=0 ;
    for(auto i : v[id]) if(!done[i]) ret++ ;
    return ret ;
}

bool check(int x)
{
    if(!deg[x]) return 1 ;
    for(auto i : v2[x]) if(!done[i] && cal(i)==1) return 0 ;
    return 1 ;
}

void erase(int u)
{
    done[u]=1 ;
    for(auto i : v[u]) deg[i]-- ;
    s1.erase(u) ; s2.erase(u) ;
    mp.erase(mkp(x[u],y[u])) ;

    for(int i=0;i<4;i++)
    {
        auto it1=mp.find(mkp(x[u]+dx2[i],y[u])) ;
        if(it1!=mp.end())
        {
            if(check(it1->S)) continue ;
            auto it2=s1.find(it1->S) ;
            if(it2!=s1.end())
                s1.erase(it1->S) ,
                s2.erase(it1->S) ;
        }
    }
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&x[i],&y[i]) ;
        mp[mkp(x[i],y[i])]=i ;
    }

    for(int i=0;i<n;i++) for(int j=0;j<3;j++)
    {
        int nx=x[i]+dx[j] , ny=y[i]+dy[j] ;
        auto it=mp.find(mkp(nx,ny)) ;
        if(it!=mp.end())
            v[it->S].push_back(i) ,
            v2[i].push_back(it->S) ,
            deg[i]++ ;
    }

    LL ans=0LL ;
    for(int i=0;i<n;i++) if(check(i))
        s1.insert(i) , s2.insert(i) ;
    for(int type=0;!s1.empty();type^=1)
    {
        int u= type==0 ? *s2.begin() : *s1.begin() ;
        erase(u) ;
        ans=(ans*((LL)n)+u)%MOD ;
        for(auto i : v[u]) if(!done[i] && check(i))
            s1.insert(i) , s2.insert(i) ;
    }
    printf("%I64d\n",ans) ;
}
