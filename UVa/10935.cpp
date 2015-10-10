#include<stdio.h>
#include<deque>
using namespace std;
main()
{
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        deque<int> dq ;
        for(int i=1;i<=n;i++) dq.push_back(i) ;
        printf("Discarded cards:") ;
        for(int i=1;i<n;i++)
        {
            int a=dq.front() ; dq.pop_front() ;
            printf(" %d%c",a,i==n-1?'\n':',') ;
            a=dq.front() ; dq.pop_front() ;
            dq.push_back(a) ;
        }
        if(n==1) printf("\n") ;
        printf("Remaining card: %d\n",dq.front()) ;
    }
}
