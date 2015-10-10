#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct P {int l,r;};
bool comp(P x,P y)
{
    if(x.l != y.l) return x.l<y.l ;
    else return x.r<y.r ;
}
P seg[200001] ;
vector<P> ans ;
int n,M ;

bool solve()
{
    ans.clear() ;
    int now=0 ;
    for(int i=0;i<n;)
    {
        while(i<n && seg[i].r<now) i++ ;
        if(i==n) break ;
        if(seg[i].l > now) return 0;
        int maxnum=-1 , id , j  ;
        for(j=i;j<n && seg[j].l<=now;j++)
            if(seg[j].r > maxnum) maxnum=seg[ id=j ].r ;
        ans.push_back((P){seg[id].l,seg[id].r}) ;
        now=seg[id].r ;
        if(seg[id].r>=M) break ;
        i=j ;
    }
    if(now<M) return 0;
    else return 1;
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d",&M) ;
        n=0 ;
        while(1)
        {
            scanf("%d%d",&seg[n].l,&seg[n].r) ;
            if(seg[n].l==0 && seg[n].r==0) break ;
            n++ ;
        }
        sort(seg,seg+n,comp) ;
        if(!solve()) printf("0\n") ;
        else
        {
            printf("%d\n",ans.size()) ;
            for(int i=0;i<ans.size();i++)
                printf("%d %d\n",ans[i].l,ans[i].r) ;
        }
        printf("\n") ;
    }
}
