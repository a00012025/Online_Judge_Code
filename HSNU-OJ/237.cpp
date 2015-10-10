#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
#define INF 1000000
using namespace std;
const int maxn=100001 ;

vector<int> v[maxn] ;
int fa[maxn],len[maxn],sec[maxn],Mid[maxn] ;
int thi[maxn],fou[maxn],cnt[maxn] ;

void dp1(int x)
{
    len[x]=sec[x]=thi[x]=fou[x]=-INF ;
    for(int i=0;i<v[x].size();i++) if(v[x][i]!=fa[x])
    {
        cnt[x]++ ;
        fa[v[x][i]]=x ;
        dp1(v[x][i]) ;
        if(1+len[v[x][i]]>=len[x])
            fou[x]=thi[x] , thi[x]=sec[x] , sec[x]=len[x] ,
            len[x]=1+len[v[x][i]] , Mid[x]=v[x][i] ;
        else if(1+len[v[x][i]]>=sec[x])
            fou[x]=thi[x] , thi[x]=sec[x] ,
            sec[x]=1+len[v[x][i]] ;
        else if(1+len[v[x][i]]>=thi[x])
            fou[x]=thi[x] , thi[x]=1+len[v[x][i]] ;
        else if(1+len[v[x][i]]>fou[x]) fou[x]=1+len[v[x][i]] ;
    }
    if(!cnt[x]) len[x]=0 ;
    debugf("%d : len,sec,Mid,thi : %d,%d,%d,%d\n",x,len[x],sec[x],Mid[x],thi[x]) ;
}

inline int maxlen(int x,int cant)
{
    return Mid[x]==cant ? sec[x] : len[x] ;
}

int d[maxn] ;
void dp2(int x)
{
    d[x]=len[x]+sec[x] ;
    for(int i=0;i<v[x].size();i++) if(v[x][i]!=fa[x])
        dp2(v[x][i]) , d[x]=max(d[x],d[v[x][i]]) ;
    debugf("d[%d] = %d\n",x,d[x]) ;
}

int uplen[maxn],start ;
void dp3(int x)
{
    uplen[x]=0 ;
    if(x!=start) uplen[x]=max(1+maxlen(fa[x],x),1+uplen[fa[x]]) ;
    debugf("uplen[%d] = %d\n",x,uplen[x]) ;
    for(int i=0;i<v[x].size();i++) if(v[x][i]!=fa[x])
        dp3(v[x][i]) ;
}

main()
{
    int n,k ; scanf("%d%d",&n,&k) ;
    for(int i=1;i<n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }

    int M=0 ;
    for(int i=1;i<=n;i++) if(v[i].size()>M) M=v[start=i].size() ;
    fa[start]=start ;
    dp1(start) ; dp2(start) ; dp3(start) ;

    if(k==1) printf("%d\n",2*n-2-(d[start]-1)) ;
    else
    {
        int ans=d[start] ;
        for(int i=1;i<=n;i++)
        {
            ans=max(ans,len[i]+sec[i]+thi[i]+uplen[i]) ;
            ans=max(ans,len[i]+sec[i]+thi[i]+fou[i]) ;
            for(int j=0;j<v[i].size();j++)
                if(v[i][j]!=fa[i])
                ans=max(ans,uplen[i]+d[v[i][j]]+maxlen(i,v[i][j])) ;
        }
        printf("%d\n",2*n-2-(ans-2)) ;
    }
}
