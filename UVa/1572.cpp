#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
bool G[60][60] ;
vector<int> v1[60],v2[60] ;
int out[60] ;
int id(char a,char b)
{
    if(b=='+') return a-'A' ;
    else return 26+a-'A' ;
}
void add_edge(char a,char b,char c,char d)
{
    int x=id(a,b) , y=id(c,d) ;
    if(!G[x][y])
    {
        G[x][y]=1 ;
        v1[x].push_back(y) ;
        v2[y].push_back(x) ;
        out[x]++ ;
    }
}
void make_edge(char *s)
{
    for(int i=0;i<=6;i+=2) for(int j=0;j<=6;j+=2)
        if(i!=j && s[i]!='0' && s[j]!='0')
            add_edge(s[i],'+'+'-'-s[i+1],s[j],s[j+1]) ;
}
main()
{
    int n;
    char s[100] ;
    while(scanf("%d",&n)!=EOF)
    {
        memset(G,0,sizeof(G)) ;
        memset(out,0,sizeof(out)) ;
        for(int i=0;i<60;i++) {v1[i].clear() ; v2[i].clear() ;}
        while(n--) {scanf("%s",s) ; make_edge(s) ;}
        queue<int> q ; int cnt=52 ;
        for(int i=0;i<52;i++) if(!out[i]) q.push(i) ;
        while(!q.empty())
        {
            int u=q.front() ; q.pop() ; cnt-- ;
            for(int i=0;i<v2[u].size();i++)
            {
                out[v2[u][i]]-- ;
                if(!out[v2[u][i]]) q.push(v2[u][i]) ;
            }
        }
        if(cnt) printf("unbounded\n") ;
        else printf("bounded\n") ;
    }
}
