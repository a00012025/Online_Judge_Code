#include<stdio.h>
main()
{
    int a[6] ; int sum=0 ;
    for(int i=1;i<=5;i++) {scanf("%d",&a[i]) ; sum+=a[i] ;}
    if(sum%5) printf("-1\n") ;
    else if(!sum) printf("-1\n") ;
    else printf("%d\n",sum/5) ;
}
