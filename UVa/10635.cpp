#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int id[70000],low[70000] ;

int lis(int *a,int n)
{
    memset(low,0,sizeof(low)) ;
    int ans=0 ;
    for(int i=0;i<n;i++)
    {
        int id=lower_bound(low,low+ans+1,a[i]) - low ;
        if(id==ans+1)
        {
            low[id]=a[i] ;
            ans++ ;
        }
        else low[id]=min(low[id],a[i]);
        //for(int i=0;i<10;i++)printf("%d,",low[i]);
        //printf("\n");
    }
    return ans ;
}

main()
{
    int T,tc=0;
    scanf("%d",&T);
    while(T--)
    {
        int n,p,q,a[70000] ;
        scanf("%d %d %d",&n,&p,&q) ;
        memset(id,0,sizeof(id)) ;
        for(int i=1;i<=p+1;i++)
        {
            int x ;
            scanf("%d",&x) ;
            id[x]=i ;
        }
        int cnt=0 ;
        for(int i=1;i<=q+1;i++)
        {
            int x;
            scanf("%d",&x) ;
            if(id[x]) a[cnt++]=id[x] ;
        }
        printf("Case %d: %d\n",++tc,lis(a,cnt)) ;
    }
}
