#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

int ch[maxn][26],ccnt ;
bool leaf[maxn] ;
void insert(char *t)
{
    for(int i=0,u=0;t[i];i++)
    {
        int c=t[i]-'a' ;
        if(!ch[u][c]) ch[u][c]=++ccnt ;
        u=ch[u][c] ;
    }
}

int dp1[maxn],dp2[maxn] ;
void DP(int x)
{
    if(leaf[x]){dp1[x]=0 ; dp2[x]=1 ; return ;}
    for(int i=0;i<26;i++) if(ch[x][i])
    {
        int to=ch[x][i] ;
        DP(to) ;
        if(!dp1[to]) dp1[x]=1 ;
        if(!dp2[to]) dp2[x]=1 ;
    }
}

char s[maxn] ;
main()
{
    int n,k ; scanf("%d%d",&n,&k) ;
    while(n--) scanf("%s",s) , insert(s) ;
    for(int i=1;i<=ccnt;i++)
    {
        leaf[i]=1 ;
        for(int j=0;j<26;j++) if(ch[i][j])
            {leaf[i]=0 ; break ;}
    }
    DP(0) ;
    if(!dp1[0] || (dp1[0] && !dp2[0] && k%2==0)) printf("Second\n") ;
    else printf("First\n") ;
}
