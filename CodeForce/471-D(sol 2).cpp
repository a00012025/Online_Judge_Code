#include<stdio.h>
#define FOR(i,m,n) for(int i=m;i<=n;i++)
int a[201001],b[201001],fail[201001]={0},n,w,ans ;
main()
{

    scanf("%d %d",&n,&w) ;
    FOR(i,1,n) scanf("%d",&a[i]) ;
    FOR(i,1,w) scanf("%d",&b[i]) ;
    FOR(i,1,n-1) a[i]=a[i]-a[i+1] ;
    FOR(i,1,w-1) b[i]=b[i]-b[i+1] ;
    n-- ; w-- ;
    if(w==0) printf("%d\n",n+1) ;
    else if(w>n) printf("0\n") ;
    else
    {
        int j=0 ;
        FOR(i,2,w)
        {
            while(j && b[i]!=b[j+1]) j=fail[j] ;
            if(b[i]==b[j+1]) j++ ;
            fail[i]=j ;
        }
        j=0 ; ans=0 ;
        FOR(i,1,n)
        {
            while(j && a[i]!=b[j+1]) j=fail[j] ;
            if(a[i]==b[j+1]) j++ ;
            if(j==w){ans++ ; j=fail[j] ;}
        }
        printf("%d\n",ans) ;
    }
}
