#include<stdio.h>
#include<algorithm>
using namespace std;
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1} ;
char c[4]={'S','N','E','W'} ;
main()
{
    int T,a[20][20];
    scanf("%d",&T);
    while(T--)
    {
        int n,m,M=-1,st1,st2 ;
        scanf("%d %d",&n,&m) ;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        {
            int w ;
            scanf("%d",&w);
            a[i][j]=w ;
            if(w==0) {st1=i ; st2=j ;}
            M=max(M,w) ;
        }
        int x=st1,y=st2,cnt=0 ;
        char ans[10000] ;
        for(int i=1;i<=M;i++) for(int j=0;j<4;j++)
        {
            int nx=x+dx[j] , ny=y+dy[j] ;
            if(nx<1 || nx>n || ny<0 || ny>m) continue ;
            if(a[nx][ny] != a[x][y]+1) continue ;
            ans[++cnt]=c[j] ;
            x=nx ; y=ny ;
        }
        int cnt2=0 ;
        for(int i=1;i<=cnt;i++)
        {
            if(i==1 || ans[i]==ans[i-1]) cnt2++ ;
            else printf("%c%d",ans[i-1],cnt2) , cnt2=1 ;
        }
        printf("%c%d\n",ans[cnt],cnt2) ;
    }
}
