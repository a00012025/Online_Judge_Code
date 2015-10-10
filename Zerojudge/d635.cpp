#include<stdio.h>
main()
{
 int a,n;
 while(scanf("%d",&n)==1)
    {
    if(n<0)   
        {
        printf("-1\n");
        break;
        }
    if (n>=64) printf("%d%d%d\n",n/64,n/8-n/64*8,n-n/8*8);
    else if (n>=8) printf("%d%d\n",n/8-n/64*8,n-n/8*8);
    else printf("%d\n",n);
    }
}
