#include<stdio.h>
#include<string.h>
main()
{
    char s[200] ;
    while(scanf("%s",s)!=EOF)
    {
        int a=0,b=0,n=strlen(s) ;
        for(int i=0;i<n;i++) if(s[i]=='0') b++ ;
        for(int i=0;i<n-1;i++) if(s[i]=='0' && s[i+1]=='0') a++ ;
        if(s[0]=='0' && s[n-1]=='0') a++ ;
        if(b*b==a*n) printf("EQUAL\n") ;
        else if(b*b>a*n) printf("ROTATE\n") ;
        else printf("SHOOT\n") ;
    }
}
