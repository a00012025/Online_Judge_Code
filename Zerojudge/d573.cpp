#include<stdio.h>
main()
{
 int n,a,b,c,p,m,i,j; 
 int s[100001]; 
 while(scanf("%d",&n)==1)
 {
 for(m=1;m<=n;m++)
    {
    scanf("%d %d",&a,&b);
    for(i=1;i<=b;i++)
        {
        scanf("%d",&c);
        s[c]=a; 
        } 
    } 
 scanf("%d",&p);
 printf("%d\n",s[p]); 
 }
}
