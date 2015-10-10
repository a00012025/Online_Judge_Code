#include<bits/stdc++.h>
#define lowbit(x) (x&-x)
#define LL long long
using namespace std;
const int maxn=100000+10 ;

int bit[maxn] ;
int add(int x,int val)
{
    while(x<maxn) bit[x]+=val , x+=lowbit(x) ;
}

int query(int x,int y)
{
    int ret=0 ;
    x-- ;
    while(y) ret+=bit[y] , y-=lowbit(y) ;
    while(x) ret-=bit[x] , x-=lowbit(x) ;
    return ret ;
}

struct P{int x ; LL val ;};

int ubd(const vector<P> &vec,int val)
{
    if(vec[0].x<=val) return 0 ;
    int l=0 , r=vec.size()-1 ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(vec[mid].x <= val) r=mid ;
        else l=mid ;
    }
    return r ;
}

vector<int> tmp ;
int a[maxn],cnt[maxn],sum[maxn] ;
int dp[maxn] ;
vector<P> v[maxn] ;
main()
{
    int n,m ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]) , tmp.push_back(a[i]) ;
    sort(tmp.begin(),tmp.end()) ;
    tmp.resize(unique(tmp.begin(),tmp.end())-tmp.begin()) ;
    m=tmp.size() ;
    for(int i=1;i<=n;i++)
        a[i]=upper_bound(tmp.begin(),tmp.end(),a[i])-tmp.begin() ,
        cnt[a[i]]++ ;
    for(int i=1;i<=m;i++) sum[i]=sum[i-1]+cnt[i] ;

    LL inv=0LL ;
    int num=0 ;
    v[0].push_back((P){0,0LL}) ;
    for(int i=1;i<=n;i++)
    {
        LL val=query(a[i]+1,m)+sum[a[i]-1]-query(1,a[i]-1) ;
        inv+=query(a[i]+1,m) ;
        add(a[i],1) ;

        int id=upper_bound(dp,dp+num+1,a[i])-dp ;
        int id2=ubd(v[id-1],a[i]) ;
        val+=v[id-1][id2].val ;
        dp[id]=a[i] ;
        if(id==num+1) num++ , v[num].push_back((P){a[i],val}) ;
        else
        {
            int r=v[id].size() ;
            while(r && val>=v[id][r-1].val) r-- ;
            if(r==v[id].size()) v[id].push_back((P){a[i],val}) ;
            else v[id][r]=(P){a[i],val} , v[id].resize(r+1) ;
        }
    }
    LL ans=0LL ;
    for(auto i : v[num]) ans=max(ans,i.val) ;
    printf("%lld\n",inv-ans) ;
}
