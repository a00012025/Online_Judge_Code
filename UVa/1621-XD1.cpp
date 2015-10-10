#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main()
{
    freopen("1.txt","w",stdout) ;
    srand(time(NULL)) ;
    int MAX=1000,num=10000 ;
    printf("%d\n",num) ;
    for(int i=1;i<=num;i++)
        printf("%d %d %d\n",rand()%MAX+4000,rand()%MAX+4000,rand()%MAX+4000) ;
}
