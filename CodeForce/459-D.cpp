#include<bits/stdc++.h>
#define LL long long
#define lowbit(x) ((x)&(-x))
using namespace std;
const int maxn=1000000+10 ;

map<int,vector<int> > mp ;
int query(int l,int r,int x)
{
    auto it=mp.find(x) ;
    vector<int> &v=it->second ;
    return upper_bound(v.begin(),v.end(),r) -
            lower_bound(v.begin(),v.end(),l) ;
}

int bit[maxn] ;
void add(int x)
{
    while(x<maxn) bit[x]++ , x+=lowbit(x) ;
}
int query(int x)
{
    int ret=0 ;
    while(x) ret+=bit[x] , x-=lowbit(x) ;
    return ret ;
}

int x[maxn],a[maxn],b[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&x[i]) , mp[x[i]].push_back(i) ;
    for(int i=1;i<=n;i++)
        a[i]=query(1,i,x[i]) , b[i]=query(i,n,x[i]) ;

    LL ans=0LL ;
    for(int i=n-1;i>=1;i--)
        add(b[i+1]) , ans+=query(a[i]-1) ;
    printf("%lld\n",ans) ;
}
