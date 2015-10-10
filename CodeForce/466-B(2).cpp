#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{
 int a,b,n ;
 long long M,ans,newa,newb;
 while(scanf("%d %d %d",&n,&a,&b)==3)
 {
 M=(long long)n*6 ;
 if((long long)a*b>=M) printf("%I64d\n%d %d\n",(long long)a*b,a,b) ;
 else if(M%a==0) printf("%I64d\n%d %I64d\n",M,a,M/a) ;
 else if(M%b==0) printf("%I64d\n%I64d %d\n",M,M/b,b) ;
 else
    {
    ans=10000000000000000 ;
    long long N=(long long)ceil(sqrt(M)) ;
    int tem=0 ;
    if(a>b){tem=a ; a=b ; b=tem ;}
    for(long long i=a;i<=N+2;i++)
        {
        long long j=(long long)ceil((double)M/i) ;
        if(j<(long long)b) continue ;
        if(i*j<ans)
            {
            newa=i ; newb=j ; ans=i*j ;
            }
        }
    if(tem==0) printf("%I64d\n%I64d %I64d\n",ans,newa,newb) ;
    else printf("%I64d\n%I64d %I64d\n",ans,newb,newa) ;
    }
 }
}
