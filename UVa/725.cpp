#include<stdio.h>
#include<string.h>
bool vis[11] ;
bool ok(int x,int y)
{
    memset(vis,0,sizeof(vis)) ;
    for(int i=0;i<=4 || x!=0;i++)
    {
        if(vis[x%10]) return 0;
        vis[x%10]=1 ;
        x/=10 ;
    }
    for(int i=0;i<=4 || y!=0;i++)
    {
        if(vis[y%10]) return 0;
        vis[y%10]=1 ;
        y/=10 ;
    }
    return 1;
}

main()
{
    int n,fir=1;
    while(scanf("%d",&n)==1 && n)
    {
        if(fir) fir=0 ;
        else printf("\n") ;
        bool found=0 ;
        for(int i=1;i<100000;i++)
            if(ok(i*n,i)) {found=1 ; printf("%05d / %05d = %d\n",i*n,i,n) ;}
        if(!found) printf("There are no solutions for %d.\n",n) ;
    }
}
