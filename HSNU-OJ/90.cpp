#include<bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define F first
#define S second
#define MKP(x,y) make_pair(x,y)
using namespace std;
const int maxn=2000+10 ;
LL sum[maxn][maxn] ;
int a[maxn][maxn],h[maxn] ;
pii st[maxn] ;

LL cal(int x1,int y1,int x2,int y2)
{
    return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1] ;
}

main()
{
    LL k ; int n ; scanf("%lld%d",&k,&n) ;
    for(int i=0;i<=n;i++) sum[i][0]=sum[0][i]=0LL ;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
    {
        scanf("%d",&a[i][j]) ;
        sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(LL)a[i][j] ;
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
    {
        if(a[i][j]>2*k) a[i][j]=-1 ;
        if(a[i][j]>=k && a[i][j]<=2*k)
            { printf("%d %d %d %d\n",j,i,j,i) ; return 0 ; }
    }

    memset(h,0,sizeof(h)) ;
    int num,x1,y1,x2,y2 ; bool ok=0 ;
    for(int i=1;i<=n && !ok;i++)
    {
        for(int j=1;j<=n;j++) h[j]= a[i][j]==-1 ? 0 : h[j]+1 ;
        num=0 ;
        for(int j=1;j<=n && !ok;j++)
        {
            if(h[j]==0) { num=0 ; continue ; }
            int newx=j ;
            while(num && st[num-1].S>=h[j]) newx=st[num-1].F , num-- ;
            st[num++]=MKP(newx,h[j]) ;
            for(int z=0;z<num && !ok;z++)
            {
                LL x=cal(i-st[z].S+1,st[z].F,i,j) ;
                if(x>=k && x<=2*k)
                {
                    printf("%d %d %d %d\n",st[z].F,i-st[z].S+1,j,i) ;
                    return 0 ;
                }
                if(x>2*k)
                {
                    x1=i-st[z].S+1 , y1=st[z].F ;
                    x2=i , y2=j ;
                    ok=1 ;
                }
            }
        }
    }
    if(!ok) { printf("NIE\n") ; return 0 ; }
    for(int i=x1;i<=x2;i++) for(int j=y1;j<=y2;j++)
    {
        LL x=cal(i,y1,i,j) ;
        if(x>=k && x<=2*k) { printf("%d %d %d %d\n",y1,i,j,i) ; return 0 ; }
    }
    for(int i=x1+1;i<=x2;i++)
    {
        LL x=cal(x1,y1,i,y2) ;
        if(x>=k && x<=2*k) { printf("%d %d %d %d\n",y1,x1,y2,i) ; return 0 ; }
    }
}
