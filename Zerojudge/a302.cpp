#include<bits/stdc++.h>
#define MOD 10007
using namespace std;

int power(int x,int y)
{
    if(y<=1) return y==1?x:0 ;
    int tmp=power(x,y/2) ;
    if(y%2) return ((long long)tmp*tmp*x) % MOD ;
    else return (tmp*tmp)%MOD ;
}

int C[1001][1001] ;
void pre_cal()
{
    for(int i=0;i<=1000;i++) for(int j=0;j<=i;j++)
        C[i][j]= j==0||j==i ? 1 : ((C[i-1][j]+C[i-1][j-1])%MOD) ;
}

main()
{
    pre_cal() ;
    int a,b,k,n,m ; scanf("%d%d%d%d%d",&a,&b,&k,&n,&m) ;
    if(k==0) { printf("1\n") ; return 0 ; }
    a%=MOD ; b%=MOD ;
    int ans1=power(a,n) , ans2=power(b,m) ;
    ans1=(ans1*C[k][n])%MOD ;
    printf("%d\n",(ans1*ans2)%MOD) ;
}
