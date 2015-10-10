#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
#define INF 1000000000
using namespace std;
struct path{int x1,y1,x2,y2;};
vector<path> v[70] ;
int dx[]={1,-1,0,0} , dy[]={0,0,1,-1} ;
int n,m,num ;
char G[70][70],word[70][70] ;

bool dfs(int x,int y,int st,int ed,int k,int id)
{
    if(word[k][id+1]=='\0') {v[k].push_back((path){st,ed,x,y}) ; return 1 ;}
    bool ret=0 ;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i] , ny=y+dy[i] ;
        if(nx<0 || nx>=n || ny<0 || ny>=m || G[nx][ny]!=word[k][id+1]) continue ;
        if(dfs(nx,ny,st,ed,k,id+1)) ret=1 ;
    }
    return ret ;
}

bool found(int x)
{
    bool ret=0 ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(G[i][j]==word[x][0])
        if(dfs(i,j,i,j,x,0)) ret=1 ;
    return ret ;
}

int dis(int x1,int y1,int x2,int y2)
{
    int ret= x1>x2 ? x1-x2 : x2-x1 ;
    ret += y1>y2 ? y1-y2 : y2-y1 ;
    return ret ;
}

int dp[70][10000],len[70] ;
main()
{
    int T ;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&num) ;
        for(int i=0;i<n;i++) scanf("%s",G[i]) ;
        for(int i=1;i<=num;i++) {scanf("%s",word[i]) ; len[i]=strlen(word[i]) ; v[i].clear() ;}
        bool no=0 ;
        for(int i=1;i<=num;i++) if(!found(i))
            {no=1 ; break ;}
        if(no) {printf("Betrayal!\n") ; continue ;}
        for(int i=1;i<=num;i++) for(int j=0;j<v[i].size();j++)
            dp[i][j]= i==num ? len[num]-1 : INF  ;
        for(int i=num-1;i>=1;i--) for(int j=0;j<v[i].size();j++)
        {
            int ed1=v[i][j].x2 , ed2=v[i][j].y2 ;
            for(int k=0;k<v[i+1].size();k++)
            {
                int st1=v[i+1][k].x1 , st2=v[i+1][k].y1 ;
                dp[i][j]=min(dp[i][j],dp[i+1][k]+len[i]-1+dis(ed1,ed2,st1,st2)) ;
            }
        }
        int ans=INF ;
        for(int j=0;j<v[1].size();j++)
            ans=min(ans,dp[1][j]+dis(0,0,v[1][j].x1,v[1][j].y1)) ;
        printf("%d\n",ans+1) ;
    }
}
