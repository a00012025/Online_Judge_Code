#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
bool comp(int x,int y)
{
    return x>y ;
}
main()
{
    int n,a[100001],b[100001]={0},num=0;
    long long ans1=0,ans2=0 ;
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    for(int i=2;i<=n;i=i+2)
    {
        if(i==2)
        {
            b[1]=max(a[1],a[2]) ;
            ans1=(long long)max(a[1],a[2]) ;
            ans2=(long long)min(a[1],a[2]) ;
            num++ ;
            continue ;
        }
        if(a[i]>b[1] && a[i-1]>b[1])
        {
            ans1+=(long long)-b[1]+a[i]+a[i-1] ;
            ans2+=(long long)b[1] ;
            pop_heap(b+1,b+num+1,comp) ;
            b[num]=a[i-1] ;
            b[num+1]=a[i] ;
            push_heap(b+1,b+num+1,comp) ;
            push_heap(b+1,b+num+2,comp) ;
            num++ ;
        }
        else
        {
            ans1+=(long long)max(a[i],a[i-1]) ;
            ans2+=(long long)min(a[i],a[i-1]) ;
            b[num+1]=max(a[i],a[i-1]) ;
            push_heap(b+1,b+num+2,comp) ;
            num++ ;
        }
    }
    if(n%2) ans1+=(long long)a[n] ;
    printf("%I64d %I64d\n",ans1,ans2) ;
}
