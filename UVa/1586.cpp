#include<stdio.h>
#include<string.h>
double C=12.01 , H=1.008 , O=16.00 , N=14.01 ;
main()
{
    int n;
    char s[1000] ;
    scanf("%d",&n) ;
    while(n--)
    {
        scanf("%s",s) ; int num=0 ;
        char c;
        double ans=0.0 ;
        for(int i=0;i<=strlen(s);i++)
        {
            if((s[i]>'9' || s[i]<'0') && i)
            {
                if(s[i-1]>='A' && s[i-1]<='Z') {num=1 ; c=s[i-1];}
                if(c=='C') ans+=C*num ;
                else if(c=='H') ans+=H*num ;
                else if(c=='O') ans+=O*num ;
                else if(c=='N') ans+=N*num ;
                num=0 ;
            }
            if(s[i]>='A' && s[i]<='Z') c=s[i] ;
            else if(s[i]>='0' && s[i]<='9')
            {
                num*=10 ;
                num+=s[i]-'0' ;
            }
        }
        printf("%.3lf\n",ans) ;
    }
}
