#include<stdio.h>
#include<algorithm>
#include<vector>
#define M 10000000
using namespace std;
int a[1001],head[M],next[1000001] ;
int fir[1000001],sec[1000001],data[1000001] ;
int h(int x)
{
    x %= M ;
    if(x<0) x+=M ;
    return x ;
}
main()
{
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=0;i<M;i++) head[i]=-1 ;
        int cnt=0 ;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
        {
            cnt++ ;
            data[cnt]=a[i]+a[j] ;
            fir[cnt]=i ; sec[cnt]=j ;
            int gp=h(data[cnt]) ;
            if(head[gp]==-1) {head[gp]=cnt ; next[cnt]=cnt ;}
            else {next[cnt]=head[gp] ; head[gp]=cnt ;}
        }
        int ans=-2000000000 ;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        {
            if(i==j) continue ;
            int val=a[i]-a[j] ;
            int gp=h(val) , now=head[gp];
            if(head[gp]==-1) continue ;
            bool found=0 , stop=0 ;
            for(int now=head[gp];!stop;now=next[now])
            {
                    //printf("%d , %d , %d\n",data[now],fir[now],sec[now]);
                if(now==next[now]) stop=1 ;
                if(data[now]!=val) continue ;
                if(fir[now]!=i && sec[now]!=i && fir[now]!=j && sec[now]!=i)
                    {found=1 ; break ;}
            }
            if(found) ans=max(ans,a[i]) ;
        }
            //for(int i=0;i<=12;i++) printf("%d,",head[i]);
            //printf("\n");
        if(ans==-2000000000) printf("no solution\n") ;
        else printf("%d\n",ans) ;
    }
}
