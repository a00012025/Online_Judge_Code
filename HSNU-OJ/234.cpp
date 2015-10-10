#include<stdio.h>
#include<set>
#include<vector>
#include<algorithm>
#define INF 2000000000
using namespace std;
const int maxn=200001 ;
struct P
{
    int x,y,id ;
    bool operator < (const P &rhs) const
    {
        if(x!=rhs.x) return x<rhs.x ;
        else return y<rhs.y ;
    }
}a[maxn];

bool cmp1(const P &p,const P &q)
{
    if(p.x!=q.x) return p.x>q.x ;
    else return p.y>q.y ;
}

bool cmp2(const P &p,const P &q)
{
    if(p.y!=q.y) return p.y<q.y ;
    else return p.x<q.x ;
}

int x[maxn],y[maxn],len[maxn],dp[maxn] ;
vector<P> gp1[maxn],gp2[maxn] ;
multiset<int> mst1[maxn] ;
multiset<int,greater<int> > mst2[maxn] ;
int left[maxn],right[maxn] ;
bool done[maxn],ok[maxn] ;

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]) , a[i]=(P){x[i],y[i],i} ;
    sort(a+1,a+n+1) ;
    int num=0 ; dp[0]=INF ;
    for(int i=n;i>=1;i--)
    {
        if(a[i].y<dp[num])
            dp[++num]=a[i].x , len[a[i].id]=num , gp1[num].push_back(a[i]) ;
        else
        {
            int id= lower_bound(dp,dp+num+1,a[i].y,greater<int>()) - dp ;
            len[a[i].id]=id ; gp1[id].push_back(a[i]) ;
            dp[id]=max(dp[id],a[i].x) ;
        }
    }

    for(int j=0;j<gp1[num].size();j++) gp2[num].push_back(gp1[num][j]) ;
    for(int i=num;i>1;i--)
    {
        int val=INF ;
        for(int j=0;j<gp1[i].size();j++) val=min(val,gp1[i][j].y) ;
        int cnt=0 ;
        for(int j=0;j<gp1[i-1].size();j++) if(gp1[i-1][j].x>val)
            { gp2[i-1].push_back(gp1[i-1][j]) ; gp1[i-1][cnt++]=gp1[i-1][j] ; }
        gp1[i-1].resize(cnt) ;
    }
    for(int i=1;i<=num;i++)
    {
        sort(gp1[i].begin(),gp1[i].end(),cmp1) ;
        sort(gp2[i].begin(),gp2[i].end(),cmp2) ;

        for(int j=0;j<gp1[i].size();j++)
        {
            mst1[i].insert(gp1[i][j].y) ;
            mst2[i].insert(gp1[i][j].x) ;
            ok[gp1[i][j].id]=1 ;
        }
        right[i]= *(mst1[i].begin()) ;
        left[i]= *(mst2[i].begin()) ;
    }
    printf("%d\n",num) ;
    for(int i=1;i<=n;i++) if(ok[i] && !done[len[i]])
    {
        printf("%d ",i) ; done[len[i]]=1 ;

        right[len[i]]=y[i] ; left[len[i]]=x[i] ;

        for(int j=len[i]-1;j>=1 && !done[j];j--)
        {
            int sz=gp1[j].size() ;
            for(;sz;sz--)
            {
                P now= gp1[j][sz-1] ;
                if(!ok[now.id]) continue ;
                if(now.x > right[j+1])  break ;
                ok[now.id]=0 ;
                mst1[j].erase(mst1[j].find(now.y)) ;
                mst2[j].erase(mst2[j].find(now.x)) ;
            }

            gp1[j].resize(sz) ;
            left[j]==*(mst2[j].begin()) ;
            if(right[j]==*(mst1[j].begin())) break ;
            right[j]=*(mst1[j].begin()) ;
        }

        for(int j=len[i]+1;j<=num && !done[j];j++)
        {
            int sz=gp2[j].size() ;
            for(;sz;sz--)
            {
                P now= gp2[j][sz-1] ;
                if(!ok[now.id]) continue ;
                if(now.y < left[j-1])  break ;
                ok[now.id]=0 ;
                mst1[j].erase(mst1[j].find(now.y)) ;
                mst2[j].erase(mst2[j].find(now.x)) ;
            }

            gp2[j].resize(sz) ;
            right[j]==*(mst1[j].begin()) ;
            if(left[j]==*(mst2[j].begin())) break ;
            left[j]=*(mst2[j].begin()) ;
        }
    }
    printf("\n") ;
}
