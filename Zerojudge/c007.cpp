#include<stdio.h>
main()
{
    int c,q=1;
    while(c=getchar())
    {
        if(c==EOF) break;
        if(c!='"') printf("%c",c) ;
        else {printf("%s", q==1 ? "``" : "''") ; q=!q ;}
    }
}
