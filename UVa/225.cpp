#include<stdio.h>
#include<set>
#include<algorithm>
#include<string.h>
#define mkp(x,y) make_pair(x,y)
using namespace std;
typedef pair<int,int> pii ;
set<pii> restrict ;
int cnt,n,nowx,nowy ;
char ans[100],ch[]={'e','n','s','w'} ;
bool vis[200][200] ;
int dx[]={1,0,0,-1} , dy[]={0,1,-1,0} ;

bool check(int x1,int y1,int x2,int y2)
{
    for(int i=x1;i<=x2;i++) for(int j=y1;j<=y2;j++)
        if(restrict.count(mkp(i,j))) return 0;
    for(int i=x2;i<=x1;i++) for(int j=y2;j<=y1;j++)
        if(restrict.count(mkp(i,j))) return 0;
    return 1;
}

bool ok(char c1,char c2)
{
    if(c1==c2) return 0 ;
    if(c1=='w' && c2=='e') return 0 ;
    if(c1=='e' && c2=='w') return 0 ;
    if(c1=='n' && c2=='s') return 0 ;
    if(c1=='s' && c2=='n') return 0 ;
    return 1 ;
}

int dis()
{
    int ret=0 ;
    ret += nowx>0 ? nowx : -nowx ;
    ret += nowy>0 ? nowy : -nowy ;
    return ret ;
}

void dfs(int num)
{
    if(num!=n && num!=0 && nowx==0 && nowy==0) return ;
    if(num==n)
    {
        if(nowx==0 && nowy==0)
        {
            cnt++ ;
            for(int i=1;i<=n;i++) printf("%c",ans[i]) ;
            printf("\n") ;
        }
        return ;
    }
    if(dis() > (n+num+1)*(n-num)/2) return ;
    for(int i=0;i<4;i++)
    {
        if(num && !ok(ans[num],ch[i])) continue ;
        int nx=nowx+dx[i]*(num+1) , tem1=nowx ;
        int ny=nowy+dy[i]*(num+1) , tem2=nowy;
        if(vis[nx+100][ny+100]) continue ;
        if(!check(nowx,nowy,nx,ny)) continue ;
        nowx=nx ; nowy=ny ; vis[nx+100][ny+100]=1 ; ans[num+1]=ch[i] ;
        dfs(num+1) ;
        nowx=tem1 ; nowy=tem2 ; vis[nx+100][ny+100]=0 ;
    }
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        restrict.clear() ;
        int m ;
        scanf("%d%d",&n,&m) ;
        while(m--)
        {
            int a,b;
            scanf("%d%d",&a,&b) ;
            restrict.insert(mkp(a,b)) ;
        }
        cnt=0 ;
        if(n%8==0 || n%8==7)
        {
            nowx=0,nowy=0 ;
            memset(vis,0,sizeof(vis)) ;
            dfs(0) ;
        }
        printf("Found %d golygon(s).\n\n",cnt) ;
    }
}
