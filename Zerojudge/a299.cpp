#include<stdio.h>
const int maxn=10000+10 ;
int x1[maxn],x2[maxn],y1[maxn],y2[maxn] ;
main()
{
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]) ,
            x2[i]+=x1[i] , y2[i]+=y1[i] ;
        int x,y,ans=-1 ; scanf("%d%d",&x,&y) ;
        for(int i=1;i<=n;i++) if(x>=x1[i]&&x<=x2[i]&&y>=y1[i]&&y<=y2[i]) ans=i;
        printf("%d\n",ans) ;
    }

}
