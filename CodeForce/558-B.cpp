#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int maxn=100000+10 ;

map<int,int> mp,mpl,mpr ;
main()
{
    int n,ma=0 ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        int x ; scanf("%d",&x) ;
        ma=max(ma,++mp[x]) ;
        if(mpl.find(x)==mpl.end()) mpl[x]=i ;
        mpr[x]=i ;
    }
    int ansl=1 , ansr=n ;
    for(auto i : mp) if(i.S==ma && mpr[i.F]-mpl[i.F]<ansr-ansl)
        ansl=mpl[i.F] , ansr=mpr[i.F] ;
    printf("%d %d\n",ansl,ansr) ;
}
