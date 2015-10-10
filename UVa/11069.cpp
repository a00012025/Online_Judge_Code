#include<stdio.h>
int a[100] ;
main()
{
    a[1]=1 ; a[2]=2 ; a[3]=2 ;
    for(int i=4;i<100;i++) a[i]=a[i-2]+a[i-3] ;
    int n;
    while(scanf("%d",&n)!=EOF) printf("%d\n",a[n]);
}
