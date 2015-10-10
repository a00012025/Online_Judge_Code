#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
#define INF 100000000
#define FORSET(x,y) for(set<int>::iterator x=(y).begin();x!=(y).end();x++)
using namespace std;
const int maxn=200000+10 ;

vector<int> v[maxn] ;
set<int> st[maxn] ;
int ans[maxn],id[maxn] ;

main()
{
    int n,m ;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++) st[i].clear() , v[i].clear() ;
        for(int i=2;i<=n;i++)
        {
            int x ; scanf("%d",&x) ;
            v[x].push_back(i) ;
        }
        for(int i=n-m+1;i<=n;i++)
        {
            int w ; scanf("%d",&w) ;
            st[i].insert(w) ;
            id[i]=i ; ans[i]=2147483647 ;
        }

        for(int i=n-m;i>=1;i--)
        {
            if(v[i].size()==1)
                {id[i]=id[v[i][0]] ; ans[i]=ans[v[i][0]] ; continue ;}

            int nid,M=0 ;
            for(int j=0;j<v[i].size();j++) if(st[id[v[i][j]]].size()>M)
                M=st[ nid = id[v[i][j]] ].size() ;

            id[i]=nid ;
            ans[i]=2147483647 ;
            for(int j=0;j<v[i].size();j++) ans[i]=min(ans[i],ans[v[i][j]]) ;
            for(int j=0;j<v[i].size();j++) if(nid != id[v[i][j]])
            {
                FORSET(it,st[id[v[i][j]]])
                {
                    if(st[nid].count(*it)){ ans[i]=0 ; break ; }
                    st[nid].insert(*it) ;
                    if(ans[i]==0) continue ;
                    set<int>::iterator it2=st[nid].find(*it) ;
                    if(it2!=st[nid].begin())
                    {
                        it2-- ;
                        ans[i]=min(ans[i],abs( (*it2)-(*it) )) ;
                        it2++ ;
                    }
                    it2++ ;
                    if(it2!=st[nid].end()) ans[i]=min(ans[i],abs( (*it2)-(*it) )) ;
                }
                st[id[v[i][j]]].clear() ;
            }
        }
        for(int i=1;i<=n-m;i++) printf("%d%c",ans[i],i==n-m?'\n':' ') ;
    }
}
