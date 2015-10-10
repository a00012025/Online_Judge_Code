#include<stdio.h>
int c1[10],c2[10],x=0,y=0 ;
main()
{
    char s[4],t[4] ; scanf("%s%s",s,t) ;
    int x=0,y=0 ;
    for(int i=0;i<4;i++)
    {
        if(s[i]==t[i]){x++ ; continue ;}
        c1[s[i]-'0']++ ;
        c2[t[i]-'0']++ ;
    }
    for(int i=0;i<10;i++) y+=(c1[i]>c2[i]?c2[i]:c1[i]) ;
    printf("%dA%dB\n",x,y) ;
}
