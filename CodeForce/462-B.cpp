#include<stdio.h>
#include<string.h>
#include<algorithm>
#define LL long long
using namespace std;

bool comp(LL x,LL y)
{
    return x>y ;
}

main()
{
    int n ; LL k,a[100]={0} ;
    char c ;
    scanf("%d %I64d",&n,&k) ;
    memset(a,0,sizeof(a)) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%c",&c) ;
        while(c<'A' || c>'Z') scanf("%c",&c) ;
        a[c-'A'+1]++ ;
    }
    sort(a+1,a+27,comp) ;
    int num=0 ;
    LL ans=0 ;
    while(k>0)
    {
        num++ ;
        if(k<=a[num]) {ans+=k*k ; k=0 ;}
        else
        {
            ans+=a[num]*a[num] ;
            k-=a[num] ;
        }
        if(num==26) break ;
    }
    printf("%I64d\n",ans) ;
}
