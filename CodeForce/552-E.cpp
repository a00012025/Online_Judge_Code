#include<bits/stdc++.h>
#define LL unsigned long long
using namespace std;
struct P{LL x,y;};
const int maxn=5000+10 ;

P pre[maxn],suf[maxn] ;
char s[maxn] ;
LL cal(int x,int y)
{
    P now=(P){0,1} ;
    for(int i=x+2;i+2<=y;i+=2)
    {
        if(s[i]=='+')
            now=(P){now.x+now.y*(s[i-1]-'0'),1} ;
        else
            now=(P){now.x,now.y*(s[i-1]-'0')} ;
    }
    LL val=now.x+now.y*(s[y-1]-'0') ;
    return val*pre[x].y*suf[y].y+pre[x].x+suf[y].x ;
}

main()
{
    scanf("%s",s+1) ;
    int n=strlen(s+1) ;
    for(int i=n+2;i>=3;i--) s[i]=s[i-2] ;
    s[1]='1' ; s[2]='*' ; s[n+3]='*' ; s[n+4]='1' ;
    n+=4 ;

    pre[0]=(P){0,1} ;
    for(int i=2;i<=n;i+=2)
    {
        if(s[i]=='+')
            pre[i]=(P){pre[i-2].x+pre[i-2].y*(s[i-1]-'0'),1} ;
        else
            pre[i]=(P){pre[i-2].x,pre[i-2].y*(s[i-1]-'0')} ;
    }

    suf[n+1]=(P){0,1} ;
    for(int i=n-1;i>=1;i-=2)
    {
        if(s[i]=='+')
            suf[i]=(P){suf[i+2].x+suf[i+2].y*(s[i+1]-'0'),1} ;
        else
            suf[i]=(P){suf[i+2].x,suf[i+2].y*(s[i+1]-'0')} ;
    }
    LL ans=0LL ;
    for(int i=2;i<=n;i+=2) for(int j=i+2;j<=n;j+=2)
        if(s[i]=='*' && s[j]=='*')
            ans=max(ans,cal(i,j)) ;
    printf("%I64u\n",ans) ;
}
