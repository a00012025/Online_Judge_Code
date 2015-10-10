#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=2000+5 ;

int a[maxn][maxn] ;
LL s1[2*maxn],s2[2*maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
    {
        int x ; scanf("%d",&x) ;
        a[i][j]=x ;
        s1[i-j+n-1]+=x ;
        s2[i+j]+=x ;
    }
    int a1,a2,b1,b2 ;
    LL S1=-1,S2=-1 ;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
    {
        LL S=s1[i-j+n-1]+s2[i+j]-a[i][j] ;
        if((i+j)%2==1 && S>S1) S1=S , a1=i , b1=j ;
        if((i+j)%2==0 && S>S2) S2=S , a2=i , b2=j ;
    }
    printf("%I64d\n%d %d %d %d\n",S1+S2,a1,b1,a2,b2) ;
}
