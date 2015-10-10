#include<stdio.h>
#include<string.h>
char s[1000000],t[1000000] ;
main()
{
    while(scanf("%s %s",s,t)!=EOF)
    {
        int num=0,i ;
        for(i=0;i<strlen(s);i++)
        {
            for(;t[num]!=s[i] && num<strlen(t);num++) ;
            if(num==strlen(t)) break ;
            num++ ;
        }
        if(i!=strlen(s)) printf("No\n") ;
        else printf("Yes\n") ;
    }
}
