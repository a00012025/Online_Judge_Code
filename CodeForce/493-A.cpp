#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10 ;

char s[2][maxn] ;
int num[2][maxn] ;
main()
{
    scanf("%s%s",s[0],s[1]) ;
    int n ; scanf("%d",&n) ;
    while(n--)
    {
        int t,x ; char c[3] ;
        scanf("%d%s%d%s",&t,c,&x,c+1) ;
        int team=(c[0]=='h' ? 0 : 1) ;
        if(num[team][x]>=2) continue ;
        num[team][x]+=(c[1]=='y'?1:2) ;
        if(num[team][x]>=2)printf("%s %d %d\n",s[team],x,t) ;
    }
}
