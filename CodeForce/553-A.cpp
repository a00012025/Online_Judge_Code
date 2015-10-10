#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
const int maxn=2000+10 ;

int C[maxn][maxn] ;
main()
{
    C[1][0]=C[1][1]=1 ;
    for(int i=2;i<maxn;i++) for(int j=0;j<=i;j++)
    {
        if(j==0||j==i) C[i][j]=1 ;
        else C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD ;
    }

    int n ; scanf("%d",&n) ;
    int ans=1 ;
    for(int i=1,s=0;i<=n;i++)
    {
        int x ; scanf("%d",&x) ;
        if(i==1){s+=x ; continue ;}
        ans=(long long)ans*C[x+s-1][x-1] %MOD ;
        s+=x ;
    }
    printf("%d\n",ans) ;
}
