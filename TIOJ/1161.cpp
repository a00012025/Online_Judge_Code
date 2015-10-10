#include<bits/stdc++.h>
#define lowbit(x) (x&-x)
#define pii pair<int,int>
#define F first
#define S second
#define mkp(x,y) make_pair(x,y)
#define INF 10000000
using namespace std;
const int maxn=1000000+10 ;

int n ;
pii a[maxn] ;
multiset<int,greater<int> > mst ;

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int k ; scanf("%d%d",&n,&k) ;
        for(int i=0;i<n;i++) scanf("%d%d",&a[i].F,&a[i].S) ;
        sort(a,a+n) ;
        mst.clear() ;
        int ans=INF ;
        for(int i=0;i<n;)
        {
            int i2 ;
            for(i2=i;i2<n && a[i2].F==a[i].F;i2++)
            {
                mst.insert(a[i2].S) ;
                if(mst.size()>k) mst.erase(mst.begin()) ;
            }
            i=i2 ;
            if(i>=k) ans=min(ans,a[i-1].F+(*mst.begin())) ;
        }
        printf("%d\n",ans) ;
    }
}
