#include<stdio.h>
#include<string.h>
int xx,yy,zz;
int weight[103],cost[103];
int memory[103][10003];
int max(int x,int y)
{
 zz=x>y?x:y ; 
}
int f(int n,int w)
    {
    if ((n==0)||(w==0)) return 0 ;
    if(w-weight[n-1]<0) return memory[n][w]=f(n-1,w);
    if(memory[n][w]) return memory[n][w] ;
    return memory[n][w]=max(f(n-1,w-weight[n-1])+cost[n-1],f(n-1,w));
    }
main()
{
 int N,M,i,xxx;
 while(scanf("%d",&N)==1)
    {
    memset(memory,0,sizeof(memory));
    memory[0][0]=0;
    for(i=0;i<N;i++) scanf("%d %d",&weight[i],&cost[i]) ;
    scanf("%d",&M);
    xxx=f(N,M);
    printf("%d\n",xxx);
    }
}
