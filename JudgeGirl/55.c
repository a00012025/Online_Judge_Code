#include<stdio.h>
int dx[2][2]={{1,0},{0,1}},dy[2][2]={{0,1},{1,0}} ;
int n,m,x[2],y[2],f[2],t[2][2],s[2] ;
main()
{
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d",&m,&n,x,y,t[0]+1,t[0],f,x+1,y+1,t[1],t[1]+1,f+1) ;
    for(int i=0;i<2;i++) for(int j=0;j<2;j++) s[i]+=t[i][j] ;
    for(int i=1;i<=f[0]||i<=f[1];i++)
    {
        for(int j=0;j<2;j++) if(i<=f[j])
        {
            int id=((i-1)%s[j]<t[j][0]) ;
            x[j]=(x[j]+dx[j][id])%m ; y[j]=(y[j]+dy[j][id])%n ;
        }
        if(x[0]==x[1]&&y[0]==y[1]){printf("robots explode at time %d\n",i) ; return 0 ;}
    }
    puts("robots will not explode") ;
}
