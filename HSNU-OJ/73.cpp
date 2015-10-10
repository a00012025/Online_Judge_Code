#include<bits/stdc++.h>
using namespace std;
struct P{int x,y ;}a[50001];
bool cmp(const P &a,const P &b)
{
    if(a.x!=b.x) return a.x<b.x ;
    else return a.y<b.y ;
}
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y) ;
    sort(a+1,a+n+1,cmp) ;
    int L=a[1].x , R=a[1].y , ans=1 ;
    for(int i=2;i<=n;i++)
    {
        if(a[i].x>R)
        {
            printf("%d %d\n",L,R) ;
            L=a[i].x , R=a[i].y ;
        }
        else R=max(R,a[i].y) ;
    }
    printf("%d %d\n",L,R) ;
}
