#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
typedef pair<int,int> pii ;
vector<int> v[1001] ;
vector<pii> edge ;
int num ;
bool room[1001] ;

bool solve()
{
    if(num<0) return 0 ;
    int cnt ;
    for(int i=0;i<(1<<8);i++)
    {
        cnt=num ;
        bool ok=1 ;
        memset(room,0,sizeof(room)) ;
        for(int j=0;j<edge.size();j++)
        {
            if(room[edge[j].first] || room[edge[j].second]) continue ;
            if(cnt==0) {ok=0 ; break ;}
            if(i & (1<<(cnt-1))) room[edge[j].first]=1 ;
            else room[edge[j].second]=1 ;
            cnt-- ;
        }
        if(ok) return 1 ;
    }
    return 0 ;
}

main()
{
    int m,n ;
    while(scanf("%d%d",&n,&m)==2 && m+n)
    {
        for(int i=0;i<=n;i++) v[i].clear() ;
        edge.clear() ;
        for(int i=1;i<=m;i++)
        {
            int a,b ; scanf("%d%d",&a,&b) ;
            v[a].push_back(b) ; v[b].push_back(a) ;
            edge.push_back(make_pair(a,b)) ;
        }
        num=8 ;
        for(int i=0;i<n;i++) if(!v[i].size()) num-- ;
        if(solve()) printf("Nice boat.\n") ;
        else printf("Makoto should die!\n") ;
    }
}
