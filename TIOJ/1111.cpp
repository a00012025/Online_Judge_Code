#include<bits/stdc++.h>
using namespace std;
const int maxn=500+10 ;
char G[maxn][maxn] ;
int n;
int dx[]={0,1,1,1},dy[]={-1,-1,0,1} ;

int check(int x,int y,char c,int t)
{
    int nx=x-dx[t] , ny=y-dy[t] ;
    if(nx>=0 && nx<n && ny>=0 &&  ny<n && G[nx][ny]==c)
        return 0 ;
    for(int i=0;i<5;i++)
    {
        nx+=dx[t] , ny+=dy[t] ;
        if(nx<0 || nx>=n || ny<0 || ny>=n || G[nx][ny]!=c) return 0 ;
    }
    nx+=dx[t] , ny+=dy[t] ;
    if(nx>=0 && nx<n && ny>=0 &&  ny<n && G[nx][ny]==c)
        return 0 ;
    return 1 ;
}

int cal(char c)
{
    int ret=0 ;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++)
        if(G[i][j]==c) for(int t=0;t<4;t++)
            ret+=check(i,j,c,t) ;
    return ret ;
}

main()
{
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=0;i<n;i++) scanf("%s",G[i]) ;
        for(int i=0;i<3;i++) printf("%c %d\n",'A'+i,cal('A'+i)) ;
        printf("\n") ;
    }
}
