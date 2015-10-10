#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char s[200],t[200] ;
main()
{
    int T,tc=0;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%s%s",s,t) ;
        int a=0,b=0,c=0,d=0 ;
        for(int i=0;i<strlen(s);i++)
        {
            if(t[i]=='0' && s[i]=='1') a++ ;
            if(t[i]=='1' && s[i]=='0') b++ ;
            if(t[i]=='0' && s[i]=='?') c++ ;
            if(t[i]=='1' && s[i]=='?') d++ ;
        }
        if(a>b+d) printf("Case %d: -1\n",++tc) ;
        else printf("Case %d: %d\n",++tc,max(a,b)+c+d) ;
    }
}
