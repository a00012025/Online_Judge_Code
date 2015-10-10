#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

char s[30] ;
int d[30][30] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        memset(d,0,sizeof(d)) ;
        for(int i=0;i<26;i++) for(int j=0;j<26;j++) d[i][j]=-INF ;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s) ;
            int len=strlen(s) ;
            for(int j=0;j<26;j++) d[j][s[len-1]-'a']=max(d[j][s[len-1]-'a'],d[j][s[0]-'a']+len) ;
            d[s[0]-'a'][s[len-1]-'a']=max(d[s[0]-'a'][s[len-1]-'a'],len) ;
        }
        int ans=0 ;
        for(int i=0;i<26;i++) ans=max(ans,d[i][i]) ;
        printf("%d\n",ans) ;
    }
}
