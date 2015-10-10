#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[30],t[30] ;

void solve(int a,int b,int c,int d)
{
    if(a>b) return ;
    if(a==b) {printf("%c",s[a]) ; return ;}
    int i ;
    for(i=c;t[i]!=s[a];i++) ;
    int len=i-c ;
    solve(a+1,a+len,c,i-1) ;
    solve(a+len+1,b,i+1,d) ;
    printf("%c",s[a]) ;
}

main()
{
    while(scanf("%s %s",s,t)!=EOF)
    {
        solve(0,strlen(s)-1,0,strlen(s)-1) ;
        printf("\n") ;
    }
}
