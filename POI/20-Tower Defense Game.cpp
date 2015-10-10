#include<bits/stdc++.h>
using namespace std;
const int maxn=500000+10 ;

vector<int> v[maxn] ;
bool vis[maxn] ;
vector<int> ans ;
main()
{
    int n,m,k ; scanf("%d%d%d",&n,&m,&k) ;
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }
    for(int i=1;i<=n;i++) if(!vis[i])
    {
        ans.push_back(i) ; vis[i]=1 ;
        for(int j=0;j<v[i].size();j++)
        {
            int x=v[i][j] ; vis[x]=1 ;
            for(int k=0;k<v[x].size();k++) vis[v[x][k]]=1 ;
        }
    }
    printf("%d\n",ans.size()) ;
    for(int i=0;i<ans.size();i++) printf("%d%c",ans[i],i+1==ans.size()?'\n':' ') ;
}
