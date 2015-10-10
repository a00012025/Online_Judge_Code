#include<stdio.h>
#include<string.h>
#include<set>
#include<vector>
using namespace std;
struct State {int a[9];}st[200000];
set<int> s ;
vector<int> ans ;
int fr,rear ;
int fa[200000],type[200000],dis[200000],dx[]={1,-1,0,0},dy[]={0,0,1,-1} ;
char t[]={'D','U','R','L'} ;

bool try_to_insert(int n)
{
    State u=st[n] ;
    int val=0 ;
    for(int i=0;i<9;i++) {val*=10 ; val+=u.a[i] ;}
    if(s.count(val)) return 0;
    s.insert(val) ; return 1;
}

void bfs()
{
    fr=1 ; rear=2 ; dis[1]=0 ;
    while(fr<rear)
    {
        State u=st[fr] ;
        for(int z=0;z<9;z++) if(!u.a[z])
        {
            int x=z/3,y=z%3 ;
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i] , ny=y+dy[i] ;
                if(nx<0||nx>2||ny<0||ny>2) continue ;
                int nz=nx*3+ny ;
                State& v=st[rear] ;
                memcpy(&v,&u,sizeof(v)) ;
                dis[rear]=dis[fr]+1 ;
                v.a[z]=v.a[nz] ; v.a[nz]=0 ;
                if(try_to_insert(rear)) {fa[rear]=fr ; type[rear]=i ; rear++ ;}
            }
            break ;
        }
        fr++ ;
    }
}

main()
{
    int T,tc=0;
    scanf("%d",&T) ;
    while(T--)
    {
        printf("Puzzle #%d\n",++tc) ;
        for(int i=0;i<9;i++) scanf("%d",&st[1].a[i]) ;
        s.clear() ;
        bfs() ;
        for(int i=0;i<9;i++) printf("%d%c",st[fr-1].a[i],i%3==2?'\n':' ') ;
        int j=fr-1 ;
        ans.clear() ;
        while(j!=1)
        {
            ans.push_back(type[j]) ;
            j=fa[j] ;
        }
        for(int i=ans.size()-1;i>=0;i--) printf("%c",t[ans[i]]) ;
        printf("\n") ;
        if(T) printf("\n") ;
    }
}
