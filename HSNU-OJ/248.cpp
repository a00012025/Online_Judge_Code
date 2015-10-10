#include<bits/stdc++.h>
using namespace std;
const int maxn=500000 ;
int ch[maxn][26],cnt=0 ;
int ID(char c)
{
    return c-'a' ;
}

bool val[maxn] ;
void trie_insert(char *t)
{
    int now=0 , len=strlen(t) ;
    for(int i=0;i<len;i++)
    {
        int c=ID(t[i]) ;
        if(!ch[now][c])
        {
            cnt++ ; memset(ch[cnt],0,sizeof(ch[cnt])) ;
            ch[now][c]=cnt ;
        }
        now=ch[now][c] ;
    }
    val[now]=1 ;
}

void dfs_trie(int x,char c)
{
    printf("%c\n",c) ;
    if(val[x]) printf("P\n") ;
    for(int i=0;i<26;i++) if(ch[x][i]) dfs_trie(ch[x][i],i+'a') ;
    printf("-\n") ;
}

void solve(char *t)
{
    int len=strlen(t) ;
    int now=0 ;
    for(int i=0;i<len;i++)
    {
        int c=ID(t[i]) ;
        for(int j=0;j<26;j++) if(ch[now][j] && j!=c) dfs_trie(ch[now][j],j+'a') ;
        printf("%c\n",t[i]) ;
        now=ch[now][c] ;
        if(val[now]) printf("P\n") ;
    }
}

int n ;
main()
{
    int maxlen=0 , tot=0 ; ;
    char s[30],t[30] ;
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s) ;
        trie_insert(s) ;
        int len=strlen(s) ;
        if(len>maxlen)
        {
            maxlen=len ;
            for(int j=0;j<=len;j++) t[j]=s[j] ;
        }
    }
    printf("%d\n",2*cnt-maxlen+n) ;
    solve(t) ;
}
