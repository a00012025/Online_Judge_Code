#include<stdio.h>
#include<string.h>
char s[100],t[100] ;
main()
{
    scanf("%s%s",s,t) ;
    int n=strlen(s),m=strlen(t) ;
    int ans=0 ;
    for(int i=0;i<=m-n;i++)
    {
        int ok=1 ;
        for(int j=0;j<n;j++) if(s[j]!=t[i+j])
            {ok=0 ; break ;}
        ans+=ok ;
    }
    printf("%d\n",ans) ;
}
