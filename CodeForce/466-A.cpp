#include<stdio.h>
main()
{
 int n,m,a,b;
 while(scanf("%d%d%d%d",&n,&m,&a,&b)==4){
 if((!n)||(!m)||(!a)||(!b)) break;
 if((a*m)>b)
    {
    if((((n/m)+1)*b)>((n/m)*b)+((n%m)*a))
        printf("%d\n",((n/m)*b)+((n%m)*a)) ;
    else 
        printf("%d\n",((n/m)+1)*b) ;
    }
 else printf("%d\n",n*a) ;
}
}
