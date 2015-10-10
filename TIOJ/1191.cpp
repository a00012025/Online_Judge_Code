#include<bits/stdc++.h>
#define LL long long
using namespace std;
int f(int x)
{
    return x>6 ? x-1 : x ;
}
main()
{
    char s[200] ;
    while(scanf("%s",s)!=EOF && s[0]!='0')
    {
        int n=strlen(s) ; LL ans=0LL ;
        for(int i=0;i<n;i++) ans=ans*9+f(s[i]-'0') ;
        printf("%lld\n",ans) ;
    }
}
