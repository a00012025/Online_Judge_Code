#include<bits/stdc++.h>
using namespace std;
char s[100010] ;
int cnt[27] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d%s",&n,s) ;
        memset(cnt,0,sizeof(cnt)) ;
        int M=0 ;
        for(int i=0;i<n;i++) M=max(M,++cnt[s[i]-'a']) ;
        for(int i=0;i<26;i++) if(cnt[i]==M) printf("%c",i+'a') ;
        printf("\n");
    }
}
