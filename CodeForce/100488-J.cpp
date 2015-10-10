#include<stdio.h>
#include<stdlib.h>
#define LL long long
LL a[50001],b[50001] ;
main()
{
            //freopen("1.txt","r",stdin);
            //freopen("2.txt","w",stdout);

    LL n;
    while(scanf("%I64d",&n)!=EOF){ int num,num2 ;
    if(n<=26)
    {
        for(int i=1;i<=n;i++) printf("%c",'a'+i-1) ;
        printf("\n");
        return 0 ;
    }
    for(LL i=0;i<=50000;i++) a[i]=(LL)i*(i+1)/2+(i/2)+2 ;
    for(LL i=0;i<=50000;i++) b[i]=(LL)i*(i+1)/2+(i/2)*2+2 ;
    n=n+2 ;
    for(num=1;a[num]+a[num+1]<n;num++) ;
    num-- ;
    LL rem=n-a[num]-a[num+1] ;
    for(int i=1;i<=num;i++) printf("a") ;
    printf("bc") ; char c='d' ;
    while(rem>=8)
    {
        int num2 ;
        for(num2=1;b[num2]<rem;num2++) ;
        num2-- ;
        for(int i=1;i<=num2;i++) printf("a") ;
        printf("%c%c",c,c+1) ;
        c=c+2 ;
        rem-=b[num2] ;
    }
    for(int i=1;i<=rem;i++) printf("%c",c++) ;
    for(int i=1;i<=num+1;i++) printf("a") ;
    printf("\n") ;
    }
}
