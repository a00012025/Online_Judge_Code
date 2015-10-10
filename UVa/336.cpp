#include<stdio.h>
#include<string.h>
#include<map>
#include<vector>
using namespace std;
int pt[1000],num,ans ;
int len[1000] ;
vector<int> v[1000] ;
map<int,int> mp ;

void dfs(int n,int dep,int l)
{
        //printf("dfs %d , %d , %d\n",dep,pt[n],len[n]) ;
    if(len[n]<0) ans++ ;
    len[n]=dep ;
    if(dep==l) return ;
    for(int i=0;i<v[n].size();i++)
        if(len[v[n][i]]<0 || len[v[n][i]]>dep+1)
            dfs(v[n][i],dep+1,l) ;
}

int getid(int a)
{
    if(mp.count(a)) return mp[a] ;
    num++ ;
    mp[a]=num ;  pt[num]=a ;
    return num ;
}

main()
{
    int n,tc=0;
    while(scanf("%d",&n)==1 && n)
    {
        mp.clear() ;
        for(int i=0;i<1000;i++) v[i].clear() ;
        num=0 ;
        for(int i=1;i<=n;i++)
        {
            int a,b ;
            scanf("%d %d",&a,&b);
            int x=getid(a),y=getid(b) ;
            v[x].push_back(y) ;
            v[y].push_back(x) ;
        }
        int a,b,id ;
        while(scanf("%d %d",&a,&b)==2)
        {
            if(a==0 && b==0) break ;
            memset(len,-1,sizeof(len)) ;
            id=mp[a] ;
            ans=0 ;
            dfs(id,0,b) ;
                //for(int i=1;i<=num;i++) printf("%d,%d\n",pt[i],len[i]) ;
            //if(tc) printf("\n") ;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++tc,num-ans,a,b) ;
        }
    }
}
