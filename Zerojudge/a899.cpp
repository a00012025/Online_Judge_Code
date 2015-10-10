#include<stdio.h>
#include<queue>
#include<vector>
#include<map>
#define LL long long
using namespace std;
vector<int> v[2000],anc[2000] ;
queue<int> q ;
map<int,int> edge ;
LL ans ;
int n,m,S,F,num,c1[1010],c2[1010],d[1010] ;

LL cost(int id,int n)
{
    if(n>d[id]) return ((LL)c1[id]*d[id]+(LL)c2[id]*(n-d[id])) ;
    else return ((LL)c1[id]*n) ;
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d%d%d%d%d",&n,&m,&S,&F,&num) ;
        while(!q.empty()) q.pop() ;
        edge.clear() ;
        for(int i=0;i<=n;i++) {v[i].clear() ; anc[i].clear() ;}
        for(int i=1;i<=m;i++)
        {
            int a,b ;
            scanf("%d%d%d%d%d",&a,&b,&c1[i],&d[i],&c2[i]) ;
            v[a].push_back(b) ;
            edge[a*1000+b]=i ;
        }
        LL len[101] ;
        for(int i=0;i<=n;i++) len[i]=((LL)1<<60) ;
        len[S]=(LL)0 ; q.push(S) ;
        while(!q.empty())
        {
            int f=q.front() ; q.pop() ;
            for(int i=0;i<v[f].size();i++)
            {
                int id=edge[f*1000+v[f][i]] ;
                if(len[f]+cost(id,num)>len[v[f][i]]) continue ;
                q.push(v[f][i]) ;
                len[v[f][i]]=len[f]+cost(id,num) ;
            }
        }
        printf("%lld\n",len[F]) ;
    }
}
