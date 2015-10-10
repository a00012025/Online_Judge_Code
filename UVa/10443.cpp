#include<stdio.h>
#include<string.h>
char c[2][110][110],s[110] ;
main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int a,b,n;
        scanf("%d %d %d",&a,&b,&n) ;
        memset(c,0,sizeof(c)) ;
        for(int i=1;i<=a;i++)
        {
            gets(s) ;
            while(strlen(s)<b) gets(s) ;
            for(int j=0;j<b;j++) c[0][i][j+1]=s[j] ;
        }
        for(int i=1;i<=n;i++) for(int j=1;j<=a;j++) for(int k=1;k<=b;k++)
        {
            if(c[(i+1)%2][j][k]=='R')
            {
                if(c[(i+1)%2][j][k-1]=='P' || c[(i+1)%2][j][k+1]=='P')
                    c[i%2][j][k]='P' ;
           else if(c[(i+1)%2][j-1][k]=='P' || c[(i+1)%2][j+1][k]=='P')
                    c[i%2][j][k]='P' ;
                else c[i%2][j][k]='R' ;
            }
            if(c[(i+1)%2][j][k]=='S')
            {
                if(c[(i+1)%2][j][k-1]=='R' || c[(i+1)%2][j][k+1]=='R')
                    c[i%2][j][k]='R' ;
           else if(c[(i+1)%2][j-1][k]=='R' || c[(i+1)%2][j+1][k]=='R')
                    c[i%2][j][k]='R' ;
                else c[i%2][j][k]='S' ;
            }
            if(c[(i+1)%2][j][k]=='P')
            {
                if(c[(i+1)%2][j][k-1]=='S' || c[(i+1)%2][j][k+1]=='S')
                    c[i%2][j][k]='S' ;
           else if(c[(i+1)%2][j-1][k]=='S' || c[(i+1)%2][j+1][k]=='S')
                    c[i%2][j][k]='S' ;
                else c[i%2][j][k]='P' ;
            }
        }
        for(int i=1;i<=a;i++)
        {
            for(int j=1;j<=b;j++) printf("%c",c[n%2][i][j]) ;
            printf("\n") ;
        }
        if(T) printf("\n") ;
    }
}
