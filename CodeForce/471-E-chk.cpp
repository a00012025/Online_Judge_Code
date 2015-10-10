#include<bits/stdc++.h>
using namespace std;

FILE *f,*g ;
char c ;
main()
{
    int a,b ;
    f=fopen("out1","r") ;
    fscanf(f,"%d",&a) ;
    f=fopen("out2","r") ;
    fscanf(f,"%d",&b) ;
    if(a!=b)
    {
        printf("ERROR\n") ;
        g=fopen("in","r") ;
        while((c=fgetc(g))!=EOF) printf("%c",c) ;
    }
}
