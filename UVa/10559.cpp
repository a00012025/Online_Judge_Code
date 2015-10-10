#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#define LL long long
using namespace std;
struct P {int id,num ;};
vector<P> v ;
int a[300] ;
LL d[211][211][211] ;

LL dp(int i,int j,int k)
{
    if(d[i][j][k]!=-1) return d[i][j][k] ;
    if(i==j) return (d[i][j][k]=(k+v[i].num)*(k+v[i].num)) ;
    LL ret=dp(i,j-1,0)+(v[j].num+k)*(v[j].num+k) ;
    for(int l=j-1;l>=i;l--) if(v[l].id==v[j].id)
        ret=max(ret,dp(l+1,j-1,0)+dp(i,l,k+v[j].num)) ;
    return (d[i][j][k]=ret) ;
}

main()
{
    int T,tc=0;
    scanf("%d",&T) ;
    while(T--)
    {
        int n;
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        v.clear() ;
        int cnt=0 ;
        for(int i=1;i<=n;i++)
        {
            if(i>1 && a[i]!=a[i-1])
            {
                v.push_back((P){a[i-1],cnt}) ;
                cnt=1 ;
            }
            else cnt++ ;
        }
        v.push_back((P){a[n],cnt}) ;
        n=v.size() ;
        memset(d,-1,sizeof(d)) ;
            //for(int i=0;i<n;i++) printf("%d,%d\n",v[i].id,v[i].num) ;
        printf("Case %d: %lld\n",++tc,dp(0,n-1,0)) ;
    }
}
