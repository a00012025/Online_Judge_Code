#include<stdio.h>
#include<algorithm>
using namespace std;
int a[17],b[17] ;

void ducci(int n)
{
    b[n]=abs(a[1]-a[n]) ;
    for(int i=1;i<n;i++) b[i]=abs(a[i]-a[i+1]) ;
    for(int i=1;i<=n;i++) a[i]=b[i] ;
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int n;
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        for(int i=1;i<=1001;i++) ducci(n) ;
        bool zero=1 ;
        for(int i=1;i<=n;i++) if(a[i]) zero=0 ;
        if(zero) printf("ZERO\n") ;
        else printf("LOOP\n") ;
    }
}
