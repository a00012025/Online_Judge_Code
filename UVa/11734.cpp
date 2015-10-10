#include<stdio.h>
#include<string.h>

bool ok(char c)
{
    if(c>='a' && c<='z') return 1;
    if(c>='A' && c<='Z') return 1;
    if(c==' ') return 1 ;
    return 0 ;
}

bool solve(char *s,char *t)
{
    int a=strlen(s) , b=strlen(t) ;
    int i=0 , j=0 ;
    while(i<a && j<b)
    {
        while(i<a && s[i]==' ') i++ ;
        if(i==a) break ;
        if(s[i]!=t[j]) return 0;
        i++ ; j++ ;
    }
    while(i<a && s[i]==' ') i++ ;
    if(i!=a || j!=b) return 0;
    return 1;
}

main()
{
    int T,tc=0;
    char b[1000] ;
    gets(b) ;
    sscanf(&b[0],"%d",&T);
    while(T--)
    {
        char s[10000],t[10000] ;
        gets(s) ; while(!ok(s[0])) gets(s) ;
        gets(t) ; while(!ok(t[0])) gets(t) ;
        int i ;
        for(i=0;i<strlen(s) && s[i]==t[i];i++) ;
        if(i==strlen(s) && i==strlen(t)) printf("Case %d: Yes",++tc);
        else if(solve(s,t)) printf("Case %d: Output Format Error",++tc);
        else printf("Case %d: Wrong Answer",++tc) ;
        printf("\n");
    }
}
