#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char s[1001][1000],c[1001] ;
bool ans[1001] ;
main()
{
    int T,tc=0;
    scanf("%d",&T) ;
    while(T--)
    {
        int n,m ; tc++ ;
        memset(ans,0,sizeof(ans)) ;
        memset(s,0,sizeof(s)) ;
        scanf("%d %d",&n,&m) ;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",c) ;
            if(strlen(c)>=3) sort(c+1,c+strlen(c)-1) ;
            for(int j=0;j<strlen(c);j++) s[i][j]=c[j] ;
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%s",c) ;
            if(strlen(c)>=3) sort(c+1,c+strlen(c)-1) ;
            int swe=0 ;
            for(int j=1;j<=n;j++)
            {
                if(strlen(s[j])!=strlen(c)) continue ;
                int yes=0 ;
                for(int k=0;k<strlen(c);k++)
                    if(s[j][k]!=c[k]) {yes=1 ; break ;}
                if(!yes) {swe=1 ; break ;}
            }
            if(swe) ans[i]=1 ;
            else ans[i]=0 ;
        }
        printf("Case #%d: ",tc) ;
        for(int i=1;i<=m;i++)printf("%d",ans[i]) ;
        printf("\n") ;
    }
}
