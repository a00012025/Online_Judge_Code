#include<bits/stdc++.h>
using namespace std;
const int maxn=10000+10 ;

char s[maxn],t[maxn] ;
int fail[maxn] ;

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int k ; scanf("%s%d",s+1,&k) ;
        int n=strlen(s+1) ;
        while(k--)
        {
            scanf("%s",t+1) ;
            int m=strlen(t+1) ;
            fail[1]=0 ;
            for(int i=2,j=0;i<=m;i++)
            {
                while(j && t[j+1]!=t[i]) j=fail[j] ;
                if(t[j+1]==t[i]) j++ ;
                fail[i]=j ;
            }
            int ans=0 ;
            for(int i=1,j=0;i<=n;i++)
            {
                while(j && t[j+1]!=s[i]) j=fail[j] ;
                if(t[j+1]==s[i]) j++ ;
                if(j==m) ans++ , j=fail[j] ;
            }
            printf("%d\n",ans) ;
        }
    }
}
