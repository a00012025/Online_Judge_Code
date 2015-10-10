#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1000+10 ;

LL a[maxn][maxn],s[3][maxn][maxn] ;

inline LL cal(int t,int x1,int y1,int x2,int y2)
{
    return s[t][x2][y2]-s[t][x1-1][y2]-s[t][x2][y1-1]+s[t][x1-1][y1-1] ;
}

main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
    {
        scanf("%lld",&a[i][j]) ;
        s[0][i][j]=s[0][i-1][j]+s[0][i][j-1]-s[0][i-1][j-1]+a[i][j] ;
        s[1][i][j]=s[1][i-1][j]+s[1][i][j-1]-s[1][i-1][j-1]+j*a[i][j] ;
        s[2][i][j]=s[2][i-1][j]+s[2][i][j-1]-s[2][i-1][j-1]+i*a[i][j] ;
    }
    int Q ; scanf("%d",&Q) ;
    while(Q--)
    {
        int x1,y1,x2,y2 ; scanf("%d%d%d%d",&x1,&x2,&y1,&y2) ;
        LL tot=cal(0,x1,y1,x2,y2) ;
        if(!tot) { printf("0\n") ; continue ; }

        int x,y ;
        int l=x1-1 , r=x2 ;
        while(r-l>1)
        {
            int mid=(r+l)/2 ;
            if(cal(0,x1,y1,mid,y2) >= (tot+1)/2) r=mid ;
            else l=mid ;
        }
        x=r ;

        l=y1-1 , r=y2 ;
        while(r-l>1)
        {
            int mid=(r+l)/2 ;
            if(cal(0,x1,y1,x2,mid) >= (tot+1)/2) r=mid ;
            else l=mid ;
        }
        y=r ;

        LL ans=0LL ;
        ans+=y*cal(0,x1,y1,x2,y)-cal(1,x1,y1,x2,y) ;
        ans+=cal(1,x1,y,x2,y2)-y*cal(0,x1,y,x2,y2) ;
        ans+=x*cal(0,x1,y1,x,y2)-cal(2,x1,y1,x,y2) ;
        ans+=cal(2,x,y1,x2,y2)-x*cal(0,x,y1,x2,y2) ;
        printf("%lld\n",ans) ;
    }
}
