#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct P {int l,r,id;};
bool cmp(P x,P y)
{
    if(x.l != y.l) return x.l<y.l ;
    else if(x.r != y.r) return x.r<y.r ;
    else return x.id<y.id ;
}
P segx[5001],segy[5001] ;

int n , ansx[5001] , ansy[5001] ;
bool used[5001] ;

bool solve1()
{
    memset(used,0,sizeof(used)) ;
    int now=1 ;
    for(int i=1;i<=n;i++)
    {
        for(;now<=n && segx[now].r<i;now++) if(!used[now]) return 0;
        if(now==n+1) return 0;
        int id,minnum=10000 ;
        for(int j=now;j<=n && segx[j].l<=i;j++)
            if(!used[j] && segx[j].r>=i && segx[j].r < minnum)
                minnum=segx[ id=j ].r ;
        if(minnum==10000) return 0 ;
        used[id]=1 ; ansx[segx[id].id]=i ;
    }
    return 1;
}

bool solve2()
{
    memset(used,0,sizeof(used)) ;
    int now=1 ;
    for(int i=1;i<=n;i++)
    {
        for(;now<=n && segy[now].r<i;now++) if(!used[now]) return 0;
        if(now==n+1) return 0;
        int id,minnum=10000 ;
        for(int j=now;j<=n && segy[j].l<=i;j++)
            if(!used[j] && segy[j].r>=i && segy[j].r < minnum)
                minnum=segy[ id=j ].r ;
        if(minnum==10000) return 0;
        used[id]=1 ; ansy[segy[id].id]=i ;
            //printf("used[%d]=1\n",segy[id].id);
    }
    return 1;
}

main()
{
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=1;i<=n;i++) scanf("%d%d%d%d",&segx[i].l,&segy[i].l,&segx[i].r,&segy[i].r);
        for(int i=1;i<=n;i++) segx[i].id=segy[i].id=i ;
        sort(segx+1,segx+1+n,cmp) ;
        sort(segy+1,segy+1+n,cmp) ;
        if(!solve1() || !solve2()) printf("IMPOSSIBLE\n") ;
        else for(int i=1;i<=n;i++) printf("%d %d\n",ansx[i],ansy[i]) ;
    }
}
