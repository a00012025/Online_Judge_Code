#include<bits/stdc++.h>
using namespace std;
const int maxn=2000+10 ;
vector<int> v[maxn] ;
int ans[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        int x ; scanf("%d",&x) ;
        v[x].push_back(i) ;
    }
    for(int i=maxn-1,j=1;i>=0;j+=v[i].size(),i--)
        for(auto k : v[i]) ans[k]=j ;
    for(int i=1;i<=n;i++) printf("%d%c",ans[i],i==n?'\n':' ') ;
}
