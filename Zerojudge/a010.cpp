#include<stdio.h>
main()
{
 int n,N,i,j,k,fir;
 bool a[1001];
 int b[1001];
 for(i=1;i<=1000;i++) a[i]=1;
 a[1]=0 ; a[2]=1 ;
 for(i=1;i<=1000;)
 	{
	for(j=i;a[j]==0;j++);
	for(k=2;k*j<=1000;k++) a[k*j]=0 ;
	i=j+1;
  	} 
 N=1;
 for(i=1;i<=1000;i++)
 	{
 	if(a[i]==0) continue;
 	b[N]=i ; N=N+1 ;
 	}				//b[1]~b[168]¬°1~1000½è¼Æ 
 while(scanf("%d",&n)==1)
 {
 fir=1;
 for(i=1;i<=168;i++)
 	{
 	 if((n%b[i])!=0) continue;
 	 if(fir==1) fir=0;
 	 else printf(" * ");
 	 N=0 ;
 	 while((n%b[i])==0)
 	 	{
 	 	N+=1 ; n=n/b[i] ;
 	 	}
 	 if(N==1) printf("%d",b[i]);
	 else printf("%d^%d",b[i],N);
 	}
 if(fir==1) printf("%d",n);
 else if(n!=1) printf(" * %d",n);
 printf("\n"); 
 }
}
