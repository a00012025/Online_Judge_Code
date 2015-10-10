#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{
 int a,b,a1,b1,n,mina,minb ;
 long long min ;
 while(scanf("%d %d %d",&n,&a,&b)==3)
 {
 if((((double)n)/a)/b<=(((double)1)/6))
            {
                long long A=a,B=b ;
                printf("%I64d\n%d %d\n",A*B,a,b) ; continue ;
                }
 int i,j,yes=0 ;
 min=100000000000000,mina=a,minb=b ;
 long long N=n ;
 N=N*6 ;
 if(N%a==0) {
            long long M=N/a ;
            printf("%I64d\n%d %I64d\n",N,a,M) ; 
            continue ;
            }
 else if(N%b==0) {
            long long M=N/b ;
            printf("%I64d\n%I64d %d\n",N,M,b) ; 
            continue ;
            }
 for(j=0;;j++)
 {
 if(((double)a)/n>=((double)6)/(b+j-1)) break ;
 if(n%(b+j)==0) {
            long long M=n/(b+j) ; M=M*6 ;
            printf("%I64d\n%I64d %d\n",N,M,b+j) ; 
            yes=1 ; break;
            }
 i=(int)(((((double)6)/(b+j))*n)-a-0.0000000001) ;
 i=i+1 ;
 if(((double)(a+i))/n>=((double)6)/(b+j) 
                && (double)(b+j)<((double)min)/(a+i))
    {
    mina=a+i ;
    minb=b+j ;
    long long A=a+i,B=b+j  ;
    if(A*B<min) min=A*B ;
    }
 if(b+j>sqrt(N)) break;
 }
 if(yes==0)printf("%I64d\n%d %d\n",min,mina,minb) ;
 }
}

