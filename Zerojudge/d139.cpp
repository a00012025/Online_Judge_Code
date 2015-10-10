#include<stdio.h>
#include<string.h>
main()
{
    char s[2001] ;
    while(scanf("%s",s)!=EOF)
    {
        int num=0 ;
        for(int i=0;i<strlen(s);i++)
        {
            if(i!=0 && s[i-1]!=s[i])
            {
                if(num==1) printf("%c",s[i-1]) ;
                else if(num==2) printf("%c%c",s[i-1],s[i-1]) ;
                else printf("%d%c",num,s[i-1]) ;
                num=1 ;
            }
            else if(i==0) num=1 ;
            else num++ ;
        }
        if(num==1) printf("%c",s[strlen(s)-1]) ;
        else if(num==2) printf("%c%c",s[strlen(s)-1],s[strlen(s)-1]) ;
        else printf("%d%c",num,s[strlen(s)-1]) ;
        printf("\n") ;
    }
}
