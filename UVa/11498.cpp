#include<stdio.h>
main()
{
 int N;
 while(scanf("%d",&N)==1)
 {
 if(!N)break ;
 int a,b,P,Q;
 scanf("%d %d",&P,&Q) ;
 for(int i=1;i<=N;i++)
    {
    scanf("%d %d",&a,&b) ;
    if(P==a || Q==b) printf("divisa\n") ;
    else if(a>P && b>Q) printf("NE\n") ;
    else if(a<P && b>Q) printf("NO\n");
    else if(a>P && b<Q) printf("SE\n") ;
    else printf("SO\n") ;
    }
 }
}
