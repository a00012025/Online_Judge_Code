#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<map>
using namespace std;
struct State {
    int a[9];
    bool operator < (const State &rhs) const
    {
        for(int i=0;i<9;i++) if(a[i]!=rhs.a[i]) return a[i]<rhs.a[i] ;
        return 0;
    }
}st[200000];
vector<int> ans ;
int fr,rear ;
int fa[200000],type[200000],dx[]={1,-1,0,0},dy[]={0,0,1,-1} ;
char t[]={'u','d','l','r'} ;
map<State,int> mp ;

void bfs()
{
    fr=1 ; rear=2 ;
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
                v.a[z]=v.a[nz] ; v.a[nz]=0 ;
                if(!mp.count(st[rear]))
                {
                    mp[st[rear]]=rear ;
                    fa[rear]=fr ;
                    type[rear]=i ;
                    rear++ ;
                }
            }
            break ;
        }
        fr++ ;
    }
}

main()
{
    int T;
    scanf("%d",&T) ;
    for(int i=0;i<8;i++) st[1].a[i]=i+1 ;
    st[1].a[8]=0 ;
    mp.clear() ; mp[st[1]]=1 ;
    bfs() ;
    while(T--)
    {
        char c[5] ;
        State S ;
        for(int i=0;i<9;i++)
        {
            scanf("%s",c) ;
            if(c[0]!='x') S.a[i]=c[0]-'0' ;
            else S.a[i]=0;
        }
        if(!mp.count(S)) printf("unsolvable\n") ;
        else
        {
            ans.clear() ;
            for(int j=mp[S];;)
            {
                if(j==1) break ;
                ans.push_back(type[j]) ;
                j=fa[j] ;
            }
            for(int i=0;i<ans.size();i++) printf("%c",t[ans[i]]) ;
            printf("\n") ;
        }
        if(T) printf("\n") ;
    }
}

