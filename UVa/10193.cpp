#include<stdio.h>
#include<string.h>

int gcd(int x,int y)
{
    return y==0 ? x : gcd(y,x%y) ;
}

main()
{
    int T,tc=0;
    scanf("%d",&T);
    while(T--)
    {
        char s[40],t[40] ;
        int n=0,m=0 ;
        scanf("%s %s",s,t) ;
        for(int i=0;i<strlen(s);i++)
        {
            n*=2 ;
            n+=s[i]-'0' ;
        }
        for(int i=0;i<strlen(t);i++)
        {
            m*=2 ;
            m+=t[i]-'0' ;
        }
        if(gcd(m,n)==1) printf("Pair #%d: Love is not all you need!\n",++tc) ;
        else printf("Pair #%d: All you need is love!\n",++tc) ;
    }
}
