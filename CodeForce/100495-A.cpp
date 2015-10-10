#include<stdio.h>
#include<queue>
#include<string.h>
#define LL long long
using namespace std;
struct P
{
    int val ;
    LL lev ;
    bool operator < (const P& rhs) const
    {
        return lev > rhs.lev ;
    }
} ;

void read_set(int *p)
{
    int num ;
    scanf("%d",&num) ;
    for(int i=1;i<=num;i++)
    {
        int a ;
        scanf("%d",&a) ;
        *p+=(1<<a) ;
    }
}

bool vis[100000] ;
int need[100000],get[100000] ;
LL work[100000],ans[100000] ;
priority_queue<struct P> q ;
main()
{
    int T,tc=0;
    scanf("%d",&T);
    while(T--)
    {
        memset(vis,0,sizeof(vis)) ;
        memset(need,0,sizeof(need)) ;
        memset(get,0,sizeof(get)) ;
        memset(ans,-1,sizeof(ans)) ;
        while(!q.empty()) q.pop() ;
        int n,m,dream=0,start=0 ;
        scanf("%d %d",&n,&m) ;
        read_set(&start) ; read_set(&dream) ;
        for(int i=1;i<=m;i++)
        {
            scanf("%I64d",&work[i]) ;
            read_set(&need[i]) ; read_set(&get[i]) ;
        }
        q.push((struct P){start,(LL)0}) ;
        vis[start]=1 ; ans[start]=0 ;
        while(!q.empty())
        {
            struct P x=q.top() ; q.pop() ;
                //printf("%d,%I64d\n",x.val,x.lev) ;
            for(int i=1;i<=m;i++)
            {
                if((x.val & need[i]) != need[i]) continue ;
                int y=x.val-need[i] ;
                if((!vis[(y | get[i])]) || (x.lev+work[i] < ans[(y | get[i])]))
                {
                    q.push((struct P){(y | get[i]),x.lev+work[i]}) ;
                    vis[(y | get[i])]=1 ;
                    ans[(y | get[i])] = x.lev+work[i] ;
                    //printf("push %d , %d\n",(y | get[i]),x.lev+work[i]);
                }
            }
        }
        tc++ ;
        if(ans[dream]!=-1) printf("Case #%d: YES %I64d\n",tc,ans[dream]) ;
        else printf("Case #%d: NO\n",tc) ;
        //for(int i=1;i<=m;i++) printf("%d,%d\n",need[i],get[i]) ;
        //printf("~~~%d -> %d\n",start,dream) ;
    }
}
