#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=2000000+10 ;
struct P{int x,y ;};
vector<P> ans ;

unsigned int a[maxn] ;
multiset<unsigned int> mst ;
main()
{
    int n,m ;
    unsigned int k ; scanf("%d%d%u",&n,&m,&k) ;
    int MOD=2*m ;
    for(int i=1;i<=n;i++)
    {
        scanf("%u",&a[i%MOD]) ;
        mst.insert(a[i%MOD]) ;
        if(i>m) mst.erase(mst.find(a[(i-m)%MOD])) ;
        auto it=mst.end() ; it-- ;
        if(*it == *mst.begin() + k)
            ans.push_back((P){max(1,i-m+1),i}) ;
    }
    for(int i=max(1,n-m+1);i<=n-2;i++)
    {
        mst.erase(mst.find(a[i%MOD])) ;
        auto it=mst.end() ; it-- ;
        if(*it == *mst.begin() + k)
            ans.push_back((P){i+1,n}) ;
    }
    printf("%d\n",ans.size()) ;
    for(auto i : ans) printf("%d %d\n",i.x,i.y) ;
}
