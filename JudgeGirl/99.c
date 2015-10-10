#include<stdio.h>
int x[10][65536],y[10][65536] ;
char s[10][256] ;
int num[10][2][256],num2[10][2] ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    for(int i=0;i<n;i++)
    {
        scanf("%s",s[i]) ;
        for(int j=0;j<m;j++) for(int k=0;k<m;k++)
        {
            int id ; scanf("%d",&id) ;
            x[i][id]=j ; y[i][id]=k ;
        }
    }
    while(1)
    {
        int id,win=0 ; scanf("%d",&id) ;
        for(int j=0;j<n;j++)
        {
            int nx=x[j][id],ny=y[j][id] ;
            if((++num[j][0][nx])==m || (++num[j][1][ny])==m) win|=(1<<j) ;
            if((nx==ny) && (++num2[j][0]==m)) win|=(1<<j) ;
            if((nx+ny==m-1) && (++num2[j][1]==m)) win|=(1<<j) ;
        }
        if(win)
        {
            printf("%d",id) ;
            for(int j=0;j<n;j++) if(win|(1<<j))
                printf(" %s",s[j]) ;
            printf("\n") ;
            return 0 ;
        }
    }
}
