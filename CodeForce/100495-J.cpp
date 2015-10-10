#include<stdio.h>
#define LL long long
int p[100],ans ;
long long a,b ;

int gcd(int x,int y)
{
    while(x!=0 && y!=0)
    {
        if(x>y) x=x%y ;
        else y=y%x ;
    }
    if(!x) return y ;
    else return x ;
}

void make_prime()
{
    for(int i=0;i<100;i++) p[i]=1 ;
    for(int i=2;i<100;)
    {
        for(int j=2;i*j<100;j++) p[i*j]=0 ;
        i++ ;
        while(p[i]==0) i++ ;
    }
}

bool isprime(int n)
{
    if(n==1 || n==0) return false ;
    else if(p[n]) return true;
    else return false;
}

bool ok(int n)
{
    int n1=n/10 , n2=n%100 ;
    if(isprime(n1) || isprime(n2)) return false ;
    if(gcd(n1,n2)!=1) return false ;
    return true ;
}

void dfs(long long n)
{
    if(n>=a && n<=b) ans++ ;
    if(n>b) return ;
    int p=n%100 ;
    for(int i=0;i<10;i++)
        if(ok(p*10+i)) dfs(n*10+i) ;
}

main()
{
    make_prime() ;
    int T,tc=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d %I64d",&a,&b) ;
        ans=0 ;
        for(int i=10;i<=99;i++) if(!isprime(i)) dfs(i) ;
        printf("Case #%d: %d\n",++tc,ans) ;
    }
}
