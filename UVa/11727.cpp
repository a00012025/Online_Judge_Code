#include<stdio.h>
main()
{
 int a,b,c ;
 int NN=0,N ;
 while(scanf("%d",&N)==1)
    {
    NN=0 ;
    while(N--){
    scanf("%d %d %d",&a,&b,&c) ;
    NN++ ; printf("Case %d: ",NN) ;
    if(((a>b)&&(b>c)) || ((c>b)&&(b>a))) printf("%d\n",b) ;
    else if(((b>a)&&(a>c)) || ((c>a)&&(a>b))) printf("%d\n",a) ;
    else printf("%d\n",c);
    }
    }
}
