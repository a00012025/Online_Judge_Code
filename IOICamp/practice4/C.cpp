#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;
char s[maxn],t[maxn] ;
int fail[maxn] ;
main()
{
    int T ; scanf("%d",&T) ; gets(s) ;
    while(T--)
    {
        gets(s+1) ; int n=strlen(s+1) ;
        if(s[n]=='\n' || s[n]=='\r') n-- ;
        if(s[n]=='\n' || s[n]=='\r') n-- ;
        int now=0 ; fail[1]=0 ;
        for(int i=2;i<=n;i++)
        {
            while(now && s[i]!=s[now+1]) now=fail[now] ;
            if(s[i]==s[now+1]) now++ ;
            fail[i]=now ;
        }
        int ans=fail[n] ;
        while(2*ans>n) ans=fail[ans] ;
        printf("%d\n",ans) ;
    }
}
