#include<stdio.h>
#include<algorithm>
#define INF (1LL<<60)
#define LL long long
using namespace std;
LL a[101][101],d[101][101] ;
int dx[4]={1,0,-1},next[101][101] ;
main()
{
    int n,m ;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
            scanf("%lld",&a[i][j]) ;
        int fir ; LL ans=INF ;
        for(int j=m-1;j>=0;j--) for(int i=0;i<n;i++)
        {
            if(j==m-1) d[i][m-1]=a[i][m-1] ;
            else
            {
                d[i][j]=INF ;
                int ni[4] ;
                ni[0]= (i==0 ? (n-1) : (i-1)) ;
                ni[1]= i ;
                ni[2]= (i==n-1 ? 0 : i+1) ;
                sort(ni,ni+3) ;
                for(int k=0;k<3;k++)
                    if(d[ni[k]][j+1]+a[i][j]<d[i][j])
                    {
                        d[i][j] = d[ni[k]][j+1]+a[i][j] ;
                        next[i][j]=ni[k] ;
                    }
            }
            if(j==0 && d[i][j]<ans) ans=d[fir=i][j] ;
        }
        for(int j=0;j<m;j++)
        {
            printf("%d%c",fir+1,j==m-1?'\n':' ') ;
            fir=next[fir][j] ;
        }
        printf("%lld\n",ans) ;
    }
}
