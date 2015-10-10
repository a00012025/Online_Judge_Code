#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

int ch[maxn][26],lev[maxn],val[maxn] ;
int ccnt=0 ;
void insert(char *t)
{
    int n=strlen(t) ;
    int now=0 ;
    for(int i=0;i<n;i++)
    {
        int c=t[i]-'a' ;
        if(!ch[now][c])
        {
            ccnt++ ;
            memset(ch[ccnt],0,sizeof(ch[ccnt])) ;
            ch[now][c]=ccnt ;
            lev[ccnt]=lev[now]+1 ;
        }
        now=ch[now][c] ;
    }
    val[now]=1 ;
}

queue<int> q ;
int fail[maxn] ;
void getfail()
{
    for(int i=0;i<26;i++) if(ch[0][i])
        q.push(ch[0][i]) ;
    while(!q.empty())
    {
        int u=q.front() ; q.pop() ;
        for(int i=0;i<26;i++)
        {
            int v=ch[u][i] ;
            if(!v) { ch[u][i]=ch[fail[u]][i] ; continue ; }
            fail[v]=ch[fail[u]][i] ;
            q.push(v) ;
        }
    }
}

char s[maxn],t[maxn] ;
char ans[maxn] ;
int pos[maxn] ;
main()
{
    if(fopen("censor.in","r"))
    {
        freopen("censor.in","r",stdin) ;
        freopen("censor.out","w",stdout) ;
    }
    int n,m ; scanf("%s%d",s+1,&m) ;
    n=strlen(s+1) ;
    while(m--) scanf("%s",t) , insert(t) ;
    getfail() ;
    int cnt=0 ;
    for(int i=1;i<=n;i++)
    {
        pos[cnt+1]=ch[pos[cnt]][s[i]-'a'] ;
        cnt++ ; ans[cnt]=s[i] ;
        if(val[pos[cnt]]) cnt-=lev[pos[cnt]] ;
    }
    ans[cnt+1]=0 ; printf("%s\n",ans+1) ;
}
