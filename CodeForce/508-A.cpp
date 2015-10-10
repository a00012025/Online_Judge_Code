#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+10 ;

int n,m,k ;
int G[maxn][maxn] ;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1} ;
main()
{
    scanf("%d%d%d",&n,&m,&k) ;
    for(int i=1;i<=k;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        G[x][y]=1 ;
        for(int j=0;j<4;j++)
            if(G[x+dx[j]][y+dy[j]] &&
               G[x+dx[(j+1)%4]][y+dy[(j+1)%4]] &&
               G[x+dx[j]+dx[(j+1)%4]][y+dy[j]+dy[(j+1)%4]])
            {printf("%d\n",i) ; return 0 ;}
    }
    printf("0\n") ;
}
