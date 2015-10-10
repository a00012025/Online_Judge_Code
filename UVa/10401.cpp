#include<stdio.h>
#include<string.h>
#define LL long long
LL ans[20][20] ;

int id(char c)
{
    if(c>='1' && c<='9') return c-'0' ;
    else if(c>='A' && c<='F') return c-'A'+10 ;
    else if(c=='?') return 0 ;
    else return -1 ;
}

main()
{
    char s[100] ;
    int G[20] ;
    while(scanf("%s",s)!=EOF)
    {
        int n=0 ;
        for(int i=0;i<strlen(s) && id(s[i])!=-1;i++,n++)
            G[i+1] = id(s[i]) ;
        for(int j=n;j>=1;j--)
        {
            LL sum=0 ;
            if(j<n) for(int i=1;i<=n;i++) sum+=ans[i][j+1] ;
            for(int i=1;i<=n;i++)
            {
                if(j==n && !G[j]) ans[i][j]=1LL ;
                else if(j==n) ans[i][j] = (i==G[j] ? 1LL : 0LL) ;
                else if(G[j] && i!=G[j]) ans[i][j]=0LL ;
                else
                {
                    ans[i][j]=sum-ans[i][j+1] ;
                    if(i!=1) ans[i][j]-=ans[i-1][j+1] ;
                    if(i!=n) ans[i][j]-=ans[i+1][j+1] ;
                }
            }
        }
        LL ANS=0 ;
        for(int i=1;i<=n;i++) ANS+=ans[i][1] ;
        printf("%lld\n",ANS) ;
    }
}
