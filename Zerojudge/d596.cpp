#include<bits/stdc++.h>
using namespace std;
int adj[10][10],dx[]={1,-1,3,-3} ;
main()
{
    for(int i=1;i<=9;i++) for(int j=0;j<4;j++) if(i+dx[j]>=1 && i+dx[j]<=9)
        adj[i][i+dx[j]]=adj[i+dx[j]][i]=1 ;
    adj[3][4]=adj[4][3]=adj[6][7]=adj[7][6]=0 ;
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int a,b,c ; scanf("%d%d%d",&a,&b,&c) ;
        bool ok=0 ;
        for(int i=1;i<=9;i++)
            if(i!=a && i!=b && i!=c && adj[i][a] && !adj[i][b] && !adj[i][c])
        {
            if(!ok) printf("%d",i) ;
            else printf(" %d",i) ;
            ok=1 ;
        }
        if(!ok) printf("Empty") ;
        printf("\n") ;
    }
}
