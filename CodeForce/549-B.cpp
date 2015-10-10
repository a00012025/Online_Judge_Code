#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10 ;

char G[maxn][maxn] ;
int a[maxn],now[maxn] ;
vector<int> v ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%s",G[i]+1) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    while(1)
    {
        bool found=0 ;
        vector<int> v2 ;
        for(int i=1;i<=n;i++) if(now[i]==a[i])
        {
            found=1 ;
            v2.push_back(i) ;
            v.push_back(i) ;
        }
        if(!found) break ;
        for(auto i : v2) for(int j=1;j<=n;j++)
            if(G[i][j]=='1') now[j]++ ;
    }
    printf("%d\n",v.size()) ;
    for(int i=0;i<v.size();i++) printf("%d%c",v[i],i+1==v.size()?'\n':' ') ;
}
