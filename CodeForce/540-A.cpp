#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+10 ;

int f(int x,int y)
{
    if(x>y) swap(x,y) ;
    return min(y-x,x-y+10) ;
}
char s[maxn],t[maxn] ;
main()
{
    int n,ans=0 ; scanf("%d%s%s",&n,s+1,t+1) ;
    for(int i=1;i<=n;i++) ans+=f(s[i]-'0',t[i]-'0') ;
    printf("%d\n",ans) ;
}
