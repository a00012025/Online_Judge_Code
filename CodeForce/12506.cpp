#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
typedef struct {int id,ed ;} P ;
vector<P> v[1000101] ;
char s[1000010] ;
int ch[1000001][26] , sz , val[1000101] , ans , edge_num ;
int data[1000001] , edge[1000001][26] ;

int id(char c)
{
    return c-'a' ;
}

void clear_ch(int x)
{
    for(int i=0;i<26;i++) ch[x][i]=0 ;
}

void clear_edge(int x)
{
    for(int i=0;i<26;i++) edge[x][i]=0 ;
}

void trie_insert(char *t)
{
    int len=strlen(t) , now=0 ;
    for(int i=0;i<len;i++)
    {
        if(!ch[now][id(t[i])])
        {
            sz++ ;
            v[sz].clear() ; clear_ch(sz) ; clear_edge(sz) ;

            ch[now][id(t[i])]=sz ;
            edge_num++ ; edge[now][id(t[i])]=edge_num ;
            v[now].push_back((P){id(t[i]),sz}) ;
        }
        data[edge[now][id(t[i])]]++ ;
        now=ch[now][id(t[i])] ;
    }
    val[now]=1 ;
}

void init()
{
    sz=0 ; ans=0 ; edge_num=0 ;
    clear_ch(0) ; clear_edge(0) ;
    memset(val,0,sizeof(val)) ;
    memset(data,0,sizeof(data)) ;
    v[0].clear() ;
    int n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",s) ;
        trie_insert(s) ;
    }
}

void dfs(int n)
{
    for(int i=0;i<v[n].size();i++)
    {
        int num=data[edge[n][v[n][i].id]] ;
        ans+=num ;
        if(num>1) dfs(v[n][i].ed) ;
    }
}

main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init() ;
        dfs(0) ;
        printf("%d\n",ans) ;
    }
}
