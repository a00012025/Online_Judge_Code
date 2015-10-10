#include<stdio.h>
#include<string.h>
main()
{
    char s[100]={"qwertyuiopasdfghjkl;zxcvbnm,./"} ;
    char c,t[100];
    scanf("%c",&c);
    scanf("%s",t) ;
    if(c=='L')
    {
        for(int i=0;i<strlen(t);i++)
        {
            int k;
            for(k=0;s[k]!=t[i];k++) ;
            printf("%c",s[k+1]) ;
        }
    }
    else
    {
        for(int i=0;i<strlen(t);i++)
        {
            int k;
            for(k=0;s[k]!=t[i];k++) ;
            printf("%c",s[k-1]) ;
        }
    }
    printf("\n") ;
}
