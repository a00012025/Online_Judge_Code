#include<stdio.h>
int n,G[10][10] ;
char now[70] ;

bool dfs(int num)
{
    if(num==n*n-1)
    {
        for(int i=0;i<n*n;i++)
        {
            printf("%c",now[i]) ;
            if((i+1)%n==0) printf("\n") ;
        }
        return 1;
    }
    int x=(num+1)/n , y=(num+1)%n ;

    if(G[x][y]!=0 && G[x][y+1]!=2 && G[x+1][y]!=4 && G[x+1][y+1]!=0)
    if(!(x==n && G[x+1][y]>0))
    {
        if(G[x][y]!=-1) G[x][y]-- ;
        if(G[x+1][y+1]!=-1) G[x+1][y+1]-- ;
        now[num+1]='\\' ;
        if(dfs(num+1)) return 1;
        if(G[x][y]!=-1) G[x][y]++ ;
        if(G[x+1][y+1]!=-1) G[x+1][y+1]++ ;
    }

    if(G[x][y]!=1 && G[x][y+1]!=0 && G[x+1][y]!=0 && G[x+1][y+1]!=4)
    if(!(x==n && G[x+1][y+1]==2))
    {
        if(G[x][y+1]!=-1) G[x][y+1]-- ;
        if(G[x+1][y]!=-1) G[x+1][y]-- ;
        now[num+1]='/' ;
        if(dfs(num+1)) return 1;
        if(G[x][y+1]!=-1) G[x][y+1]++ ;
        if(G[x+1][y]!=-1) G[x+1][y]++ ;
    }
    return 0;
}

main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<=n;i++) for(int j=0;j<=n;j++)
        {
            char c ; scanf("%c",&c) ;
            while(c!='.' && (c<'0' || c>'4')) scanf("%c",&c) ;
            G[i][j]= c=='.' ? -1 : c-'0' ;
        }
        dfs(-1) ;
    }
}

