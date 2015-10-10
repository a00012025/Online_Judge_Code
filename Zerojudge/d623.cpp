#include<stdio.h>
main()
{
 int a,b,c,d,D;
 double e,f,g,h ;
 while(scanf("%d %d %d %d",&a,&b,&c,&d)==4)
    {
    if((a==0)&(b==0)&&(c==0)&&(d==0)) break;
    D=a*d-b*c;
    if(D==0)printf("cheat!\n");
    e=(double)d/D;
    f=(double)-b/D;
    g=(double)-c/D;
    h=(double)a/D;
    if(D!=0) printf("%.5lf %.5lf\n%.5lf %.5lf\n",e,f,g,h);
    }
}

//42 68 335 101
