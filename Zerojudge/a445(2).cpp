#include<stdio.h>
#include<string.h>

main()
{
int N,x,y,a,b,g[10001],p,q,i,j;
 while(scanf("%d %d %d",&N,&x,&y)==3)
 {
 memset(g,0,sizeof(g));
 for(i=1;i<=x;i++)
    {
    scanf("%d %d",&a,&b);
    if((g[a]==0)&&(g[b]==0))
        {
        g[a]=b;
        g[b]=b;
        }
    else if((g[a]==0)&&(g[b]!=0)) g[a]=b;
    else if((g[b]==0)&&(g[a]!=0)) g[b]=a;
    else if((g[a]!=0)&&(g[b]!=0)) 
        {
        while(a!=g[a]) a=g[a];
        while(b!=g[b]) b=g[b];
        g[a]=b;
        }
    }
 for(i=1;i<=N;i++)
    {
    if(g[i]==0) g[i]=i;
    }
 for(i=1;i<=y;i++)
    {
    scanf("%d %d",&a,&b);
    while(a!=g[a]) a=g[a];
    while(b!=g[b]) b=g[b];
    if(a!=b) printf(":(\n");
    else printf(":)\n");
    }
}}
