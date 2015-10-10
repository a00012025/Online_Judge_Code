#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

vector<int> v[maxn] ;

int fa[maxn],size[maxn] ;
int getfa(int x)
{
    return fa[x]==x ? x : fa[x]=getfa(fa[x]) ;
}

set<int> fas,las,las2 ;
map<int,int> mp ;
vector<int> del ;
int type[maxn] ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }
    fill(fa+1,fa+n+1,-1) ;
    for(int i=1;i<=n;i++) las.insert(i) ;
    for(int i=1;i<=n;i++)
    {
        mp.clear() ;
        las2.clear() ;
        del.clear() ;
        for(auto j : v[i])
        {
            if(fa[j]==-1)
            {
                las2.insert(j) ;
                type[j]=i ;
            }
            else mp[getfa(j)]++ ;
        }
        if(fa[i]==-1)
        {
            fa[i]=i ; size[i]=1 ;
            for(auto j : las) if(j!=i && type[j]!=i)
                fa[j]=i , size[i]++ ;
            for(auto j : fas) if(mp[j]<size[j])
            {
                fa[j]=i ;
                size[i]+=size[j] ;
                del.push_back(j) ;
            }
            for(auto j : del) fas.erase(j) ;
            fas.insert(i) ;
        }
        else
        {
            int i2=getfa(i) ;
            for(auto j : las) if(type[j]!=i)
                fa[j]=i2 , size[i2]++ ;
            for(auto j : fas) if(j!=i2 && mp[j]<size[j])
            {
                fa[j]=i2 ;
                size[i2]+=size[j] ;
                del.push_back(j) ;
            }
            for(auto j : del) fas.erase(j) ;
        }
        swap(las,las2) ;
    }
    int ans=0 ;
    for(int i=1;i<=n;i++) if(fa[i]==i || fa[i]==-1)
        ans++ ;
    printf("%d\n",ans) ;
}
