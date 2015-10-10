#include<stdio.h>
int G[101][101] ;
main()
{
    int n,m,fir=1,height[200] ;
    while(scanf("%d",&n)==1 && n)
    {
        scanf("%d",&m) ;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        {
            char c ;
            scanf("%c",&c) ;
            while(c!='0' && c!='1') scanf("%c",&c) ;
            if(c=='1') G[i][j]=1 ;
            else G[i][j]=0 ;
        }
        int ans=0 ;
        for(int i=1;i<=m;i++) height[i]=0 ;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        {
            height[j]=0 ;
            if(G[i][j])
            {
                for(int k=i;k>=1 && G[k][j];k--) height[j]++ ;
                for(int k=j-1;k>=1 && height[k]>height[j];k--)
                    height[k]=height[j];
                for(int k=j;k>=1 && height[k]!=0;k--) ans+=height[k] ;
            }
            //printf("%d,",height[j]);
            //if(j==m)printf("\n");
        }
        //if(fir) fir=0 ;
        //else printf("\n");
        printf("%d\n",ans) ;
    }
}
