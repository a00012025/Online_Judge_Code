#include<stdio.h>
#include<string.h>
main()
{
    int n,T,fir=1;
    char s[10000] ;
    while(scanf("%d",&T)==1) while(T--)
    {
        scanf("%s",s) ; int i ;
        while(strlen(s)==0) scanf("%s",s) ;
        for(i=1;i<strlen(s);i++)
        {
            bool yes=1 ;
            for(int j=0;j+i<strlen(s);j++) if(s[j]!=s[j+i]) yes=0;
            if(yes==1 && strlen(s)%i==0) break;
            else yes=0 ;
        }
        //if(fir) fir=0;
        //else printf("\n\n") ;
        printf("%d\n",i) ;
        if(T) printf("\n") ;
    }
}
