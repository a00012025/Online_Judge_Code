#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
#define mkp(x,y) make_pair(x,y)
using namespace std;
const int maxn=100000+1000 ;
int n,fa[401][maxn],fa2[maxn] ;
int getfa(int id,int x)
{
    return fa[id][x]==x ? x : fa[id][x]=getfa(id,fa[id][x]) ;
}

int getfa2(int x)
{
    return fa2[x]==x ? x : fa2[x]=getfa2(fa2[x]) ;
}

void DSU1(int id,const vector<pii> &vec)
{
    int sz=vec.size() ;
    for(int i=1;i<=n;i++) fa[id][i]=i ;
    for(int i=0;i<sz;i++)
    {
        int x=getfa(id,vec[i].F) , y=getfa(id,vec[i].S) ;
        if(x!=y) fa[id][x]=y ;
    }
}

vector<pii> v[maxn] ;
vector<int> v1,v2 ;
map<pii,vector<int> > mp ;
int ans[maxn] ;

vector<int> tmp ;
void DSU2(vector<pii> &vec)
{
    tmp.clear() ;
    for(int i=0;i<vec.size();i++)
        tmp.push_back(vec[i].F) ,
        tmp.push_back(vec[i].S) ;
    sort(tmp.begin(),tmp.end()) ;
    tmp.resize(unique(tmp.begin(),tmp.end())-tmp.begin()) ;
    for(int i=0;i<vec.size();i++)
        vec[i].F=lower_bound(tmp.begin(),tmp.end(),vec[i].F)-tmp.begin() ,
        vec[i].S=lower_bound(tmp.begin(),tmp.end(),vec[i].S)-tmp.begin() ;

    for(int i=0;i<=601;i++) fa2[i]=i ;
    for(int i=0;i<vec.size();i++)
    {
        int x=getfa2(vec[i].F) , y=getfa2(vec[i].S) ;
        if(x!=y) fa2[x]=y ;
    }
    for(int i=0;i<tmp.size();i++) for(int j=i+1;j<tmp.size();j++)
        if(getfa2(i)==getfa2(j))
    {
        if(!mp.count(mkp(tmp[i],tmp[j]))) continue ;
        map<pii,vector<int> >::iterator it=mp.find(mkp(tmp[i],tmp[j])) ;
        for(int z=0;z<it->S.size();z++)
            ans[it->S[z]]++ ;
    }
}

main()
{
    int m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=m;i++)
    {
        int x,y,col ; scanf("%d%d%d",&x,&y,&col) ;
        v[col].push_back(mkp(x,y)) ;
    }

    for(int i=1;i<=m;i++) if(!v[i].empty())
    {
        if(v[i].size()>=300) v1.push_back(i) ;
        else v2.push_back(i) ;
    }

    for(int i=0;i<v1.size();i++)
        DSU1(i,v[v1[i]]) ;

    int Q ; scanf("%d",&Q) ;
    memset(ans,0,sizeof(ans)) ;
    for(int i=0;i<Q;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        if(x>y) swap(x,y) ;
        mp[mkp(x,y)].push_back(i) ;
        for(int j=0;j<v1.size();j++)
            if(getfa(j,x)==getfa(j,y)) ans[i]++ ;
    }

    for(int i=0;i<v2.size();i++)
        DSU2(v[v2[i]]) ;

    for(int i=0;i<Q;i++) printf("%d\n",ans[i]) ;
}
