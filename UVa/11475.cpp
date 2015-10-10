#include<stdio.h>
#include<string.h>
char s[100001],t[100001] ;
int fail[100005] ;
main()
{
    while(scanf("%s",s)!=EOF)
    {
        int len=strlen(s) ;
        for(int i=0;i<len;i++) t[i]=s[len-1-i] ;
        fail[0]=-1 ; int now=-1 ;
        for(int i=1;i<len;i++)
        {
            while(now>=0 && t[now+1]!=t[i]) now=fail[now] ;
            if(t[now+1]==t[i]) now++ ;
            fail[i]=now ;
        }
        int k=-1 ;
        for(int i=0;i<len;i++)
        {
            while(k>=0 && t[k+1]!=s[i]) k=fail[k] ;
            if(t[k+1]==s[i]) k++ ;
            //printf("%d,",k);
        }
            //printf("\n");
            //for(int i=0;i<len;i++)printf("%d,",fail[i]);
            //printf("\n");
        for(int i=0;i<len;i++)printf("%c",s[i]);
        for(int i=len-k-2;i>=0;i--)printf("%c",s[i]);
        printf("\n");
    }
}
