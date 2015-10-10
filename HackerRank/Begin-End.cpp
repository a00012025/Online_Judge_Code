#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1000000+10 ;

char s[maxn] ;
int num[26] ;
int main()
{
    int n ; scanf("%d%s",&n,s) ;
    LL ans=0LL ;
    for(int i=0;i<n;i++) num[s[i]-'a']++ ;
    for(int i=0;i<26;i++) ans+=(LL)num[i]*(num[i]+1)/2 ;
    printf("%lld\n",ans) ;
}
