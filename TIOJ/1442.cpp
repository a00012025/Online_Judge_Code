#include<bits/stdc++.h>
using namespace std;
const int maxn=4000+5 ;

char G[maxn][maxn] ;
int n,m ;

int cal(int x)
{
    int x0=x ;
    for(int i=0,type=0;i<n;)
    {
        if(i<0) return 0 ;
        if(G[i][x]=='\\' && type==0)
        {
            if(x==m-1) return 0 ;
            if(G[i][x+1]=='/') x++ , i-- , type=1 ;
            else i++ , x++ ;
        }
        else if(G[i][x]=='\\' && type==1)
        {
            if(x==0) return 0 ;
            if(G[i][x-1]=='/') x-- , i++ , type=0 ;
            else i-- , x-- ;
        }
        else if(G[i][x]=='/' && type==0)
        {
            if(x==0) return 0 ;
            if(G[i][x-1]=='\\') x-- , i-- , type=1 ;
            else x-- , i++ ;
        }
        else
        {
            if(x==m-1) return 0 ;
            if(G[i][x+1]=='\\') x++ , i++ , type=0 ;
            else x++ , i-- ;
        }
    }
    return 1 ;
}

main()
{
    scanf("%d%d",&n,&m) ;
    swap(n,m) ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
    {
        char c=getchar() ;
        while(c!='\\' && c!='/') c=getchar() ;
        G[i][j]=c ;
    }
    int ans=0 ;
    for(int i=0;i<m;i++) ans+=cal(i) ;
    if(ans) printf("%d\n",ans) ;
    else printf("I can't escape.\n") ;
}
