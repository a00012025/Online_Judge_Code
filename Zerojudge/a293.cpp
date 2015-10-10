#include<stdio.h>
int f(int a,int b)
{
    if(a==1 && b==1) return 1;
    if(a==8 && b==1) return 2;
    if(a==1 && b==8) return 7;
    if(a==8 && b==8) return 5;
}
main()
{
    int p,a[26] ;
    scanf("%d",&p) ;
    for(int i=1;i<=25;i++) scanf("%d",&a[i]) ;
    for(int i=1;i<p;i++)
    {
        int ans=0 ;
        for(int i=1;i<=25;i++)
        {
            int r;
            scanf("%d",&r) ;
            ans+=f(a[i],r) ;
            a[i]=r ;
        }
        printf("%d\n",ans) ;
    }
}
