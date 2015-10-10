#include<stdio.h>
main()
{
    int n,cnt=0;
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        int a,b ;
        scanf("%d %d",&a,&b) ;
        if(b-a>=2) cnt++ ;
    }
    printf("%d\n",cnt) ;
}
