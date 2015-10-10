#include<stdio.h>
char s[100]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./" ;
main()
{
    int c;
    while(c=getchar())
    {
        if(c==EOF) break;
        if(c==' ' || c=='\n') printf("%c",c) ;
        else
        {
            int i ;
            for(i=0;s[i]!=c;i++) ;
            printf("%c",s[i-1]) ;
        }
    }
}
