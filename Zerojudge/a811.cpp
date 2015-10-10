#include<stdio.h>
#include<algorithm>
using namespace std;
bool comp(long long a,long long b)
{
 return a>b ;
}
long long gcd(long long a,long long b)
{
 if(a==1) return 1;
 if(b==1) return 1;
 while((a%b!=0)&&(b%a!=0))
    {
    if(a>b) a=a%b ;
    else b=b%a ;
    }
 if(a%b==0) return b ;
 else return a ;
}
main()
{
 int N,n;
 long long a[10001] ;
 while(scanf("%d",&N)==1)
 {
 while(N--)
 {
 scanf("%d",&n) ;
 for(int i=1;i<=n;i++) scanf("%lld",&a[i]) ;
 if(n==2) {printf("%lld\n",a[2]-a[1]) ; continue ;}
 sort(&a[1],&a[n+1],comp) ;
 long long gg=gcd(a[1]-a[2],a[2]-a[3]) ;
 for(int i=4;i<=n;i++) gg=gcd(gg,a[i-1]-a[i]) ;
 printf("%lld\n",gg) ;
 }
 }
}
