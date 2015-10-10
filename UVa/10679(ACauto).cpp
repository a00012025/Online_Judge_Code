#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;
int ch[1100101][52],fail[1100101],last[1100101],sz;
vector<int> val[1100101];
bool ans[5000] ;

int id(char c)
{
    if(c>='a' && c<='z') return c-'a' ;
    else return c-'A'+26 ;
}

void init()
{
    sz=0 ;
    memset(last,0,sizeof(last));
    memset(fail,0,sizeof(fail)) ;
    val[0].clear() ;
    memset(ch[0],0,sizeof(ch[0])) ;
    memset(ans,0,sizeof(ans)) ;
}

void trie_insert(char *t,int idx)
{
    int len=strlen(t),now=0 ;
    for(int i=0;i<len;i++)
    {
        if(!ch[now][id(t[i])])
        {
            sz++ ; memset(ch[sz],0,sizeof(ch[sz])) ; val[sz].clear() ;
            ch[now][id(t[i])]=sz ;
        }
        now=ch[now][id(t[i])] ;
    }
    val[now].push_back(idx) ;
}

void getfail()
{
    queue<int> q ;
    for(int i=0;i<52;i++)
    {
        if(ch[0][i]) q.push(ch[0][i]) ;
    }
    while(!q.empty())
    {
        int u=q.front() ; q.pop() ;
        for(int i=0;i<52;i++)
        {
            int v=ch[u][i] ;
            if(!v) continue ;
            q.push(v);
            int now=fail[u] ;
            while(now && !ch[now][i]) now=fail[now] ;
            fail[v]=ch[now][i] ;
            last[v]= val[fail[v]].size()>0 ? fail[v] : last[fail[v]] ;
        }
    }
}

void found(int n)
{
    for(int i=0;i<val[n].size();i++) ans[val[n][i]]=1 ;
        //printf("found val[%d] = %d\n",n,val[n]);
    if(last[n]) found(last[n]) ;
}

void match(char *T)
{
    int len=strlen(T) ;
    int now=0 ;
    for(int i=0;i<len;i++)
    {
        while(now && !ch[now][id(T[i])]) now=fail[now] ;
        now=ch[now][id(T[i])] ;
        if(val[now].size()) found(now) ;
        else if(last[now]) found(last[now]) ;
    }
}

main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init() ;
        char s[1000100] ;
        scanf("%s",s) ;
        int Q , cnt=0 ;
        scanf("%d",&Q) ;
        while(Q--)
        {
            char t[110001] ; cnt++ ;
            scanf("%s",t) ;
            trie_insert(t,cnt) ;
        }
        getfail() ;
        match(s) ;
        for(int i=1;i<=cnt;i++) printf("%c\n",ans[i]==0 ? 'n' : 'y') ;
    }
}
