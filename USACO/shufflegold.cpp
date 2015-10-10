#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

int per[31][maxn] ;
main()
{
    freopen("shufflegold.in","r",stdin) ;
    freopen("shufflegold.out","w",stdout) ;
    int m,n,Q ; scanf("%d%d%d",&m,&n,&Q) ;
    for(int i=1;i<=n;i++)
    {
        int x ; scanf("%d",&x) ;
        per[0][n+1-x]=(n+1-i)-1 ;
    }
    for(int i=1;i<31;i++) for(int j=1;j<=n;j++)
        per[i][j]=per[i-1][per[i-1][j]] ;

    while(Q--)
    {
        int x ; scanf("%d",&x) ;
        x=m+1-x ;
        int bot=min(m,x+n-1) , k=0 ;
        int now=bot-x+1 ;

        for(int i=30 , num=bot-n;i>=0;i--)
            if(num>=(1<<i) && per[i][now])
        {
            now=per[i][now] ;
            k^=(1<<i) ;
            num-=(1<<i) ;
        }
        k++ ; now=per[0][now] ;
        printf("%d\n",bot-k+1-now) ;
    }
}
