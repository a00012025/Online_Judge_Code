#include<stdio.h>
#include<string.h>
int now[10],n,maxd ;

int estimate()
{
    int cnt=0 ;
    for(int i=1;i<n;i++) if(now[i+1]!=now[i]+1) cnt++ ;
    return cnt ;
}

bool iddfs(int num)
{
    if(num==maxd)
    {
        for(int i=1;i<=n;i++) if(now[i]!=i) return 0;
        return 1 ;
    }
    if(3*(maxd-num)<estimate()) return 0;
    int now2[10] ;
    for(int i=1;i<=n;i++) now2[i]=now[i] ;
    for(int i=1;i<n;i++) for(int j=i;j<n;j++) for(int k=j+1;k<=n;k++)
    {
        for(int z=1;z<=n;z++) now[z]=now2[z] ;
        for(int z=i;z<i+k-j;z++) now[z]=now2[z+j-i+1] ;
        for(int z=i+k-j;z<=k;z++) now[z]=now2[z+j-k] ;
        if(iddfs(num+1)) return 1;
    }
    for(int z=1;z<=n;z++) now[z]=now2[z] ;
    return 0;
}

main()
{
    int tc=0 ;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=1;i<=n;i++) scanf("%d",&now[i]) ;
        maxd=0 ;
        for(;;maxd++)
            if(iddfs(0)) break ;
        printf("Case %d: %d\n",++tc,maxd) ;
    }
}
