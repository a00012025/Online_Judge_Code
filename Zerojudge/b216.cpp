#include<bits/stdc++.h>
using namespace std;
int x[]={0,5,15,25,5,15,25,5,15,25},y[]={0,25,25,25,15,15,15,5,5,5} ;
bool vis[10]={0} ;
int line[10][10]={{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9}} ;
int point[]={0,8,5,8,5,2,5,8,5,8} ;
int dis(int x1,int y1,int x2,int y2)
{
    return max(abs(x1-x2),abs(y1-y2)) ;
}

main()
{
    for(int i=1;i<=9;i++)
    {
        int a,b ; scanf("%d%d",&a,&b) ;
        if((a%10)==0 || (b%10)==0) continue ;
        for(int i=1;i<=9;i++) if(dis(a,b,x[i],y[i])<5) vis[i]=1 ;
    }
    int num=0,ans=0 ;
    for(int i=1;i<=9;i++) if(vis[i]) ans+=point[i] ;
    for(int i=0;i<6;i++)
    {
        bool ok=1 ;
        for(int j=0;j<3;j++) if(!vis[line[i][j]]) ok=0 ;
        if(ok) num++ ;
    }
    printf("%d %d\n",num,ans) ;
}
