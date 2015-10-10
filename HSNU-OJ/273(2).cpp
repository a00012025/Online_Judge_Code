//#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000000
#define pii pair<int,int>
#define F first
#define S second
#define mkp(x,y) make_pair(x,y)
using namespace std;
const int maxn=100000+10 , dx[]={1,-1,0,0} , dy[]={0,0,1,-1} ;

vector<int> v[maxn] ;
map<pii,int> mp ;
vector<pii> tmp ;
pii a[maxn] ;
int n,n2,deg[maxn],num[maxn] ;
LL ans=0LL ;

queue<int> q ;
bool used[maxn] ;
void BFS()
{
    while(!q.empty())
    {
        int u=q.front() ; q.pop() ;
        deg[u]-- ; n2-- ;
        mp.erase(a[u]) ; used[u]=1 ;
        ans+=((LL)num[u])*((LL)n-num[u]) ; ans%=MOD ;
        for(int i=0;i<v[u].size();i++)
        {
            num[v[u][i]]+=num[u] ;
            if((--deg[v[u][i]])==1) q.push(v[u][i]) ;
        }
    }
}

int vis[maxn],viscnt=0 ;
vector<int> cc ;
void dfs0(int x)
{
    vis[x]=viscnt ; cc.push_back(x) ;
    if(deg[x]==1) q.push(x) ;
    for(int i=0;i<v[x].size();i++)
        if(!used[v[x][i]] && vis[v[x][i]]!=viscnt)
        dfs0(v[x][i]) ;
}

int lev[maxn],low[maxn],cutid,cutnum1,cutnum2 ;
int num1[maxn],num2[maxn] ;

void update_cut_point(int id,int val1,int val2)
{
    if(cutid==-1) { cutid=id ; cutnum1=val1 ; cutnum2=val2 ; return ; }
    int sz=cc.size() ;
    if(abs(val1-sz/2) < abs(cutnum1-sz/2))
        cutid=id , cutnum1=val1 , cutnum2=val2 ;
}

void dfs(int x,int fa,int l)
{
    lev[x]=low[x]=l ; vis[x]=viscnt ;
    num1[x]=1 ; num2[x]=num[x] ;
    int son1=0 , son2=0 ;
    for(int i=0;i<v[x].size();i++) if(!used[v[x][i]])
    {
        if(vis[v[x][i]]==viscnt) low[x]=min(low[x],lev[v[x][i]]) ;
        else
        {
            if(!son1) son1=v[x][i] ;
            else son2=v[x][i] ;
            dfs(v[x][i],x,l+1) ;
            num1[x]+=num1[v[x][i]] ;
            num2[x]+=num2[v[x][i]] ;
            low[x]=min(low[x],low[v[x][i]]) ;
            if(low[v[x][i]]>=lev[x] && deg[v[x][i]]==2)
                update_cut_point(v[x][i],num1[v[x][i]],num2[v[x][i]]) ;
        }
    }
    if(x==fa && son2)
        update_cut_point(son1,num1[son1],num2[son2]) ;
}

void CUT(int x)
{
    viscnt++ ; cc.clear() ;
    dfs0(x) ;
    BFS() ;
    int id ; for(id=0;id<cc.size() && used[cc[id]];id++) ;
    if(id==cc.size()) return ;

    cutid=-1 ;
    viscnt++ ;
    dfs(cc[id],cc[id],0) ;
    if(cutid==-1) return ;

    int son1=0 , son2=0 ;
    for(int i=0;i<v[cc[id]].size();i++) if(!used[v[cc[id]][i]])
    {
        if(!son1) son1=v[cc[id]][i] ;
        else son2=v[cc[id]][i] ;
    }
    if(lev[son1]>lev[son2]) swap(son1,son2) ;

    num[son2]+=cutnum2+1 ;
    num[son1]+=n-cutnum2 ;
    ans += ((LL)2)*((LL)cutnum2)*((LL)n-1-cutnum2)+((LL)n-1) ;
    ans %= MOD ;
    used[cc[id]]=1 ; mp.erase(a[cc[id]]) ;
    deg[son1]-- ; deg[son2]-- ;
    CUT(son1) ;
    CUT(son2) ;
}

main()
{
    scanf("%d",&n) ; n2=n ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].F,&a[i].S) ;
        mp[a[i]]=i ;
        num[i]=1 ;
    }
    for(int i=1;i<=n;i++) for(int z=0;z<4;z++)
    {
        int nx=a[i].F+dx[z] , ny=a[i].S+dy[z] ;
        if(mp.count(mkp(nx,ny)))
            v[i].push_back(mp[mkp(nx,ny)]) ,
            deg[i]++ ;
    }

    for(int i=1;i<=n;i++) if(deg[i]==1) q.push(i) ;
    BFS() ;
    if(!n2) { printf("%I64d\n",ans) ; return 0 ; }

    for(int i=1;i<=n;i++) debugf("%d,",used[i]) ; debugf("\n") ;
    for(int i=1;i<=n;i++) debugf("%d,",num[i]) ; debugf("\n") ;


    CUT(mp.begin()->S) ;

    while(n2)
    {
        BFS() ;
        tmp.clear() ;
        map<pii,int>::iterator it1=mp.begin() , it2 ;
        LL sum=0LL ;
        int last=it1->F.S-1 ;
        for(it2=it1;it2!=mp.end() && it2->F.F==it1->F.F;it2++)
        {
            if(it2->F.S!=last+1) break ;
            last=it2->F.S ;
            sum+=num[it2->S] ;
            deg[it2->S]=0 ;
            for(int i=0;i<v[it2->S].size();i++)
                if(!used[v[it2->S][i]] && a[v[it2->S][i]].F != it2->F.F)
            {
                if((--deg[v[it2->S][i]])==1) q.push(v[it2->S][i]) ;
                num[v[it2->S][i]]+=num[it2->S] ;
            }
            tmp.push_back(it2->F) ;
            n2-- ;
        }
        ans+=sum*((LL)n-sum) ; ans%=MOD ;
        for(int i=0;i<tmp.size();i++) mp.erase(tmp[i]) ;
    }
    printf("%I64d\n",ans) ;
}
