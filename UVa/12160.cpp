#include<stdio.h>
#include<queue>
#include<string.h>
const int INF=100000000 ;
using namespace std;
queue<int> q;
char st[5],ed[5],add[1000][5] ;
int lev[10000],tc=0 ;

int val(char *a)
{
    if(strlen(a)<4) return 0 ;
    return 1000*(a[0]-'0')+100*(a[1]-'0')+10*(a[2]-'0')+(a[3]-'0') ;
}

int id(int n)
{
    return n%10000 ;
}

main()
{
    while(scanf("%s %s",st,ed)==2)
    {
        int m;
        scanf("%d",&m) ;
        if(!(val(st)+val(ed)+m)) break ;
        for(int i=1;i<=m;i++) scanf("%s",add[i]) ;
        while(!q.empty()) q.pop() ;
        for(int i=0;i<10000;i++) lev[i]=INF ;
        lev[val(st)]=0 ; q.push(val(st)) ;
        while(!q.empty())
        {
            int a=q.front() ; q.pop() ;
            for(int i=1;i<=m;i++) if(lev[a]+1 < lev[id(a+val(add[i]))])
            {
                lev[id(a+val(add[i]))]=lev[a]+1 ;
                q.push(id(a+val(add[i]))) ;
            }
        }
        if(lev[val(ed)]==INF) printf("Case %d: Permanently Locked\n",++tc) ;
        else printf("Case %d: %d\n",++tc,lev[val(ed)]) ;
    }
}
