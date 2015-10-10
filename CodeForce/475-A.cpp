#include<stdio.h>
main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a,b,c,d ;
        if(n>=3) c=1 ;
        else c=0 ;
        if(n<=4) a=1 ;
        else a=(n+1)/3 ;
        if(n==1) b=0 ;
        else if(n<=5) b=1 ;
        else b=n/3 ;
        d=(n-1)/3 ;
        if(n==0) a=b=c=d=0 ;
        printf("+------------------------+\n|") ;
        for(int i=1;i<=a;i++) printf("O.") ;
        for(int i=1;i<=11-a;i++) printf("#.") ;
        printf("|D|)\n|") ;
        for(int i=1;i<=b;i++) printf("O.") ;
        for(int i=1;i<=11-b;i++) printf("#.") ;
        printf("|.|\n|") ;
        printf("%c",c==0 ? '#' : 'O') ;
        printf(".......................|\n|") ;
        for(int i=1;i<=d;i++) printf("O.") ;
        for(int i=1;i<=11-d;i++) printf("#.") ;
        printf("|.|)\n+------------------------+\n") ;
    }
}
