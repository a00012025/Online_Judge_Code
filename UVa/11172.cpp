#include<stdio.h>
main()
{
 int a,b;
 int N;
 while(scanf("%d",&N)==1)
 {
 if(N==0) break;
 while(N--){
    scanf("%d %d",&a,&b) ;
    if(a>b) printf(">\n") ;
    else if(a==b) printf("=\n") ;
    else printf("<\n") ;
    }
 }
}
