#include<stdio.h>
#include<string.h>
main()
{
    int a[20],x[10001];
    while(scanf("%d",&a[1])!=EOF)
    {
        memset(x,0,sizeof(x)) ;
        for(int i=2;i<=12;i++) scanf("%d",&a[i]) ;
        int num=0,no=0 ;
        for(int i=1;i<=12;i++)
        {
            if(x[a[i]]==0) num++ ;
            x[a[i]]++ ;
        }
        for(int i=1;i<=10000;i++) if(x[i]%2!=0) no=1 ;
        if(num>=4 || no==1) printf("IMPOSSIBLE\n") ;
        else if(num==1) printf("POSSIBLE\n") ;
        else if(num==2)
        {
            no=0 ;
            for(int r=1;r<=12;r++)
                if(x[a[r]]==6 || x[a[r]]==10) no=1 ;
            if(no==1) {printf("IMPOSSIBLE\n") ; continue;}
            int dif=0 ;
            for(int r=1;r<=6;r++) if(a[2*r-1]!=a[2*r]) dif+=1;
            if(dif!=4) printf("IMPOSSIBLE\n");
            else printf("POSSIBLE\n") ;
        }
        else if(num==3)
        {
            no=0 ;
            for(int r=1;r<=12;r++)
                if(x[a[r]]!=4) no=1 ;
            for(int i=1;i<=6;i++)
                if(a[2*i-1]==a[2*i]) no=1 ;
            if(no==1) printf("IMPOSSIBLE\n") ;
            else printf("POSSIBLE\n") ;
        }
    }
}
