#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10,maxc=3000 ;

int ch[maxc][26],ccnt ;
bool have[maxc] ;
void insert(char *t)
{
    int now=0 ;
    for(int i=0;t[i];i++)
    {
        int c=t[i]-'a' ;
        if(!ch[now][c])
        {
            ccnt++ ; memset(ch[ccnt],0,sizeof(ch[ccnt])) ;
            ch[now][c]=ccnt ;
        }
        now=ch[now][c] ;
    }
    have[now]=1 ;
}

int n ;
char s[maxn],t[maxn] ;
bool ok[maxn][maxn] ;
bool dp[maxc][maxn] ;
vector<int> ri[maxn] ;
bool process()
{
    for(int i=1;i<=n;i++)
    {
        ri[i].clear() ;
        for(int j=i;j<=n;j++) if(ok[i][j])
            ri[i].push_back(j) ;
    }
    bool ret=0 ;
    for(int i=1;i<=n;i++)
    {
        memset(dp,0,sizeof(dp)) ;
        dp[0][i-1]=1 ;
        for(int j=0;j<=ccnt;j++) for(int k=i-1;k<n;k++) if(dp[j][k])
        {
            int c=s[k+1]-'a' ;
            if(ch[j][c]) dp[ch[j][c]][k+1]=1 ;
            for(auto it : ri[k+1]) dp[j][it]=1 ;
        }
        for(int j=1;j<=ccnt;j++) if(have[j])
            for(int k=i;k<=n;k++) if(dp[j][k] && !ok[i][k])
                {ok[i][k]=1 ; ret=1 ;}
    }
    return ret ;
}

int dp2[maxn] ;
void solve(int m)
{
    memset(have,0,sizeof(have)) ;
    memset(ok,0,sizeof(ok)) ;
    memset(dp,0,sizeof(dp)) ;
    ccnt=0 ; memset(ch[0],0,sizeof(ch[0])) ;

    scanf("%s",s+1) ; n=strlen(s+1) ;
    while(m--) scanf("%s",t) , insert(t) ;
    while(process()) ;
    memset(dp2,0,sizeof(dp2)) ;
    for(int i=1;i<=n;i++)
    {
        dp2[i]=max(dp2[i],dp2[i-1]) ;
        for(int j=i;j<=n;j++) if(ok[i][j])
            dp2[j]=max(dp2[j],dp2[i-1]+(j-i+1)) ;
    }
    printf("%d\n",n-dp2[n]) ;
}

main()
{
    int m ;
    while(scanf("%d",&m)==1 && m) solve(m) ;
}
