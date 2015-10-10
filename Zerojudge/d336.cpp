#include<stdio.h>
#include<string.h>
main()
{
 int N;
 char s[10000] ;
 scanf("%d",&N) ;
 while(N--)
 {
 gets(s) ;
 while((s[0]!='0')&&(s[0]!='1')) gets(s);
 int a=0,b=0 ;
 for(int i=0;i<strlen(s);i++)
    {
    if(i%2==0) a+=s[i]-'0' ;
    else b+=s[i]-'0' ;
    }
 if((a-b)%3==0) printf("Yes\n") ;
 else printf("No\n") ;
 }
}
