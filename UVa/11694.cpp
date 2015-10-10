#include<stdio.h>
int n,fa[1000],G[20][20],T ;
char now[1000] ;
int getfa(int n)
{
    return n==fa[n] ? n : getfa(fa[n]) ;
}

inline int id(int x,int y)
{
    return x*(n+1)+y ;
}

bool dfs(int num)
{
    if(num==n*n-1)
    {
        if(G[n][n]>0) return 0;
        for(int i=0;i<n*n;i++)
        {
            printf("%c",now[i]) ;
            if((i+1)%n==0) printf("\n") ;
        }
        return 1;
    }
    int x=(num+1)/n , y=(num+1)%n ;
    if(G[x][y]>=2 || G[x][y+1]>=3) return 0;

    int num1,num2 ;

    num1=id(x,y) , num2=id(x+1,y+1) ;
    if(G[x][y]!=0 && G[x][y+1]!=2 && G[x+1][y]!=4 && G[x+1][y+1]!=0 && getfa(num1)!=getfa(num2))
    {
    if(!(x==n-1 && G[x+1][y]>0) && !(y==n-1 && G[x][y+1]>0))
    {
        if(G[x][y]!=-1) G[x][y]-- ;
        if(G[x+1][y+1]!=-1) G[x+1][y+1]-- ;
        now[num+1]='\\' ;
        int tem1=getfa(num1) , tem2=getfa(num2) ;
        fa[tem1]=tem2 ; //printf("fa[%d]=%d\n",tem1,tem2) ;
        if(dfs(num+1)) return 1;
        fa[tem1]=tem1 ;
        if(G[x][y]!=-1) G[x][y]++ ;
        if(G[x+1][y+1]!=-1) G[x+1][y+1]++ ;
    }
    }

    num1=id(x,y+1) , num2=id(x+1,y) ;
    if(G[x][y]!=1 && G[x][y+1]!=0 && G[x+1][y]!=0 && G[x+1][y+1]!=4 && getfa(num1)!=getfa(num2))
    {
    if(!(x==n-1 && G[x+1][y+1]==2) && !(y==n-1 && G[x+1][y+1]>1))
    {
        if(G[x][y+1]!=-1) G[x][y+1]-- ;
        if(G[x+1][y]!=-1) G[x+1][y]-- ;
        now[num+1]='/' ;
        int tem1=getfa(num1) , tem2=getfa(num2) ;
        fa[tem1]=tem2 ; //printf("fa[%d]=%d\n",tem1,tem2) ;
        if(dfs(num+1)) return 1;
        fa[tem1]=tem1 ;
        if(G[x][y+1]!=-1) G[x][y+1]++ ;
        if(G[x+1][y]!=-1) G[x+1][y]++ ;
    }
    }
    return 0;
}

main()
{
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d",&n) ;
        for(int i=0;i<=(n+1)*(n+1);i++) fa[i]=i ;
        for(int i=0;i<=n;i++) for(int j=0;j<=n;j++)
        {
            char c ; scanf("%c",&c) ;
            while(c!='.' && (c<'0' || c>'4')) scanf("%c",&c) ;
            G[i][j]= c=='.' ? -1 : c-'0' ;
        }
        dfs(-1) ;
    }
}
