#include<stdio.h>
#include<algorithm>
using namespace std;
bool comp(int a,int b)
{
 int c,d;
 c=a%10 ;
 d=b%10 ;
 if(c!=d) return c<d ; 
 else return a>b ;
} 
main()
{
 int n,a[1001],i;
 while(scanf("%d",&n)==1)
 {
 for(i=1;i<=n;i++) scanf("%d",&a[i]);
 sort(&a[1],&a[n+1],comp);
 for(i=1;i<=n;i++) printf("%d ",a[i]);
 printf("\n");
 }
}
