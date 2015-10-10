#include<bits/stdc++.h>
#define CASE_T int __T ; scanf("%d",&__T) ; while(__T--)
using namespace std;
const int maxn=100000+10 ;
struct P
{
    int l,r,id ;
    bool operator < (const P &rhs) const
    {
        if(r!=rhs.r) return r<rhs.r ;
        else return l<rhs.l ;
    }
};
int a[maxn],ans[maxn] ;

int now[maxn] ;
void cal(const vector<P> &v)
{
    int num=0 ;
    for(int i=v[0].l;i<=v[0].r;i++)
        if(!(now[a[i]]++)) num++ ;
    ans[v[0].id]=num ;

    for(int i=1;i<v.size();i++)
    {
        for(int j=v[i-1].r+1;j<=v[i].r;j++)
            if(!(now[a[j]]++)) num++ ;

        if(v[i].l > v[i-1].l)
        {
            for(int j=v[i-1].l;j<v[i].l;j++)
                if(!(--now[a[j]])) num-- ;
        }
        else if(v[i].l < v[i-1].l)
        {
            for(int j=v[i-1].l-1;j>=v[i].l;j--)
                if(!(now[a[j]]++)) num++ ;
        }
        ans[v[i].id]=num ;
    }
}

vector<P> u[400] ;
int tmp[maxn] ;
main()
{
    CASE_T
    {
        int n,Q ; scanf("%d%d",&n,&Q) ;

        for(int i=1;i<=n;i++) scanf("%d",&a[i]) , tmp[i]=a[i] ;
        sort(tmp+1,tmp+n+1) ;
        int m=unique(tmp+1,tmp+n+1)-tmp-1 ;
        for(int i=1;i<=n;i++) a[i]=lower_bound(tmp+1,tmp+m+1,a[i])-tmp ;

        int sq= (int)sqrt(n+0.5) ;
        for(int i=0;i<400;i++) u[i].clear() ;
        for(int i=1;i<=Q;i++)
        {
            int l,r ; scanf("%d%d",&l,&r) ;
            u[l/sq].push_back((P){l,r,i}) ;
        }

        for(int i=0;i<400;i++) if(!u[i].empty())
        {
            fill(now,now+m+1,0) ;
            sort(u[i].begin(),u[i].end()) ;
            cal(u[i]) ;
        }
        for(int i=1;i<=Q;i++) printf("%d\n",ans[i]) ;
    }
}
