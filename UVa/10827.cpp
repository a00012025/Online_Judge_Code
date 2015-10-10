#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<deque>
using namespace std;
struct P {int val,id;};
int a[160][160],sum[160][160],b[160] ;

int cal(int x,int y,int z,int w)
{
    return sum[z][w]-sum[x-1][w]-sum[z][y-1]+sum[x-1][y-1] ;
}

int max_sum(int *p,int n)
{
    deque<P> dq ;
    int sum=0,ret=-10000000 ;
    dq.push_front((P){0,0}) ;
    for(int i=1;i<=n;i++)
    {
        while(dq.front().id < i-n/2) dq.pop_front() ;
        sum+=p[i] ;
        ret=max(ret,sum-dq.front().val) ;
        while(!dq.empty() && dq.back().val >= sum) dq.pop_back() ;
        dq.push_back((P){sum,i}) ;
    }
    return ret ;
}

main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]) ;
            a[i+n][j+n]=a[i][j+n]=a[i+n][j]=a[i][j] ;
        }
        n*=2 ;
        memset(sum,0,sizeof(sum)) ;
        int ans=-10000000 ;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
            sum[i][j]=a[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1] ;
        for(int i=1;i<=n;i++) for(int j=i;j<=n && j-i+1<=n/2;j++)
        {
            for(int k=1;k<=n;k++) b[k]=cal(i,k,j,k) ;
            ans=max(ans,max_sum(b,n)) ;
            for(int k=1;k<=n;k++) b[k]=cal(k,i,k,j) ;
            ans=max(ans,max_sum(b,n)) ;
        }
        printf("%d\n",ans) ;
    }
}
