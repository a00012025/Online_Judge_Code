#include<stdio.h>
main()
{
    int n,num=0;
    bool vis[200]={0} ;
    scanf("%d",&n) ;
    int a,b ;
    scanf("%d",&a) ;
    for(int i=1;i<=a;i++)
    {
        int k;
        scanf("%d",&k) ;
        if(vis[k]==0){vis[k]=1 ; num++ ;}
    }
    scanf("%d",&b) ;
    for(int i=1;i<=b;i++)
    {
        int k;
        scanf("%d",&k) ;
        if(vis[k]==0){vis[k]=1 ; num++ ;}
    }
    if(num<n) printf("Oh, my keyboard!\n") ;
    else printf("I become the guy.\n");
}
