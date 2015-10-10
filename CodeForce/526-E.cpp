#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1000000+10 ;

int n,a[maxn],len[maxn] ;
int dis(int x,int y)
{
    if(y>=x) return y-x ;
    return n+y-x ;
}

LL s[2*maxn] ;
main()
{
    int Q ; scanf("%d%d",&n,&Q) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    for(int i=1;i<=2*n;i++) s[i]=s[i-1]+(i>n?a[i-n]:a[i]) ;
    while(Q--)
    {
        LL x ; scanf("%lld",&x) ;
        if(x>=s[n]) { printf("1\n") ; continue ; }
        int id,mi=n+1 ;
        for(int i=n,j=2*n-1;i>=1;i--)
        {
            while(s[j]-s[i-1]>x) j-- ;
            len[i]=min(n,j-i+1) ;
            //printf("len[%d]=%d\n",i,len[i]) ;
            if(len[i]<mi) mi=len[id=i] ;
        }

        int ans=n ;
        for(int i=id;i<=id+len[id];i++)
        {
            int cnt=0 , st=(i-1)%n+1 ;
            for(int j=st;!cnt || dis(j,st)>len[j];
                j=(j+len[j]-1)%n+1,cnt++) ;
            ans=min(ans,cnt+1) ;
        }
        printf("%d\n",ans) ;
    }
}
