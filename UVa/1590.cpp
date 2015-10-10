#include<stdio.h>
#include<string.h>
#include<algorithm>
#define LL long long
using namespace std;

void print_ans(LL n)
{
    printf("%d.",n/(1LL<<24)) ;
    for(int i=24;i<32;i++) if(n&(1LL<<i)) n ^= (1LL<<i) ;
    printf("%d.",n/(1LL<<16)) ;
    for(int i=16;i<24;i++) if(n&(1LL<<i)) n ^= (1LL<<i) ;
    printf("%d.",n/(1LL<<8)) ;
    for(int i=8;i<16;i++) if(n&(1LL<<i)) n ^= (1LL<<i) ;
    printf("%d\n",n) ;
}

main()
{
    int n;
    LL a[2000] ;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            char s[100] ;
            scanf("%s",s) ; a[i]=0LL ;
            for(int j=0;j<strlen(s);)
            {
                int k ;
                sscanf(&s[j],"%d",&k) ;
                a[i]*=(LL)256 ; a[i]+=(LL)k ;
                while(j<strlen(s) && s[j]!='.') j++ ;
                j++ ;
            }
        }
        LL M=0 ;
        for(int i=2;i<=n;i++) M=max(M,a[1]^a[i]) ;
        int i ;
        for(i=31;i>=0 && (M&(1LL<<i))==0;i--) ;
        LL ans1=a[1] , ans2=(1LL<<32)-1 ;
        for(int j=0;j<=i;j++)
        {
            if(ans1&(1LL<<j)) ans1 ^= (1LL<<j) ;
            ans2 ^= (1LL<<j) ;
        }
        print_ans(ans1) ;
        print_ans(ans2) ;
    }
}
