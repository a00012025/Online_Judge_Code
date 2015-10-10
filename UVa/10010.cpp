#include<stdio.h>
#include<string.h>
char G[60][60],s[100] ;
int len,n,m;
int dx[]={1,1,0,-1,-1,-1,0,1} , dy[]={0,1,1,1,0,-1,-1,-1} ;

bool check(int x,int y,int dir)
{
    int X=x+dx[dir]*(len-1) ;
    int Y=y+dy[dir]*(len-1) ;
    if(X<1 || X>n || Y<1 || Y>m) return 0;
    for(int i=0;i<len;i++)
    {
        int nx=x+dx[dir]*i ;
        int ny=y+dy[dir]*i ;
        if(G[nx][ny]!=s[i]) return 0;
    }
    return 1;
}

bool ok(char c)
{
    if(c>='a'&&c<='z') return 1;
    if(c>='A'&&c<='Z') return 1;
    return 0;
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int k ; scanf("%d%d",&n,&m) ;
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        {
            char c ; scanf("%c",&c) ;
            while(!ok(c)) scanf("%c",&c) ;
            if(c>='A' && c<='Z') c -= 'A'-'a' ;
            G[i][j]=c ;
        }
        scanf("%d",&k) ;
        while(k--)
        {
            scanf("%s",s) ;
            len=strlen(s) ;
            for(int i=0;i<len;i++) if(s[i]>='A' && s[i]<='Z')
                s[i] -= 'A'-'a' ;
            bool ok=0 ;
            for(int i=1;i<=n && !ok;i++) for(int j=1;j<=m && !ok;j++)
                for(int dir=0;dir<8 && !ok;dir++)
                if(check(i,j,dir)) {printf("%d %d\n",i,j) ; ok=1 ;}
        }
        if(T) printf("\n") ;
    }
    return 0;
}
