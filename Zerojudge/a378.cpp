#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int c[100001],d[100001],k,n;
bool comp(int a,int b)
{
 return a>b ;
}
bool comp_k()
{
 int i,ret=1;
 sort(&d[1],&d[n+1],comp);
 for(i=1;i<=k;i++) if(d[i]<=c[k+1-i]) {ret=0 ; break;}
 return ret;
}
main()
{
 int N,NN,i,x,y,z;
 int a[100001];
 while(scanf("%d",&NN)==1)
 {
 for(N=1;N<=NN;N++)
 {
 memset(a,0,sizeof(a)); memset(c,0,sizeof(c)); 
 memset(d,0,sizeof(d));
 scanf("%d %d",&n,&k);
 for(i=1;i<=n;i++) scanf("%d",&a[i]);
 for(i=1;i<=n;i++) scanf("%d",&c[i]);
 sort(&c[1],&c[n+1]);
 for(i=1;i<=n;i++) d[i]=a[i];
 if(comp_k()==1) {printf("0\n") ; continue ;}
 x=0 ; y=200000000 ;
 while(y-x>1)
    {
    z=(x+y)/2 ;
    for(i=1;i<=n;i++) d[i]=a[i]+z ;
    if(comp_k()==1) y=z ;
    else x=z ;
    }
 printf("%d\n",y);
 }
 }
}
