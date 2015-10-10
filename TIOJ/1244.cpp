#include<bits/stdc++.h>
#define LL long long
#define MOD 100000007
using namespace std;
const int maxn=10000+10,maxc=3000 ;

int fac[maxn] ;
int c[maxc][maxc] ;

void gcd(int a,int b,int &x,int &y)
{
    if(b==0) x=1 , y=0 ;
    else gcd(b,a%b,y,x) , y-=(a/b)*x ;
}

int inv(int n)
{
    int a,b ;
    gcd(n,MOD,a,b) ;
    return a<0?a+MOD:a ;
}

LL C(int a,int b)
{
    if(a<maxc) return (LL)c[a][b] ;
    return ((((LL)fac[a])*((LL)inv(fac[b]))%MOD)*((LL)inv(fac[a-b])))%MOD ;
}

int ans[maxn] ;

int f(int n)
{
    if(ans[n]!=-1) return ans[n] ;
    ans[n]=0LL ;
    for(int i=0;i<n;i++) ans[n]=
        (ans[n]+(((LL)C(n-1,i))*((LL)f(i)))%MOD)%MOD ;
    return ans[n] ;
}

main()
{
    fac[0]=1 ;
    for(int i=1;i<maxn;i++) fac[i]=((LL)fac[i-1]*i)%MOD ;
    for(int i=1;i<maxc;i++) for(int j=0;j<=i;j++)
        c[i][j]=j==0||j==i ? 1 : (c[i-1][j]+c[i-1][j-1])%MOD ;

    for(int i=0;i<maxn;i++) ans[i]=-1 ;
    ans[0]=ans[1]=1 ;
    int n ; scanf("%d",&n) ;
    printf("%d\n",f(n)) ;
}
