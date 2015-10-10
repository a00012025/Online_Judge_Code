#include<bits/stdc++.h>
using namespace std;
const int maxn=1800000 ;

int ch[maxn][26],val[maxn] ;
int ccnt=1,n ;
void insert(char *t,int y)
{
    int now=0 ;
    for(int i=0;i<n;i++)
    {
        int c=t[i]-'A' ;
        if(!ch[now][c])
        {
            memset(ch[ccnt],0,sizeof(ch[ccnt])) ;
            ch[now][c]=ccnt++ ;
        }
        now=ch[now][c] ;
    }
    val[now]|=(1<<y) ;
}

int find(char *t,int y)
{
    for(int i=0,now=0;i<n;i++)
    {
        int c=t[i]-'A' ;
        if(!ch[now][c]) return 0 ;
        if(i==n-1)
        {
            if(val[ch[now][c]]&(1<<y))
                { ch[now][c]=0 ; return 1 ; }
            else return 0 ;
        }
        else now=ch[now][c] ;
    }
}

char G[40][40],s[40] ;
int ans=0 ;

void dfs(int x,int y,int d,int type)
{
    if(d==n-1)
    {
        if(type==1) insert(s,y) ;
        else ans+=find(s,y) ;
        return ;
    }
    if(type==1)
    {
        s[d+1]=G[x][y+1] ;
        dfs(x,y+1,d+1,type) ;
        s[d+1]=G[x+1][y] ;
        dfs(x+1,y,d+1,type) ;
    }
    else
    {
        s[d+1]=G[x][y-1] ;
        dfs(x,y-1,d+1,type) ;
        s[d+1]=G[x-1][y] ;
        dfs(x-1,y,d+1,type) ;
    }
}

main()
{
    freopen("palpath.in","r",stdin) ;
    freopen("palpath.out","w",stdout) ;
    scanf("%d",&n) ;
    for(int i=0;i<n;i++) scanf("%s",G[i]) ;
    s[0]=G[0][0] ; dfs(0,0,0,1) ;
    s[0]=G[n-1][n-1] ; dfs(n-1,n-1,0,2) ;
    printf("%d\n",ans) ;
}
