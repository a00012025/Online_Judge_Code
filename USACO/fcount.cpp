#include<bits/stdc++.h>
using namespace std;
const int maxn=500+10 ;

struct P
{
    int id,val ;
    bool operator < (const P &rhs) const
    {
        return val>rhs.val ;
    }
}a[maxn];

int n,b[maxn] ;
bool check()
{
    int sum=0 ;
    for(int i=1;i<=n;i++)
    {
        if(b[i]>n-1) return 0 ;
        sum+=b[i] ;
    }
    if(sum%2) return 0 ;
    sum=0 ;
    for(int i=1,now=n,sum2=0;i<=n;i++)
    {
        sum+=b[i] ;
        while(now>=i+1 && b[now]<i) sum2+=b[now] , now-- ;
        if(now<i) { now++ ; sum2-=b[now] ; }
        if(sum>i*(i-1)+sum2+(now-i)*i) return 0 ;
    }
    return 1 ;
}

vector<int> ans ;
main()
{
    if(fopen("fcount.in","r"))
    {
        freopen("fcount.in","r",stdin) ;
        freopen("fcount.out","w",stdout) ;
    }
    scanf("%d",&n) ;
    for(int i=1;i<=n+1;i++) scanf("%d",&a[i].val) , a[i].id=i ;
    sort(a+1,a+n+2) ;
    for(int i=1;i<=n+1;i++)
    {
        for(int j=1,cnt=1;j<=n+1;j++)
            if(j!=i) b[cnt++]=a[j].val ;
        if(check()) ans.push_back(a[i].id) ;
    }
    sort(ans.begin(),ans.end()) ;
    printf("%d\n",ans.size()) ;
    for(auto i : ans) printf("%d\n",i) ;
}
