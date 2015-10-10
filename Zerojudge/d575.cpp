#include<stdio.h>
int abs(int a) 
    {
    if(a>=0) return a;
    return -a ;
    }
main()
{
 int a,b,c,d;
 int A,B,n;
 while(scanf("%d %d %d %d %d",&a,&b,&c,&d,&n)==5)
 {
 A=abs(a-c);
 B=abs(b-d);
 if(n-A<B) printf("alive\n");
 else printf("die\n");
 }
}
