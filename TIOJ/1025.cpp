#include<bits/stdc++.h>
using namespace std;

inline int num(int x,int y)
{
    return 3*(x/3)+y/3 ;
}

int now[9][9] ;
bool usx[9][9],usy[9][9],usb[9][9] ;
int cnt ;

void dfs(int n)
{
    if(n==81)
    {
        cnt++ ;
        for(int i=0;i<9;i++) for(int j=0;j<9;j++)
            printf("%d%c",now[i][j],j==8?'\n':' ') ;
        printf("\n") ; return ;
    }
    int x=n/9 , y=n%9 ;
    if(now[x][y]) { dfs(n+1) ; return ; }
    for(int i=1;i<=9;i++)
        if(!usx[x][i] && !usy[y][i] && !usb[num(x,y)][i])
    {
        usx[x][i] = usy[y][i] = usb[num(x,y)][i] = 1 ;
        now[x][y]=i ;
        dfs(n+1) ;
        usx[x][i] = usy[y][i] = usb[num(x,y)][i] = 0 ;
        now[x][y]=0 ;
    }
}

main()
{
    for(int i=0;i<9;i++) for(int j=0;j<9;j++)
    {
        int x ; scanf("%d",&x) ; now[i][j]=x ;
        if(x)
        {
            usx[i][x]=1 ;
            usy[j][x]=1 ;
            usb[num(i,j)][x]=1 ;
        }
    }
    cnt=0 ;
    dfs(0) ;
    printf("there are a total of %d solution(s).\n",cnt) ;
}
