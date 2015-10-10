#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1000001] ;
main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        sort(a+1,a+1+n) ;
        bool fir=true ;
        if(n%2) printf("A=%d",a[(n+1)/2]) ;
        else for(int i=a[n/2] ; i<=a[(n/2)+1] ; i++)
        {
            if(fir) {fir=false ; printf("A=") ;}
            else printf("¡B") ;
            printf("%d",i) ;
        }
        printf("\n") ;
    }
}
