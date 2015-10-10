#include<bits/stdc++.h>
#define LL long long
#define DB double
#define LD long double
using namespace std;
const int maxn=50000+10 ;
const DB PI=2*acos(0.0) ;

struct pt{DB x,y;};
DB dot(const pt &a,const pt &b) { return a.x*b.x + a.y*b.y ; }
DB len(const pt &a){ return sqrt(dot(a,a)) ; }

struct P
{
    int id ; DB val ;
    bool operator < (const P &rhs) const
    {
        return val<rhs.val ;
    }
};

DB in[maxn],out[maxn] ;
pt p[maxn] ;
set<P> s1,s2 ;

main()
{
    freopen("sight.in","r",stdin) ;
    freopen("sight.out","w",stdout) ;
    int n ; DB r ; scanf("%d%lf",&n,&r) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%lf%lf",&p[i].x,&p[i].y) ;
        DB a=atan2(p[i].y,p[i].x) , b=acos(r/len(p[i])) ;
        in[i]= a-b ;
        out[i]= a+b ;
    }

    int ans=0 ;
    while(out[1]<in[1]) out[1]+=2*PI ;
    s1.insert((P){1,out[1]}) ;
    for(int i=2;i<=n;i++)
    {
        while(in[i]>in[1]) in[i]-=2*PI ;
        while(out[i]>in[i]) out[i]-=2*PI ; out[i]+=2*PI ;
        if(out[i]>in[1])
            s1.insert((P){i,out[i]}) ;
        else
        {
            while(in[i]<in[1]) in[i]+=2*PI ;
            s2.insert((P){i,in[i]}) ;
        }
    }
    ans+= (s1.size()-1) ;

    while(1)
    {
        if(s2.empty()) { printf("%lld\n",(LL)n*(n-1)/2) ; return 0 ; }
        int id=s2.begin()->id ; DB val=s2.begin()->val ;
        if(id==1) break ;

        s2.erase(s2.begin()) ;
        while(!s1.empty())
        {
            if(s1.begin()->val < val)
            {
                int id2=s1.begin()->id ;
                while(in[id2]<val) in[id2]+=2*PI ;
                s2.insert((P){id2,in[id2]}) ;
                s1.erase(s1.begin()) ;
            }
            else break ;
        }
        ans+=s1.size() ;
        while(out[id]<val) out[id]+=2*PI ;
        s1.insert((P){id,out[id]}) ;
    }
    printf("%d\n",ans) ;
}
