#include<stdio.h>
#include<algorithm>
using namespace std;
typedef struct{int a,b,id ;} P ;
bool comp(P x,P y)
{
    return x.a<y.a ;
}
P s[100001] ;
main()
{
    int n,m ;
    scanf("%d %d",&n,&m) ;
    for(int i=1;i<=n;i++) {scanf("%d",&s[i].a) ; s[i].id=i ;}
    for(int i=1;i<=n;i++) scanf("%d",&s[i].b) ;
    make_heap(s+1,s+n+1,comp) ;
    long long ans=0 ;
    for(int i=1;i<=m;i++)
    {
        ans+=(long long)s[1].a ;
        P tem ;
        tem.a=max(s[1].a-s[1].b,1) ;
        tem.b=s[1].b ;
        tem.id=s[1].id ;
        pop_heap(s+1,s+n+1,comp) ;
        s[n]=tem ;
        push_heap(s+1,s+n+1,comp) ;
    }
    printf("%I64d\n",ans) ;
}
