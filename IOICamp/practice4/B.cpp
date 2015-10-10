#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+10 ;
vector<int> v[maxn] ;
int val[maxn],d[maxn] ;

int dp(int x)
{
    if(d[x]!=-1) return d[x] ;
    if(v[x].empty()) return d[x]=val[x] ;
    int &ans=d[x] ; ans=1000010 ;
    for(int i=0;i<v[x].size();i++) ans=min(ans,val[x]+dp(v[x][i])) ;
    return ans ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        for(int i=1;i<=n;i++) v[i].clear() ;
        for(int i=1;i<=n;i++)
        {
            int t ; scanf("%d%d",&val[i],&t) ;
            while(t--)
            {
                int x ; scanf("%d",&x) ;
                v[i].push_back(x) ;
            }
        }
        memset(d,-1,sizeof(d)) ;
        printf("%d\n",dp(n)) ;
    }
}
