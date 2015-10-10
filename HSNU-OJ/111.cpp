#include<bits/stdc++.h>
#define LL long long
using namespace std;

vector<int> tmp1,tmp2 ;
main()
{
    int T ; scanf("%d",&T);
    while(T--)
    {
        tmp1.clear() ; tmp2.clear() ;
        int n ; scanf("%d",&n) ;
        for(int i=1;i<=n;i++)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            tmp1.push_back(x) ;
            tmp2.push_back(y) ;
        }
        sort(tmp1.begin(),tmp1.end()) ;
        sort(tmp2.begin(),tmp2.end()) ;
        tmp1.resize(unique(tmp1.begin(),tmp1.end())-tmp1.begin()) ;
        tmp2.resize(unique(tmp2.begin(),tmp2.end())-tmp2.begin()) ;
        LL ans= ((LL)tmp1.size())*((LL)tmp2.size()) - n ;
        printf("%lld\n",ans) ;
    }
}
