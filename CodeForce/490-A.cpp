#include<bits/stdc++.h>
using namespace std;
const int maxn=5000+10 ;

vector<int> v[4] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        int x ; scanf("%d",&x) ;
        v[x].push_back(i) ;
    }
    int m=min(min(v[1].size(),v[2].size()),v[3].size()) ;
    printf("%d\n",m) ;
    for(int i=0;i<m;i++) printf("%d %d %d\n",v[1][i],v[2][i],v[3][i]) ;
}
