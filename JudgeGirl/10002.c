#include<stdio.h>
main()
{
    int h,w,a ; scanf("%d%d%d",&h,&w,&a) ;
    printf("%d\n%d\n",a*(4*h+8*w-8*a),8*h+16*w-8*a) ;
}
