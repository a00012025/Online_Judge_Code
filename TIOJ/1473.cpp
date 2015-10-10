#include<bits/stdc++.h>
#define MOD 10007
using namespace std;
const int maxn=100+10 ;

int ch[maxn*15][4] , len[maxn*15] , ccnt=1 ;
bool val[maxn*15] ;
void insert(char *t)
{
    int l=strlen(t) , now=0 ;
    for(int i=0;i<l;i++)
    {
        int c=t[i]-'a' ;
        if(!ch[now][c])
        {
            memset(ch[ccnt],0,sizeof(ch[ccnt])) ;
            ch[now][c]=ccnt ;
            len[ccnt]=len[now]+1 ;
            ccnt++ ;
        }
        now=ch[now][c] ;
    }
    val[now]=1 ;
}

int fail[maxn*15] ;
void get_fail()
{
    queue<int> q ;
    for(int i=0;i<4;i++) if(ch[0][i])
        fail[ch[0][i]]=0 , q.push(ch[0][i]) ;
    while(!q.empty())
    {
        int u=q.front() ; q.pop() ;
        for(int i=0;i<4;i++)
        {
            int v=ch[u][i] ;
            if(!v) { ch[u][i]=ch[fail[u]][i] ; continue ; }
            q.push(v) ;
            fail[v]=ch[fail[u]][i] ;
            if(val[fail[v]]) val[v]=1 ;
        }
    }
}

inline void up(int &x,int y)
{
    x=(x+y)%MOD ;
}

int n,dp[2][maxn][maxn*15] ;
char s[maxn] ;

void DP()
{
    int st=0 , L=strlen(s) ;
    for(int i=0;i<L;i++)
    {
        st=ch[st][s[i]-'a'] ;
        if(val[st]) { printf("0 1\n") ; return ; }
    }
    dp[1][L][st]=1 ;
    int ans1=0 , ans2=0 ;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<maxn;j++) for(int k=0;k<ccnt;k++)
            dp[(i+1)%2][j][k]=0 ;
        for(int j=1;j<maxn;j++) for(int k=0;k<ccnt;k++)
            if(dp[i%2][j][k])
        {
            int add=dp[i%2][j][k] ;
            for(int z=0;z<4;z++)
                up(dp[(i+1)%2][j+1][ch[k][z]],add) ;
            if(j==1) { up(ans1,add) ; continue ; }
            if(j==len[k]) up(dp[(i+1)%2][j-1][fail[k]],add) ;
            else up(dp[(i+1)%2][j-1][k],add) ;
        }
        for(int j=1;j<maxn;j++) for(int k=0;k<ccnt;k++)
            if(val[k])
            up(ans2,dp[(i+1)%2][j][k]) ,
            dp[(i+1)%2][j][k]=0 ;
    }
    printf("%d %d\n",ans1,ans2) ;
}

char t[maxn] ;
main()
{
    int k ;
    scanf("%s%d%d",s,&n,&k) ;
    while(k--) scanf("%s",t) , insert(t) ;
    get_fail() ;
    DP() ;
}
