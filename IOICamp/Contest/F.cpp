#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=200000+10 ;
struct P
{
    int l,r,id;
    bool operator < (const P &rhs) const
    {
        return r==rhs.r ? id<rhs.id : r<rhs.r ;
    }
};

int a[maxn],now[maxn] ;
LL ans[maxn] ;

vector<int> val ;
int discrete(int n)
{
    val.clear() ;
    for(int i=1;i<=n;i++) val.push_back(a[i]) ;
    sort(val.begin(),val.end()) ;
    val.erase(unique(val.begin(),val.end()),val.end()) ;
    for(int i=1;i<=n;i++)
        a[i]=lower_bound(val.begin(),val.end(),a[i])-val.begin() ,
        a[i+n]=a[i] ;
    return (int)val.size()+1 ;
}

void cal(const vector<P> &v)
{
    LL num=0LL ;
    for(int i=v[0].l;i<=v[0].r;i++)
    {
        now[a[i]]++ ;
        num+= val[a[i]]-now[a[i]]+1 ;
    }
    ans[v[0].id]=num ;

    for(int i=1;i<v.size();i++)
    {
        for(int j=v[i-1].r+1;j<=v[i].r;j++)
        {
            now[a[j]]++ ;
            num+= val[a[j]]-now[a[j]]+1 ;
        }
        if(v[i-1].l < v[i].l)
        {
            for(int j=v[i-1].l;j<v[i].l;j++)
            {
                now[a[j]]-- ;
                num-= val[a[j]]-now[a[j]] ;
            }
        }
        else if(v[i-1].l > v[i].l)
        {
            for(int j=v[i-1].l-1;j>=v[i].l;j--)
            {
                now[a[j]]++ ;
                num+= val[a[j]]-now[a[j]]+1 ;
            }
        }
        ans[v[i].id]=num ;
    }
}

vector<P> v[700] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n,Q ; scanf("%d%d",&n,&Q) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        int sz=discrete(n) ;
        int sq=(int)sqrt(n+0.5) ;
        for(int i=0;i<700;i++) v[i].clear() ;
        for(int i=1;i<=Q;i++)
        {
            int l,r ; scanf("%d%d",&l,&r) ;
            if(r>=l) v[l/sq].push_back((P){l,r,i}) ;
            else v[l/sq].push_back((P){l,r+n,i}) ;
        }
        for(int i=0;i<700;i++) if(!v[i].empty())
        {
            fill(now,now+sz+1,0) ;
            sort(v[i].begin(),v[i].end()) ;
            cal(v[i]) ;
        }
        for(int i=1;i<=Q;i++) printf("%lld\n",ans[i]) ;
    }
}
