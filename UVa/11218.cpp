#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
typedef struct{int id,val ;} P ;
queue<int> q ;
P p[200] ;
int w[2000],ans[2000] ;
main()
{
    int n,tc=0;
    while(scanf("%d",&n)==1 && n)
    {
        memset(w,0,sizeof(w)) ;
        for(int i=1;i<=n;i++)
        {
            int a,b,c,x ;
            scanf("%d%d%d%d",&a,&b,&c,&x) ;
            int k=(1<<(a-1))+(1<<(b-1))+(1<<(c-1)) ;
            w[k]=max(w[k],x) ;
        }
        int cnt=0 ;
        for(int i=0;i<1000;i++)
        {
            if(w[i]==0) continue ;
            cnt++ ;
            p[cnt].id=i ; p[cnt].val=w[i] ;
        }
        while(!q.empty()) q.pop() ;
        memset(ans,0,sizeof(ans)) ;
        q.push(0) ;
        while(!q.empty())
        {
            int x=q.front() ; q.pop() ;
            for(int i=1;i<=cnt;i++) if((x & p[i].id)==0)
            {
                ans[x+p[i].id]=max(ans[x+p[i].id],ans[x]+p[i].val) ;
                q.push(x+p[i].id) ;
            }
        }
        if(ans[511]==0) printf("Case %d: -1\n",++tc);
        else printf("Case %d: %d\n",++tc,ans[511]);
    }
}
