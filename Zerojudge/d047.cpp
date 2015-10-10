#include<stdio.h>
#include<string.h>
bool an(int n)
{
    if((n%400)==0) return true ;
    else if((n%100)==0) return false ;
    else if((n%4)==0) return true ;
    else return false ;
}
bool hu(char* a,int l)
{
    int n=0 ;
    for(int i=0;i<l;i++) n+=a[i]-'0' ;
    if((n%3==0) && ((a[l-1]-'0')%5==0)) return true ;
    return false ;
}
bool bu(char* a,int l)
{
    int n=0,m=0 ;
    for(int i=0;i<l;i=i+2) n+=a[i]-'0' ;
    for(int i=1;i<l;i=i+2) m+=a[i]-'0' ;
    if(((n-m)%11==0) && ((a[l-1]-'0')%5==0)) return true ;
    return false ;
}
main()
{
    char s[100000] ;
    bool fir=1 ;
    while(scanf("%s",s)!=EOF)
    {
        if(fir) fir=0 ;
        else printf("\n") ;
        int l=strlen(s) ;
        int n=1000*(s[l-4]-'0')+100*(s[l-3]-'0')+10*(s[l-2]-'0')+(s[l-1]-'0') ;
        int x=an(n),y=hu(s,l),z=(bu(s,l))&&(an(n)) ;
        if((!x) && (!y) && (!z))
            printf("This is an ordinary year.\n") ;
        else
        {
            if(x) printf("This is leap year.\n") ;
            if(y) printf("This is huluculu festival year.\n") ;
            if(z) printf("This is bulukulu festival year.\n") ;
        }
    }
}
