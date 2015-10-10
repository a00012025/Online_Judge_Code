#include<stdio.h>
#include<algorithm>
using namespace std;
int n,a[5001],b[5001];
int st1[5001],st2[5001],st3[5001] ;

bool solve()
{
    int top1,top2,top3 ;
    for(int i=1;i<=n;i++)
    {
        top1=top2=top3=0 ;
        for(int j=i+1;j<=n;j++)
        {
            if(a[j]<a[i]) st2[top2++]=j ;
            else
            {
                if(!top1 || a[j]>a[st1[top1-1]]) st1[top1++]=j ;
                while(top3 && a[j]<a[st3[top3-1]]) top3-- ;
                st3[top3++]=j ;
            }
        }
        if(!top1 || !top2 || !top3) continue ;
        for(int j=0;j<top1;j++)
        {
            int id1=st1[j] ;
            int id2=lower_bound(st2,st2+top2,id1)-st2 ;
            if(id2==top2) break ;
            int id3=lower_bound(st3,st3+top3,st2[id2])-st3 ;
            if(id3==top3) break ;
            if(a[id1]>a[st3[id3]]) return 1;
        }
    }
    return 0;
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        if(solve()) printf("YES\n") ;
        else
        {
            for(int i=1;i<=n;i++) a[i]=-a[i] ;
            if(solve()) printf("YES\n") ;
            else printf("NO\n") ;
        }
    }
}
