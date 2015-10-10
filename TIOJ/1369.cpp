#include<bits/stdc++.h>
using namespace std;
const int maxn=50000+10 ;

vector<int> v[maxn] ;
int t=0,ans[maxn] ;

void dfs(int x)
{
    ans[x]=++t ;
    for(auto i : v[x]) dfs(i) ;
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        int k ; scanf("%d",&k) ;
        while(k--)
        {
            int x ; scanf("%d",&x) ;
            v[i].push_back(x) ;
        }
    }
    dfs(1) ;
    for(int i=1;i<=n;i++) printf("%d\n",ans[i]) ;
}
