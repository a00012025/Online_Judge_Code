#include<stdio.h>
#include<string.h>
main()
{
    char s[200] ;
    int a[200],fir=1 ;
    while(gets(s))
    {
        int l=strlen(s) ;
        if(s[0]=='0') break ;
        for(int i=0;i<l;i++) a[i]=s[i]-'0' ;
        for(int i=0;i<l-5;)
        {
            for(;a[i]==0;i++) ;
            int n=10*a[i]+a[i+1] ;
            if(n>=17)
            {
                n=n%17 ;
                a[i]=n/10 ;
                a[i+1]=n%10 ;
            }
            else
            {
                n=100*a[i]+10*a[i+1]+a[i+2] ;
                n=n%17 ;
                a[i]=0 ; a[i+1]=n/10 ; a[i+2]=n%10 ;
            }
        }
        int k,now=0 ;
        for(k=0;k<l && a[k]==0;k++) ;
        for(int i=k;i<l;i++)
        {
            now*=10 ;
            now+=a[i] ;
        }
        printf("%d\n",now%17?0:1) ;
    }
}
