#include<bits/stdc++.h>
using namespace std;
const int maxn=10000 + 5 ;
int pm[maxn],cnt ;
bool vis[maxn] ;
void get_prime()
{
    memset(vis,0,sizeof(vis)) ;
    for(int i=2;i<maxn;i++) if(!vis[i])
        for(int j=i*i;j<maxn;j+=i) vis[j]=1 ;
    cnt=0 ;
    for(int i=2;i<maxn;i++) if(!vis[i])
        pm[++cnt]=i ;
}

int a[maxn] ;

void add_factorial(int x,int type)
{
    if(x==1) return ;
    for(int i=1;i<=cnt && pm[i]<=x;i++)
    {
        int add=0 , j=x ;
        while(j) {add+=j/pm[i] ; j/=pm[i] ;}
        a[i] += add*type ;
    }
}

main()
{
    get_prime() ;
    int p,q,r,s ;
    while(scanf("%d%d%d%d",&p,&q,&r,&s)!=EOF)
    {
        memset(a,0,sizeof(a)) ;
        add_factorial(p,1) ;
        add_factorial(q,-1) ;
        add_factorial(p-q,-1) ;
        add_factorial(r,-1) ;
        add_factorial(s,1) ;
        add_factorial(r-s,1) ;
        double ans=1.0 ;
        for(int i=1;i<=cnt;i++) if(a[i])
        {
            if(a[i]>0) for(int j=1;j<=a[i];j++) ans *= pm[i] ;
            else for(int j=1;j<=-a[i];j++) ans /= pm[i] ;
        }
        printf("%.5f\n",ans) ;
    }
}
