#include<stdio.h>
#include<stack>
#define LL long long
using namespace std;
typedef struct {int val,time ;}P ;
int a[1001001] ;
main()
{
    int n,T ;
    scanf("%d",&T);
    while(T--)
    {
        stack<P> s ;
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        while(!s.empty()) s.pop() ;
        LL ans=0 ;
        for(int i=1;i<=n;i++)
        {
            int add=0,same=0 ;
            while((!s.empty()) && (s.top().val<=a[i]))
            {
                if(s.top().val==a[i]) same+=s.top().time ;
                add+=s.top().time ;
                s.pop() ;
            }
            if(s.empty()) ans+=((LL)2)*add ;
            else ans+=((LL)2)*add+2 ;
            if(same) s.push((P){a[i],same+1}) ;
            else s.push((P){a[i],1}) ;
        }
        printf("%lld\n",ans/2) ;
    }
}
