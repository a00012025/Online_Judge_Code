#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10 ;

char s[maxn] ;
int now[27] ;
main()
{
    int n ; scanf("%d%s",&n,s+1) ;
    int ans=0 ;
    for(int i=1;i<=2*n-2;i+=2)
    {
        now[s[i]-'a']++ ;
        if(!now[s[i+1]-'A']) ans++ ;
        else now[s[i+1]-'A']-- ;
    }
    printf("%d\n",ans) ;
}
