#include<stdio.h>
#include<string.h>
char s[1001000];
main()
{
    while(gets(s))
    {
        int len=strlen(s);
            //for(int i=0;i<len;i++)printf("%d,",s[i]);
        if(len==0){printf("0\n");continue ;}
        int ans=len ;
        if(s[len-1]==10 || s[len-1]=='\n' || s[len-1]=='\r') len-- ;
        for(int k=1;k<=len;k++)
        {
            bool yes=1 ;
            for(int i=0;i<len;i++)
            {
                if(i+k>=len) break ;
                if(s[i+k]!=s[i]) {yes=0 ; break ;}
            }
            if(yes) {ans=k ; break ;}
        }
        printf("%d\n",len/ans) ;
    }
}
