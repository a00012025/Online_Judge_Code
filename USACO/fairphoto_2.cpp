#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
#define M 5000000
using namespace std;
const int maxn=100000+10 , maxb=8+2 ;

void getv(const vector<int> &vec,int S,vector<int> &ret)
{
    ret.resize(vec.size()) ;
    for(int i=0,j=-1;i<vec.size();i++)
    {
        if(!(S&(1<<i))) ret[i]=vec[i] ;
        else
        {
            if(j==-1) j=vec[i] ;
            ret[i]=vec[i]-j ;
        }
    }
    ret.push_back(S) ;
}

int ri[maxn][maxb],le[maxn][maxb] ;
void getb(int x,int type,int K,vector<int> &ret)
{
    ret.clear() ;
    if(type==1) for(int i=K-1;ri[x][i];i++)
        ret.push_back(ri[x][i]) ;
    else for(int i=K-1;le[x][i];i++)
        ret.push_back(le[x][i]) ;
}

struct node
{
    node *nex ;
    vector<int> vec ;
    int data ;
    node(const vector<int> &_vec,int _data)
    {
        nex=NULL ;
        data=_data ;
        vec=_vec ;
    }
}*head[M] ;

int insert(const vector<int> &vec,int data)
{
    int h=0 ;
    for(int i=0;i<vec.size();i++) h+=(vec[i]<<(2*i)) ;
    h%=M ; if(h<0) h+=M ;
    for(node *u=head[h];u;u=u->nex)
    {
        bool ok=1 ;
        for(int i=0;i<vec.size();i++) if(vec[i]!=u->vec[i])
            { ok=0 ; break ; }
        if(ok) return u->data ;
    }
    if(data==-1) return -1 ;
    node *v=new node(vec,data) ;
    v->nex=head[h] ; head[h]=v ;
    return -1 ;
}

vector<int> pos[maxb] ;
vector<int> sum(maxb),tmp1(maxb),tmp2(maxb) ;
pii p[maxn] ;

int n ;
pii tmp[maxb] ;
void cal_lr(int x)
{
    int cnt=0 ;
    for(int i=0;i<maxb;i++)
    {
        int id=lower_bound(pos[i].begin(),pos[i].end()
                           ,x)-pos[i].begin() ;
        if(id!=pos[i].size()) tmp[cnt++]=(pii){pos[i][id],i} ;
    }
    sort(tmp,tmp+cnt) ;
    for(int i=0,j=0;i<cnt;i++)
        j^=(1<<tmp[i].S) , ri[x][i]=j ;

    cnt=0 ;
    for(int i=0;i<maxb;i++)
    {
        int id=upper_bound(pos[i].begin(),pos[i].end(),
                           x)-pos[i].begin()-1 ;
        if(id>=0) tmp[cnt++]=(pii){pos[i][id],i} ;
    }
    sort(tmp,tmp+cnt,greater<pii>()) ;
    for(int i=0,j=0;i<cnt;i++)
        j^=(1<<tmp[i].S) , le[x][i]=j ;
}

main()
{
    if(fopen("fairphoto.in","r"))
    {
        freopen("fairphoto.in","r",stdin) ;
        freopen("fairphoto.out","w",stdout) ;
    }
    int K ; scanf("%d%d",&n,&K) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&p[i].F,&p[i].S) ;
    sort(p+1,p+n+1) ;
    for(int i=1;i<=n;i++) pos[p[i].S].push_back(i) ;
    for(int i=1;i<=n;i++) cal_lr(i) ;

    int ans=-1 ;
    for(int i=1;i<=n;i++)
    {
        getb(i,1,K,tmp1) ;
        for(auto j : tmp1)
        {
            getv(sum,j,tmp2) ;
            insert(tmp2,p[i].F) ;
        }
        sum[p[i].S]++ ;
        getb(i,2,K,tmp1) ;
        for(auto j : tmp1)
        {
            getv(sum,j,tmp2) ;
            int res=insert(tmp2,-1) ;
            if(res!=-1) ans=max(ans,p[i].F-res) ;
        }
    }
    printf("%d\n",ans) ;
}
