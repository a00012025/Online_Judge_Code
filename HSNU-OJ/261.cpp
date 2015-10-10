//#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
using namespace std;
const int maxn=150001 ;
struct P{int from,to;};
vector<int> v[maxn] ;
vector<P> edge ;

struct pt
{
    int id,val ;
    bool operator < (const pt &rhs) const
    {
        return id==rhs.id ? val<rhs.val : id<rhs.id ;
    }
};

inline int TO(int x,int j)
{
    return edge[v[x][j]].to==x ? edge[v[x][j]].from : edge[v[x][j]].to ;
}

map<pt,int> mp ;
int icnt=0 , inv[2*maxn] ;
int ID(const pt &q)
{
    if(!mp.count(q)) mp[q]=++icnt , inv[icnt]=q.id ;
    return mp[q] ;
}

struct PATH
{
    int x,y ;
    vector<int> path;
}pth[maxn];

int pthid[2*maxn],pos[2*maxn] ;
bool val[2*maxn] ;

set<int> tmp ;
int cal(int z,int step)
{
    int id=pthid[z] , now=pos[z] ;
    int x=pth[id].x , y=pth[id].y ;
    if(now<x)
    {
        if(now<step) return 0 ;
        return (int)val[pth[id].path[now-step]] ;
    }

    tmp.clear() ;
    int pos2= (((now-x-step)%y)+y)%y ;
    pos2 += x ;
    if(val[pth[id].path[pos2]]) tmp.insert( inv[pth[id].path[pos2]] ) ;

    pos2= (((now-step)%y)+y)%y ;
    while(pos2<x)
    {
        if(val[pth[id].path[pos2]]) tmp.insert( inv[pth[id].path[pos2]] ) ;
        pos2 += y ;
    }

    debugf("cal(%d,%d)=%d\n",z,step,tmp.size()) ;

    return tmp.size() ;
}

int n,m,p ;
int per[2*maxn] ;
bool in[2*maxn],vis[2*maxn] ;
main()
{
    scanf("%d%d%d",&n,&m,&p) ;
    for(int i=1;i<=m;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(i-1) ;
        v[y].push_back(i-1) ;
        edge.push_back((P){x,y}) ;
        ID((pt){x,i-1}) ; ID((pt){y,i-1}) ;
    }

    for(int i=0;i<n;i++)
    {
        int to ;
        if(v[i].size()==1)
        {
            to=TO(i,0) ;
            per[ ID((pt){i,v[i][0]}) ] = ID((pt){to,v[i][0]}) ;
            in[ ID((pt){to,v[i][0]}) ] = 1 ;
            val[ ID((pt){i,v[i][0]}) ] = 1 ;
        }
        else
        {
            for(int j=1;j<v[i].size();j++)
            {
                to=TO(i,0) ;
                per[ ID((pt){i,v[i][j]}) ] = ID((pt){to,v[i][0]}) ;
                in[ ID((pt){to,v[i][0]}) ] = 1 ;
                val[ ID((pt){i,v[i][j]}) ] = 1 ;
            }
            to=TO(i,1) ;
            per[ ID((pt){i,v[i][0]}) ] = ID((pt){to,v[i][1]}) ;
            in[ ID((pt){to,v[i][1]}) ] = 1 ;
        }
    }

    for(int i=1;i<=icnt;i++) debugf("per[%d] = %d , val=%d\n",i,per[i],val[i]) ;

    int cnt=0 ;
    for(int i=1;i<=icnt;i++) if(!in[i])
    {
        debugf("start = %d\n",i) ;
        int tmp ;
        for(int j=i;!vis[j];j=per[j])
            pth[cnt].path.push_back(j) , vis[j]=1 , tmp=per[j] ;
        int sz=pth[cnt].path.size() ;
        for(int j=0;j<sz;j++) if(pth[cnt].path[j]==tmp)
        {
            pth[cnt].x=j ;
            pth[cnt].y=sz-j ;
            break ;
        }

        for(int j=0;j<sz;j++)
            pthid[pth[cnt].path[j]]=cnt ,
            pos[pth[cnt].path[j]]=j ;

        cnt++ ;
    }

    for(int i=1;i<=icnt;i++) if(!vis[i])
    {
        for(int j=i;!vis[j];j=per[j]) vis[j]=1 , pth[cnt].path.push_back(j) ;
        pth[cnt].x=0 ;
        pth[cnt].y=pth[cnt].path.size() ;
        for(int j=0;j<pth[cnt].path.size();j++)
            pthid[pth[cnt].path[j]]=cnt ,
            pos[pth[cnt].path[j]]=j ;

        cnt++ ;
    }

    for(int i=0;i<cnt;i++)
    {
        debugf("pth id : %d , x=%d , y=%d\n",i,pth[i].x,pth[i].y) ;
        for(int j=0;j<pth[i].path.size();j++)
            debugf("%d,",pth[i].path[j]) ;
        debugf("\n") ;
    }

    int Q ; scanf("%d",&Q) ;
    while(Q--)
    {
        int step , ans=0 ;
        scanf("%d",&step) ;
        for(int i=0;i<v[p].size();i++) ans+=cal(ID((pt){p,v[p][i]}),step) ;
        printf("%d\n",ans) ;
    }
}
