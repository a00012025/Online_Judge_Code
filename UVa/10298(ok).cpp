#include<stdio.h>
#include<string.h>
char s[1010000] ;
int fail[1010000] ;
main()
{
    while(scanf("%s",s)==1)
    {
        if(s[0]=='.') break ;
        int len=strlen(s) ;
        fail[0]=-1 ; int k=-1 ;
        for(int i=1;i<len;i++)
        {
            while(k>=0 && s[i]!=s[k+1]) k=fail[k] ;
            if(s[i]==s[k+1]) k++ ;
            fail[i]=k ;
        }
        int p=len-1-fail[len-1] , ans=p ;
        for(int i=0;i+p<len;i++)
            if(s[i+p]!=s[i]) {ans=1 ; break ;}
        printf("%d\n",len/ans) ;
    }
}
