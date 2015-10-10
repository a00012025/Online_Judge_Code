#include<stdio.h>
int a[200001],b[200001],Z[200001],L,R,len ;
int s[400101],n,w ;

int solve()
{
    if(w==1) return n ;
    if(w>n) return 0 ;
    L=0 ; R=0 ;
    for(int i=1;i<len;i++)
    {
        if(i>R)
        {
            L=i; R=i ;
            for(;R<len && s[R]==s[R-L];R++);
            Z[i]=R-L ; R-- ;
        }
        else if(Z[i-L]<R-i+1) Z[i]=Z[i-L] ;
        else
        {
            L=i ; for(R=R+1;R<len && s[R]==s[R-L];R++) ;
            Z[i]=R-L ;
            R-- ;
        }
            //printf("i,L,R : %d,%d,%d\n",i,L,R) ;
    }
    int ans=0 ;
    for(int i=1;i<len;i++) if(Z[i]==w-1) ans++ ;
    return ans ;
}

main()
{
    scanf("%d %d",&n,&w) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    for(int i=1;i<=w;i++) scanf("%d",&b[i]) ;
    for(int i=0;i<w-1;i++) s[i]=b[i+1]-b[i+2] ;
    s[w-1]=1000000000 ;
    for(int i=0;i<n-1;i++) s[i+w]=a[i+1]-a[i+2] ;
    len=n+w-1 ;
    printf("%d\n",solve()) ;
    //for(int i=1;i<len;i++) printf("%d,",Z[i]) ;
    //printf("\n") ;
}
