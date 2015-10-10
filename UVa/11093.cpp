#include<stdio.h>
#define LL long long
LL a[100001],b[100001],f[100001] ;
main()
{
    int T,tc=0;
    scanf("%d",&T) ;
    while(T--)
    {
        LL s1=0LL,s2=0LL ;
        int n;
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++) {scanf("%lld",&a[i]) ; s1+=a[i] ;}
        for(int i=1;i<=n;i++) {scanf("%lld",&b[i]) ; s2+=b[i] ;}
        if(s1<s2) {printf("Case %d: Not possible\n",++tc) ; continue ;}
        f[1]=0 ;
        LL m=0 ; int id=1 ;
        for(int i=2;i<=n;i++)
        {
            f[i]=f[i-1]+a[i-1]-b[i-1] ;
            if(f[i]<m) m = f[ id=i ] ;
        }
        printf("Case %d: Possible from station %d\n",++tc,id) ;
    }
}
