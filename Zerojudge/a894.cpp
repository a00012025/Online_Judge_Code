#include<stdio.h>
#include<string.h>
int a[100001][33],odd[100001] ;
bool vis[33] ;
main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        memset(a,0,sizeof(a)) ;
        int n,x,num=0 ;
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x) ;
            int lev=0 ;
            while(x%2==0){lev++ ; x=x/2 ;}
            if(num==0){num++ ; odd[1]=x ; a[1][lev]=1 ; continue ;}
            int j ;
            for(j=1;j<=num && odd[j]!=x;j++) ;
            if(j==num+1) {
                    num++ ; odd[num]=x ; a[num][lev]++ ; continue ;}
            else a[j][lev]++ ;
        }
        int ANS=0 ;
        for(int i=1;i<=num;i++)
        {
            int ans=0,j ;
            memset(vis,0,sizeof(vis)) ;
            for(j=33;j!=0;)
            {
                for(j=j-1;a[i][j]==0 && j>=0;j--) ;
                if(j==-1) break ;
                if(vis[j+1]==0 && a[i][j]>=2)
                {
                    vis[j+1]=1 ;
                    vis[j]=1 ;
                    ans+=2 ;
                }
                else if(vis[j+1]==0 && a[i][j]==1)
                {
                    vis[j+1]=1 ;
                    ans+=1 ;
                }
                else
                {
                    vis[j]=1 ;
                    ans+=1 ;
                }
            }
            ANS+=ans ;
        }
        printf("%d\n",ANS) ;
    }
}
