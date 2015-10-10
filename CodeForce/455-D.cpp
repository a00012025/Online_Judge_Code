#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 , maxsq=350 ;

struct P
{
    int l,r,cnt[maxn],st,sz ;
    int a[2*maxsq] ;
    void build()
    {
        sz=r-l+1 ; st=0 ;
        memset(cnt,0,sizeof(cnt)) ;
        for(int i=0;i<sz;i++) cnt[a[i]]++ ;
    }
    inline int get(int x){return a[(x+st)%sz] ;}
    void shift(int L,int R,int x)
    {
        cnt[a[(R-l+st)%sz]]-- ; cnt[x]++ ;
        if(l==L && r==R)
            st=(st==0?sz-1:st-1) , a[st]=x ;
        else
        {
            L-=l ; R-=l ;
            for(int i=R;i>L;i--) a[(i+st)%sz]=a[(i-1+st)%sz] ;
            a[(L+st)%sz]=x ;
        }
    }
    int query(int L,int R,int x)
    {
        if(l==L && r==R) return cnt[x] ;
        int ret=0 ;
        L-=l ; R-=l ;
        for(int i=L;i<=R;i++) if(a[(i+st)%sz]==x)
            ret++ ;
        return ret ;
    }
}p[maxsq];

main()
{
    int n ; scanf("%d",&n) ;
    int sq=2*int(sqrt(n+0.5))+1 ;
    for(int i=0;i<n;i+=sq)
        p[i/sq].l=i , p[i/sq].r=min(i+sq-1,n-1) ;
    for(int i=0;i<n;i++)
    {
        int x ; scanf("%d",&x) ;
        p[i/sq].a[i-i/sq*sq]=x ;
    }
    for(int i=0;i<n;i+=sq)
        p[i/sq].build() ;
    int Q , last=0 ; scanf("%d",&Q) ;
    while(Q--)
    {
        int t,l,r,k ; scanf("%d%d%d",&t,&l,&r) ;
        l=(l+last-1)%n ; r=(r+last-1)%n ;
        if(l>r) swap(l,r) ;
        if(t==1)
        {
            int lg=l/sq , rg=r/sq ;
            int rval=p[rg].get(r-rg*sq) ;
            for(int i=lg;i<=rg;i++)
            {
                int pos=min(r,i*sq+sq-1) ;
                int nval=p[i].get(pos-i*sq) ;
                p[i].shift(max(i*sq,l),pos,rval) ;
                rval=nval ;
            }
        }
        else
        {
            scanf("%d",&k) ; k=(k+last-1)%n+1 ;
            int lg=l/sq , rg=r/sq , ans=0 ;
            for(int i=lg;i<=rg;i++)
                ans+=p[i].query(max(i*sq,l),min(i*sq+sq-1,r),k) ;
            printf("%d\n",last=ans) ;
        }
    }
}
