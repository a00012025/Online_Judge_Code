#include<stdio.h>
#include<vector>
#include<map>
#define F first
#define S second
#define pii pair<int,int>
using namespace std;
const int maxn=1100000+10 ;
int a[maxn],left[maxn],right[maxn],n ;
int LEN[maxn] ;
map<int,vector<int> > v ;
vector< vector< vector<int> > > G ;

void build_LEN()
{
    LEN[1]=0 ;
    for(int i=2;i<=n;i++) LEN[i]=LEN[i/2]+1 ;
}

int search_in_v(const vector<int> &vec,int val)
{
    if(vec[0]>val) return 0 ;
    int l=0 , r=vec.size() ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(vec[mid]>val) r=mid ;
        else l=mid ;
    }
    return r ;
}

int RMQ(const vector< vector<int> > &vec,int l,int r)
{
    int x=LEN[r-l+1] ;
    return min(vec[x][l],vec[x][r-(1<<x)+1]) ;
}

int cal(int vid,int l,int r,int val)
{
    if(r<l) return -1 ;
    if(RMQ(G[vid],l,r) > val) return -1 ;
    if(RMQ(G[vid],l,l) < val) return l ;
    int lo=l , hi=r ;
    while(hi-lo>1)
    {
        int mid=(hi+lo)/2 ;
        if(RMQ(G[vid],l,mid)<val) hi=mid ;
        else lo=mid ;
    }
    return hi ;
}

map<int,int> inv ;
pii ans[maxn/2] ;
int st[maxn] ;
main()
{
    scanf("%d",&n) ;
    build_LEN() ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    int sz=0 ;
    for(int i=1;i<=n;i++)
    {
        while(sz && a[st[sz-1]]<a[i]) sz-- ;
        left[i]= (!sz) ? 0 : st[sz-1] ;
        st[sz++]=i ;
    }
    sz=0 ;
    for(int i=n;i>=1;i--)
    {
        while(sz && a[st[sz-1]]>a[i]) sz-- ;
        right[i]= (!sz) ? n+1 : st[sz-1] ;
        st[sz++]=i ;
    }

    for(int i=1;i<=n;i++) v[a[i]-i].push_back(i) ;
    int cnt=0 ;
    for(map<int,vector<int> >::iterator it=v.begin();it!=v.end();it++)
    {
        inv[it->F]=cnt ;
        G.resize(cnt+1) ; G[cnt].resize(20) ;
        for(int i=0;(1<<i)<it->S.size();i++)
            for(int j=0;j+(1<<i)-1<it->S.size();j++)
        {
            if(i==0) G[cnt][i].push_back(left[it->S[j]]) ;
            else
            G[cnt][i].push_back(min(G[cnt][i-1][j],G[cnt][i-1][j+(1<<(i-1))])) ;
        }
        cnt++ ;
    }

    int anscnt=0 ;
    for(int i=1;i<n;i++)
    {
        if(right[i]<=i+3) continue ;
        map<int,vector<int> >::iterator it=v.find(a[i]-i) ;
        int id=inv[it->F] ;
        int id1=search_in_v(it->S,i) ;
        int id2=search_in_v(it->S,right[i])-1 ;
        int val=cal(id,id1,id2,i) ; if(val==-1) continue ;
        if(anscnt && it->S[val]<=ans[anscnt-1].S) anscnt-- ;
        ans[anscnt++]=make_pair(i,it->S[val]) ;
    }
    printf("%d\n",anscnt) ;
    for(int i=0;i<anscnt;i++) printf("%d %d\n",ans[i].F,ans[i].S) ;
}
