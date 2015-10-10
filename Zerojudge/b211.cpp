#include<bits/stdc++.h>
using namespace std;
const int maxn=1010 ;
bool vis[maxn] ;
int pr[maxn],cnt ;

void make_prime()
{
    memset(vis,0,sizeof(vis)) ;
    for(int i=2;i*i<maxn;i++) if(!vis[i])
        for(int j=i*i;j<maxn;j+=i)
        vis[j]=1 ;
    cnt=0 ;
    for(int i=2;i<maxn;i++) if(!vis[i])
        pr[++cnt]=i ;
}

int gcd(int x,int y)
{
    return y==0?x:gcd(y,x%y) ;
}

int get_pow(int x,int m,int p)
{
    int ret=1 ;
    while(m--) ret*=x , ret%=p ;
    return ret ;
}

main()
{
    make_prime() ;
    int a,b,m,n,p ;
    while(scanf("%d%d%d%d%d",&a,&b,&m,&n,&p)!=EOF)
    {
        int x=get_pow(a,gcd(m,n),p) , y=get_pow(b,gcd(m,n),p) ;
        int ans=(x-y+p)%p ;
        int val=gcd(a,b) ;
        for(int i=1;val!=1 && i<=cnt;i++) if(val%pr[i]==0)
        {
            int t=0 ;
            while(val%pr[i]==0) val/=pr[i] , t++ ;
            int mul=get_pow(pr[i],t*min(m,n)-t*gcd(m,n),p) ;
            ans*=mul ; ans%=p ;
        }
        printf("%d\n",ans) ;
    }
}
