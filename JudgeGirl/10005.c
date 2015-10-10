#include<stdio.h>
#include<string.h>
main()
{
    char s[2000] ;
    while(scanf("%s",s)!=EOF)
    {
        int n=strlen(s),m ;
        for(int i=0;i<n;)
        {
            while(i<n && (s[i]<'0' || s[i]>'9')) i++ ;
            if(i==n) break ;
            sscanf(&s[i],"%d",&m) ;
            printf("%d\n",m) ;
            while(i<n && s[i]>='0' && s[i]<='9') i++ ;
        }
    }
}
