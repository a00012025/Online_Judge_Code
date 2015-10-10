#include<stdio.h>
#include<string.h>
main()
{
    char s[2000],t[2000] ;
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int no=0 ;
        scanf("%s %s",s,t) ;
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]=='?' && t[i]=='?') no=1 ;
            if(s[i]!='?') t[i]=s[i] ;
            if(t[i]!='?') s[i]=t[i] ;
        }
        if(no) printf("No\n") ;
        else
        {
            printf("Yes:") ;
            for(int i=0;i<strlen(s);i++) printf("%c",s[i]) ;
            printf("\n") ;
        }
    }
}
