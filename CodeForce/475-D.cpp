#include<stdio.h>
#include<map>
#include<stdlib.h>
#define LL long long
using namespace std;
int a[100001],G[100001][20] ;
map<int,LL> mp ;
int gcd(int a,int b)
{
    return b==0 ? a : gcd(b,a%b) ;
}
main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]) ; G[i][0]=a[i] ;}
    for(int j=1;j<20;j++) for(int i=1;i<=n;i++)
    {
        if((i+(1<<j))>n+1) continue ;
        G[i][j]=gcd(G[i][j-1],G[i+(1<<(j-1))][j-1]) ;
    }
    for(int i=1;i<=n;i++)
    {
        int g=a[i],k,left=i,right=i ;
        while(right<=n)
        {
            k=19 ;
            while(k>=0)
            {
                while(k>=0 && (right+(1<<k)>n+1 || G[right][k]%g!=0)) k-- ;
                    //printf("%d,%d,%d,%d\n",i,right,g,k) ;
                if(k<0) break ;
                right+=(1<<k) ;
            }
            if(mp.count(g)) mp[g]+=right-left ;
            else mp[g]=right-left ;
                //printf("%d : %d ~ %d\n",g,left,right-1) ;
            left=right ;
            if(right<=n) g=gcd(g,a[right]) ;
        }
    }
    int Q;
    scanf("%d",&Q) ;
    for(int i=1;i<=Q;i++)
    {
        int x;
        scanf("%d",&x) ;
        if(mp.count(x)) printf("%I64d\n",mp[x]) ;
        else printf("0\n") ;
    }
}
