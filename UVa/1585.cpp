#include<stdio.h>
#include<string.h>
main()
{
    int n;
    char s[100] ;
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s) ; int num=0,ans=0 ;
        for(int j=0;j<strlen(s);j++)
        {
            if(s[j]=='O') {num++ ; ans+=num ;}
            else if(s[j]=='X') num=0 ;
        }
        printf("%d\n",ans) ;
    }
}
