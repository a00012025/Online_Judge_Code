#include<bits/stdc++.h>
#define LL long long
#define MKP(x,y) make_pair(x,y)
#define PB(x) push_back(x)
#define F first
#define S second
using namespace std;

LL cal_2(LL x)
{
    LL l=0,r=1e8 ;
    while(r-l>1)
    {
        LL mid=(r+l)/2 ;
        if(mid*(mid-1)/2 >= x) r=mid ;
        else l=mid ;
    }
    return r ;
}

LL cal_3(LL x)
{
    LL l=0,r=2e5 ;
    while(r-l>1)
    {
        LL mid=(r+l)/2 ;
        if(mid*(mid-1)*(mid-2)/6 >= x) r=mid ;
        else l=mid ;
    }
    return r ;
}

LL cal_4(LL x)
{
    LL l=0,r=1e4 ;
    while(r-l>1)
    {
        LL mid=(r+l)/2 ;
        if(mid*(mid-1)*(mid-2)*(mid-3)/24 >= x) r=mid ;
        else l=mid ;
    }
    return r ;
}

vector<pair<LL,LL> > ans ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        LL n ; scanf("%lld",&n) ;
        ans.clear() ;
        ans.PB(MKP(n,1)) ; ans.PB(MKP(n,n-1)) ;
        LL x=cal_2(n) ; if(x*(x-1)/2 == n) ans.PB(MKP(x,2)) , ans.PB(MKP(x,x-2)) ;
        LL y=cal_3(n) ; if(y*(y-1)*(y-2)/6 == n) ans.PB(MKP(y,3)) , ans.PB(MKP(y,y-3)) ;
        LL z=cal_4(n) ; if(z*(z-1)*(z-2)*(z-3)/24 == n) ans.PB(MKP(z,4)) , ans.PB(MKP(z,z-4)) ;
        for(LL i=5;i<=50;i++)
        {
            LL now=1LL , j=i ;
            while(now<n)
            {
                j++ ;
                now=now*j/(j-i) ;
            }
            if(now==n) ans.PB(MKP(j,i)) , ans.PB(MKP(j,j-i)) ;
        }
        sort(ans.begin(),ans.end()) ;
        ans.resize(unique(ans.begin(),ans.end())-ans.begin()) ;
        printf("%d\n",ans.size()) ;
        for(int i=0;i<ans.size();i++) printf("(%lld,%lld)%c",ans[i].F,ans[i].S,i==ans.size()-1?'\n':' ') ;
    }
}
