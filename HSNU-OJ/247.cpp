#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
#define pll pair<LL,LL>
#define F first
#define S second
using namespace std;
const int maxn=1000005 ;
struct P{int from,to,dis;};
vector<int> v[maxn] ;
vector<P> edge ;
int n ;
bool vis[maxn],vis2[maxn] ;
bool used[maxn],evis[maxn] ;

vector<int> cyc_e ;
int psz ;

void dfs2(int x,LL d,LL &val,int &id,int tp)
{
    if(d>val) val=d , id=x ;
    vis2[x]=!tp ;
    for(int i=0;i<v[x].size();i++) if(!used[v[x][i]])
    {
        int to= edge[v[x][i]].from==x ? edge[v[x][i]].to : edge[v[x][i]].from ;
        if(vis2[to]==tp) dfs2(to,d+edge[v[x][i]].dis,val,id,tp) ;
    }
}

pll max_length1(int x)
{
    pll ret=(pll){-1LL,-1LL} ;
    int id ;
    dfs2(x,0,ret.F,id,0) ;
    dfs2(id,0,ret.S,id,1) ;
    return ret ;
}

vector<LL> len ;
int lsz ;
bool dfs0(int x,int fa,int &y,LL &MAX)
{
    vis[x]=1 ; bool ret=0 ;
    for(int i=0;i<v[x].size();i++) if(!evis[v[x][i]])
    {
        evis[v[x][i]]=1 ;
        int to= edge[v[x][i]].from==x ? edge[v[x][i]].to : edge[v[x][i]].from ;
        if(vis[to] == 1)
        {
            if(psz<cyc_e.size()) cyc_e[psz]=v[x][i] , psz++ ;
            else cyc_e.push_back(v[x][i]) , psz++ ;
            y=to ;
            used[v[x][i]]=1 ;
            ret=1 ;
        }
        if(dfs0(to,x,y,MAX))
        {
            if(to!=y) ret=1 , used[v[x][i]]=1 ;
            pll tmp=max_length1(to) ; //printf("%d : %I64d,%I64d\n",to,tmp.F,tmp.S);
            if(lsz<len.size()) len[lsz]=tmp.F ;
            else len.push_back(tmp.F) ;
            lsz++ ;
            MAX=max(MAX,tmp.S) ;
            if(to!=y)
            {
                if(psz<cyc_e.size()) cyc_e[psz]=v[x][i] , psz++ ;
                else cyc_e.push_back(v[x][i]) , psz++ ;
            }
        }
    }
    if(fa==x && ret==1)
    {
        pll tmp=max_length1(x) ; //printf("%d : %I64d,%I64d\n",x,tmp.F,tmp.S);
        if(lsz<len.size()) len[lsz]=tmp.F ;
        else len.push_back(tmp.F) ;
        lsz++ ;
        MAX=max(MAX,tmp.S) ;
    }
    return ret ;
}

multiset<LL> mst ;
LL cal(int x)
{
    psz=lsz=0 ;
    int y ;
    LL ret=0LL ;
    dfs0(x,x,y,ret) ;

    int num=psz ;
/*
    for(int i=0;i<num;i++) printf("len = %I64d , edge=%d\n",len[i],edge[cyc_e[i]].dis) ;
*/
/*
    mst.clear() ; LL tot=0LL ;
    for(int i=0;i<num;i++) mst.insert(tot+len[i]) , tot+=edge[cyc_e[i]].dis ;
    LL sum=0LL ;
    for(int i=0;i<num;i++)
    {
        mst.erase(mst.find(sum+len[i])) ;
        ret=max(ret,len[i]+(*(mst.begin()))-sum) ;
        mst.insert(tot+sum+len[i]) ;
        sum+=edge[cyc_e[i]].dis ;
    }*/
    //printf("ret = %I64d\n",ret) ;
    return ret ;
}

main()
{
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        int x,d ; scanf("%d%d",&x,&d);
        edge.push_back((P){i,x,d}) ;
        v[i].push_back(i-1) ;
        v[x].push_back(i-1) ;
    }
    LL ans=0LL ;
    for(int i=1;i<=n;i++) if(!vis[i]) ans+=cal(i) ;
    printf("%I64d\n",ans) ;
}
