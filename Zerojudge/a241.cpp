#include<stdio.h>
#include<algorithm>
using namespace std;
bool comp(int x,int y)
{
    return x>y ;
}
int heap[1000000],ans[2000]={0};
main()
{
    int T,n,num=1,cnt=0;
    heap[1]=1 ;
    while(cnt<=200)
    {
        int a=heap[1] ;
        if(a==ans[cnt])
        {
            pop_heap(heap+1,heap+num+1,comp) ;
            num-- ; continue ;
        }
        ans[++cnt]=a ;
        pop_heap(heap+1,heap+num+1,comp) ;
        heap[num]=2*a ; heap[num+1]=5*a ;
        push_heap(heap+1,heap+num+1,comp) ;
        push_heap(heap+1,heap+num+2,comp) ;
        num++ ;
    }
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d",&n) ;
        int l=1,r=200 ;
        while(r-l>1)
        {
            int mid=(r+l)/2 ;
            if(ans[mid]>n) r=mid ;
            else l=mid ;
        }
        printf("%d\n",l-1) ;
    }
}
