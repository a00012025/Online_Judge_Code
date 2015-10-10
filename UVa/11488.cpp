#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int sz,ch[10100000][2] ;
int depth[10100000],data[10100000] ;
int edge[10100000][2] ;

int id(char c)
{
    return c-'0' ;
}

void init()
{
    sz=0 ;
    ch[0][0]=ch[0][1]=0 ;
    depth[0]=0 ; data[0]=0 ; edge[0][0]=edge[0][1]=0 ;
}

void init2(int x)
{
    ch[x][0]=ch[x][1]=0 ;
    depth[x]=0 ; data[x]=0 ; edge[x][0]=edge[x][1]=0 ;
}

void trie_insert(char *t)
{
    int len=strlen(t),now=0 ;
    for(int i=0;i<len;i++)
    {
        if(!ch[now][id(t[i])])
        {
            sz++ ; init2(sz) ;
            ch[now][id(t[i])]=sz ;
            edge[now][id(t[i])]=sz ;
            depth[sz]=depth[now]+1 ;
        }
        data[edge[now][id(t[i])]]++ ;
            //printf("%d,",edge[now][id(t[i])]) ;
        now=ch[now][id(t[i])];
    }
}

main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n) ;
        init() ;
        while(n--)
        {
            char s[300] ;
            scanf("%s",s) ;
            trie_insert(s) ;
        }
        int ans=0 ;
        for(int i=1;i<=sz;i++) ans=max(ans,depth[i]*data[i]) ;
        printf("%d\n",ans) ;/*
            for(int i=1;i<=sz;i++) printf("%d,",depth[i]);
            printf("\n");
            for(int i=1;i<=sz;i++) printf("%d,",data[i]);
            printf("\n");*/
    }
}
