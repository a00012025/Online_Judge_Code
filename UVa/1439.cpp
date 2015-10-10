#include<stdio.h>
#include<string.h>
#include<map>
#include<vector>
using namespace std;
map<char,int> mp ;
char ch[20] ;
bool G[20][20],have_edge[1<<15] ;
int cnt,n ;
vector<int> edge[2000] ;

int id(char c)
{
    if(mp.count(c)) return mp[c] ;
    mp[c]=n ; ch[n]=c ; //printf("ch[%d]=%c\n",n,c) ;
    n++ ; return n-1 ;
}

int dp[1<<15],fa[1<<15],col[20] ;
const int INF=1000000 ;

void update(int x,int val,int f)
{
    if(val>=dp[x]) return ;
    dp[x]=val ; fa[x]=f ;
}

main()
{
    int m ;
    while(scanf("%d",&m)!=EOF)
    {
        memset(G,0,sizeof(G)) ;
        memset(edge,0,sizeof(edge)) ;
        memset(have_edge,0,sizeof(have_edge)) ;
        for(int i=0;i<2000;i++) edge[i].clear() ;
        mp.clear() ; n=0 ;
        for(int i=1;i<=m;i++)
        {
            char s[3],a,b ;
            scanf("%s",s) ; a=s[0] ;
            scanf("%s",s) ; b=s[0] ;
            G[id(a)][id(b)]=G[id(b)][id(a)]=1 ;
            edge[100*id(a)+id(b)].push_back(i) ;// printf("edge %d pb %d\n",100*id(a)+id(b),i) ;
            edge[100*id(b)+id(a)].push_back(i) ;
        }
        for(int S=0;S<(1<<n);S++)
        {
            bool ok=0 ;
            for(int i=0;!ok && i<n;i++) if(S & (1<<i))
            for(int j=i+1;!ok && j<n;j++) if(S & (1<<j))
                if(G[i][j]) {have_edge[S]=1 ; ok=1 ;}
            //printf("set %d : %d\n",S,have_edge[S]) ;
        }
        for(int S=0;S<(1<<n);S++) dp[S]=INF ;
        dp[0]=0 ;
        for(int S=1;S<(1<<n);S++) for(int S0=S;S0;S0=(S0-1)&S)
            if(!have_edge[S0])
            update(S,dp[S-S0]+1,S-S0) ;

        //for(int S=0;S<(1<<n);S++) printf("set %d : %d\n",S,dp[S]) ;

        int cnt=0 ;
        for(int S=((1<<n)-1);S;S=fa[S])
        {
                //printf("S=%d , fa[S]=%d\n",S,fa[S]) ;
            int T=S-fa[S] ;
            for(int i=0;i<n;i++) if(T & (1<<i)) col[i]=cnt ;
            cnt++ ;
        }

        char ans1[200],ans2[200] ;
        for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(G[i][j])
        for(int k=0;k<edge[i*100+j].size();k++)
        {
            //printf("%d,%d\n",i,j) ;
            int id=edge[i*100+j][k] ;
            if(col[i]<col[j]) {ans1[id]=ch[i] ; ans2[id]=ch[j] ;}
            else {ans1[id]=ch[j] ; ans2[id]=ch[i] ;}
        }

        printf("%d\n",cnt-2) ;
        for(int i=1;i<=m;i++) printf("%c %c\n",ans1[i],ans2[i]) ;
    }
}
