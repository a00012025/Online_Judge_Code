#include<stdio.h>
#include<string.h>
char c[18]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'} ;
main()
{
    int n;
    char s[100],ans[100] ;
    while(scanf("%s",s)==1)
    {
        if(s[0]=='-') break ;
        if(s[1]!='x')
        {
            int a=0,num=0;
            for(int i=0;i<strlen(s);i++){a=a*10 ; a=a+s[i]-'0';}
            for(;a>0;a=a/16,num++) ans[num]=c[a%16] ;
            printf("0x") ;
            for(int i=num-1;i>=0;i--)printf("%c",ans[i]);
            printf("\n") ;
        }
        else
        {
            int a=0 ;
            for(int i=2;i<strlen(s);i++)
            {
                int j ;
                for(j=0;c[j]!=s[i];j++) ;
                a=a*16 ;
                a=a+j ;
            }
            printf("%d\n",a) ;
        }

    }
}
