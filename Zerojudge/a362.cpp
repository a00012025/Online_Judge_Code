#include<stdio.h>
#include<algorithm>
using namespace std;
struct P{
    int id;
    int h;
    int w;
    }s[10001];
bool comp(struct P a,struct P b)
{
    if(a.h!=b.h) return a.h<b.h ;
    if(a.w!=b.w) return a.w<b.w ;
    return a.id<b.id ;
}
main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++)
        {
                scanf("%d %d",&s[i].h,&s[i].w) ; s[i].id=i ;
        }
        sort(&s[1],&s[n+1],comp) ;
        int ans=0 ;
        for(int i=1;i<=n;i++)
        {
            if(s[i].id>=i) ans+=s[i].id-i ;
            else ans+=i-s[i].id ;
        }
        printf("%d\n",ans) ;

    }
}
