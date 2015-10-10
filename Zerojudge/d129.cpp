#include<stdio.h>
#include<algorithm>
#define LL long long
using namespace std;
bool cmp(LL x,LL y)
{
    return x>y ;
}
main()
{
    LL a[10000],ans[10000]={0} ;
    a[1]=1 ; int num=1,cnt=0 ;
    while(cnt<=1500)
    {
        LL n=a[1] ;
        if(ans[cnt]==n)
        {
            pop_heap(a+1,a+num+1,cmp) ;
            num-- ;
            continue ;
        }
        ans[++cnt]=n ;
        pop_heap(a+1,a+num+1,cmp) ;
        a[num]=n*2 ; a[num+1]=n*3 ; a[num+2]=n*5 ;
        push_heap(a+1,a+num+1,cmp) ;
        push_heap(a+1,a+num+2,cmp) ;
        push_heap(a+1,a+num+3,cmp) ;
        num=num+2 ;
    }
        printf("The 1500'th ugly number is %lld.\n",ans[1500]) ;
}
