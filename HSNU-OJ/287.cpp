#include<stdio.h>
main()
{
    int n,num=0 ; scanf("%d",&n) ;
    for(int i=n-1;i;i/=2,num++) ;
    printf("%d\n",num) ;
    for(int i=0;i<num;i++)
    {
        int cnt=0 ;
        for(int j=0;j<n;j++) if(j&(1<<i)) cnt++ ;
        printf("%d",cnt) ;
        for(int j=0;j<n;j++) if(j&(1<<i)) printf(" %d",j+1) ;
        puts("") ;
    }
}
