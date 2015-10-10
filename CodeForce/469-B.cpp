#include<stdio.h>
bool inter(int a,int b,int c,int d)
{
    if(a>=c && a<=d) return 1;
    if(b>=c && b<=d) return 1;
    if(a<=c && b>=d) return 1;
    if(a==c || a==d || b==c || b==d) return 1 ;
    else return 0 ;
}
main()
{
    int p,q,l,r ;
    int a[51],b[51],c[51],d[51] ;
    scanf("%d%d%d%d",&p,&q,&l,&r) ;
    for(int i=1;i<=p;i++) scanf("%d %d",&a[i],&b[i]) ;
    for(int i=1;i<=q;i++) scanf("%d %d",&c[i],&d[i]) ;
    int ans=0 ;
    for(int x=l;x<=r;x++)
    {
        int yes=0 ;
        for(int i=1;i<=p;i++)
        {
            for(int j=1;j<=q;j++)
            {
                if(inter(a[i],b[i],c[j]+x,d[j]+x)==1) yes=1 ;
                if(yes) break ;
            }
            if(yes) break ;
        }
        if(yes==1) ans++ ;
    }
    printf("%d\n",ans) ;
}
