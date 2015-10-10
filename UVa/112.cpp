#include<stdio.h>
bool yes ;
char s[1000] ;
int N;

char readchar()
{
    char c;
    scanf("%c",&c) ;
    while(( (c>'9')||(c<'0') )&&(c!='(')&&(c!=')')&&(c!='-')) scanf("%c",&c) ;
    return c ;
}

int readtree(int now)
{
    int emp=0  ;
    char c=readchar() ;
    if(c==')') return 1 ;
    int n ;
    if(c!='-')
    {
        n=c-'0' ;
        while(1)
        {
            c=readchar() ;
            if(c=='(') break ;
            n*=10 ; n+=c-'0' ;
        }
    }
    else
    {
        n=0 ;
        while(1)
        {
            c=readchar() ;
            if(c=='(') break ;
            n*=10 ; n+=c-'0' ;
        }
        n=-n ;
    }
    int a=readtree(now+n) ;
    readchar() ;
        //printf("read tree %d = %d\n",now+n,a) ;
    int b=readtree(now+n) ;
    readchar() ;
        //printf("read tree %d = %d\n",now+n,b) ;
    if(a+b==2)
    {
        if(now+n==N) yes=1 ;
        //printf("now+n=%d\n",now+n) ;
    }
    return 0 ;
}

main()
{
    while(scanf("%d",&N)!=EOF)
    {
        yes=0 ;
        readchar() ;
        readtree(0) ;
        if(yes) printf("yes\n");
        else printf("no\n") ;
    }
}
// 22 (5(4(11(7()())(2()()))()) (8(13()())(4()(1()()))))
