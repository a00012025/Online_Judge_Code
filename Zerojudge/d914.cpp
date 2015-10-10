#include<bits/stdc++.h>
using namespace std;

int G1[30][30],G2[30][30] ;
int f(int x,int y)
{
    if(x==-1 && y==-1) return 0 ;
    if(x==-1 || y==-1) return 1 ;
    if(x==y) return 0 ;
    return 2 ;
}
main()
{
    int n,m ;
    while(scanf("%d",&n)!=EOF)
    {
        memset(G1,-1,sizeof(G1)) ;
        memset(G2,-1,sizeof(G2)) ;
        for(int i=1;i<=n;i++)
        {
            int x,y,c ; scanf("%d%d%d",&x,&y,&c) ;
            G1[x][y]=c ;
        }
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++)
        {
            int x,y,c ; scanf("%d%d%d",&x,&y,&c) ;
            G2[x][y]=c ;
        }
        int ans=0 ;
        for(int i=1;i<=19;i++) for(int j=1;j<=19;j++)
            ans+=f(G1[i][j],G2[i][j]) ;
        printf("%d\n",ans) ;
    }
}
