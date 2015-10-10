#include<bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const int maxn=3000 ;
bool vis[maxn] ;
int phi[maxn] ;

int gcd(int x,int y)
{
    return y==0 ? x : gcd(y,x%y) ;
}

void phi_table()
{
    memset(vis,0,sizeof(vis)) ;
    for(int i=2;i*i<maxn;i++) if(!vis[i])
        for(int j=i*i;j<maxn;j+=i)
        vis[j]=1 ;
    memset(phi,0,sizeof(phi)) ;
    phi[1]=1 ;
    for(int i=2;i<maxn;i++) if(!vis[i])
        for(int j=i;j<maxn;j+=i)
    {
        if(phi[j]==0) phi[j]=j ;
        phi[j]=(phi[j]/i)*(i-1) ;
    }
}

main()
{
    phi_table() ;
    int a,b ;
    while(scanf("%d%d",&a,&b)==2 && a+b)
    {
        LL ans1=0LL ;
        for(int i=1;i<=a;i++)
        {
            int q=b/i , r=b%i ;
            ans1+=((LL)q)*((LL)phi[i]) ;
            for(int j=q*i+1;j<=b;j++) ans1+= gcd(i,j)==1 ? 1LL : 0LL ;
        }
        ans1=ans1*4+4 ;
        LD ans=((LD)ans1)/((((LD)2*a+1))*((LD)2*((LD)b)+1)-1) ;
        printf("%.7Lf\n",ans) ;
    }
}
