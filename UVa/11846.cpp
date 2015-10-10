#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int G[30][30],gpx[30],gpy[30],n,total ;
bool vis[30][30] ;
char now[30][30],ch ;

bool check(int x1,int y1,int x2,int y2,int ok1,int ok2)
{
    if(x2>=n || y2>=n) return 0;
    for(int i=x1;i<=x2;i++) for(int j=y1;j<=y2;j++)
    {
        if(vis[i][j]) return 0;
        if(i==ok1 && j==ok2) continue ;
        if(G[i][j]) return 0;
    }
    return 1 ;
}

bool dfs(int x,int y,int num)
{/*
        printf("%d,%d,%d\n",x,y,num) ;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++)
            printf("%c%c",now[i][j],j==n-1?'\n':' ') ;
        system("pause") ;*/
    if(num==total)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++) printf("%c",now[i][j]) ;
            printf("\n") ;
        }
        return 1;
    }
    int nx= y==n-1 ? x+1 : x ;
    int ny= y==n-1 ? 0 : y+1 ;

    if(G[x][y]==1)
    {
        vis[x][y]=1 ; now[x][y]=ch ;
        ch++ ;
        if(dfs(nx,ny,num+1)) return 1;
        ch-- ;
        vis[x][y]=0 ; return 0;
    }

    if(G[x][y] || vis[x][y])
    {
        if(dfs(nx,ny,num)) return 1;
        else return 0;
    }

    //if(x && y && !vis[x-1][y-1]) return 0;

    if(x && !vis[x-1][y])
    {
        if(!check(x-1,y,x+G[x-1][y]-2,y,x-1,y)) return 0;
        for(int i=x-1;i<=x+G[x-1][y]-2;i++)
        {
            vis[i][y]=1 ;
            now[i][y]=ch ;
        }
        ch++ ;
        if(dfs(nx,ny,num+1)) return 1;
        ch-- ;
        for(int i=x-1;i<=x+G[x-1][y]-2;i++)
            vis[i][y]=0 ;
        return 0 ;
    }

    if(y && G[x][y-1] && !vis[x][y-1])
        for(int k=2;k<=G[x][y-1];k++) if(G[x][y-1]%k==0)
    {
        if(!check(x,y-1,x+(G[x][y-1]/k)-1,y+k-2,x,y-1)) continue ;
        for(int i=x;i<=x+(G[x][y-1]/k)-1;i++)
            for(int j=y-1;j<=y+k-2;j++)
        {
            vis[i][j]=1 ; now[i][j]=ch ;
        }
        ch++ ;
        if(dfs(nx,ny,num+1)) return 1;
        ch-- ;
        for(int i=x;i<=x+(G[x][y-1]/k)-1;i++)
            for(int j=y-1;j<=y+k-2;j++)
                vis[i][j]=0 ;
    }

    for(int i=0;i<total;i++)
    {
        if(gpx[i]<x || gpy[i]<y) continue ;
        int area=G[gpx[i]][gpy[i]] ;
        if((gpx[i]-x+1)*(gpy[i]-y+1)>area) continue ;
        for(int k=1;k<=area;k++)
            if(area%k==0 && y+k-1>=gpy[i] && x+(area/k)-1>=gpx[i])
        {
            if(!check(x,y,x+(area/k)-1,y+k-1,gpx[i],gpy[i])) continue ;
            for(int p=x;p<=x+(area/k)-1;p++)
                for(int q=y;q<=y+k-1;q++)
            {
                vis[p][q]=1 ; now[p][q]=ch ;
            }
            ch++ ;
            if(dfs(nx,ny,num+1)) return 1;
            ch-- ;
            for(int p=x;p<=x+(area/k)-1;p++)
                for(int q=y;q<=y+k-1;q++)
                    vis[p][q]=0 ;
        }
    }
    return 0;
}

bool init()
{
    ch='A' ;
    memset(vis,0,sizeof(vis)) ;
    scanf("%d%d",&n,&total) ;
    if(!(n+total)) return 0;

    for(int i=0;i<n;i++) for(int j=0;j<n;j++) now[i][j]='x' ;

    int cnt=0 ;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++)
    {
        char c ; scanf("%c",&c) ;
        while(c!='.' && (c<'1' || c>'9')) scanf("%c",&c) ;
        G[i][j]= c=='.' ? 0 : c-'0' ;
        if(G[i][j])
        {
            gpx[cnt]=i ; gpy[cnt]=j ;
            cnt++ ;
        }
    }
    return 1;
}

main()
{
    while(init())
        dfs(0,0,0) ;
}
