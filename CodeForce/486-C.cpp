#include<bits/stdc++.h>
using namespace std;
char s[100001] ;

int dis(char c,char d)
{
    int ret=30 ;
    ret=min(ret,abs(c-d)) ;
    ret=min(ret,c-'a'+'z'-d+1) ;
    ret=min(ret,d-'a'+'z'-c+1) ;
    return ret ;
}

int n,k ;
bool need[100001] ;
int solve()
{
    int ans=0 ;
    for(int i=1;i<=(n+1)/2;i++) if(s[i]!=s[n+1-i])
        need[i]=need[n+1-i]=1 , ans+=dis(s[i],s[n+1-i]) ;
    if(!ans) return 0 ;
    if(k<(n+3)/2)
    {
        int x,y ;
        for(x=1;x<=(n+1)/2 && !need[x];x++) ;
        for(y=(n+1)/2;y>=1 && !need[y];y--) ;
        ans+=min(abs(k-x)+abs(x-y),abs(k-y)+abs(x-y)) ;
    }
    else
    {
        int x,y ;
        for(x=(n+3)/2;x<=n && !need[x];x++) ;
        for(y=n;y>=(n+3)/2 && !need[y];y--) ;
        ans+=min(abs(k-x)+abs(x-y),abs(k-y)+abs(x-y)) ;
    }
    return ans ;
}

main()
{
    scanf("%d%d%s",&n,&k,s+1) ;
    memset(need,0,sizeof(need)) ;
    printf("%d\n",solve()) ;
}
