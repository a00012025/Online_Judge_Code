#include<bits/stdc++.h>
#define LL long long
#define mkp(x,y) make_pair(x,y)
using namespace std;
const int maxn=100000+10 ;

map< pair<LL,char>,int > mp ;
int w[27] ;
char s[maxn] ;
LL sum[maxn] ;
main()
{
    for(int i=0;i<26;i++) scanf("%d",&w[i]) ;
    scanf("%s",s+1) ;
    int n=strlen(s+1) ;
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+w[s[i]-'a'] ;
    LL ans=0LL ;
    for(int i=1;i<n;i++)
    {
        mp[mkp(sum[i],s[i])]++ ;
        ans+=mp[mkp(sum[i],s[i+1])] ;
    }
    printf("%I64d\n",ans) ;
}
