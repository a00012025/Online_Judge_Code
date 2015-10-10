#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const int maxstate=10000000,M=1000000,p[16]={1,5,14,37,79,161,338,731,1529,3579,8014,16659,35691,80019,168938,356947} ;
struct State
{
    int a[16] ;
};
State state[maxstate],goal ;

int next[maxstate],head[M],dis[maxstate],fr,rear,dx[]={1,-1,0,0},dy[]={0,0,1,-1} ;

int h(State st)
{
    int ret=0 ;
    for(int i=0;i<16;i++) ret += (st.a[i])*p[i] ;
    return ret%M ;
}

void init()
{
    for(int i=0;i<16;i++) scanf("%d",&state[1].a[i]) ;
    memset(next,0,sizeof(next)) ;
    memset(head,0,sizeof(head)) ;
}

bool try_to_insert(int n)
{
    int k=h(state[n]) ;
    for(int j=head[k];j!=0;j=next[j]) if(memcmp(&state[j],&state[n],sizeof(state[n]))==0) return 0;
    next[rear]=head[k] ;
    head[k]=rear ;
        //for(int i=0;i<16;i++) printf("%2d%c",state[n].a[i],i%4==3?'\n':' ') ;
        //system("pause") ;
    return 1;
}

int bfs()
{
    fr=1 , rear=2 ;
    dis[1]=0 ;
    while(fr<rear)
    {
        State u=state[fr] ;
        if(memcmp(&u,&goal,sizeof(u))==0) return dis[fr] ;
        for(int z=0;z<16;z++) if(!u.a[z])
        {
            int x=z/4 , y=z%4 ;
            for(int k=0;k<4;k++)
            {
                State& v=state[rear] ;
                memcpy(&v,&u,sizeof(u)) ;
                int nx=x+dx[k] , ny=y+dy[k] ;
                if(nx<0 || nx>3 || ny<0 || ny>3) continue ;
                int nz=nx*4+ny ;
                v.a[z]=v.a[nz] ; v.a[nz]=0 ;
                if(try_to_insert(rear)) {dis[rear]=dis[fr]+1 ; rear++ ;}
            }
            break ;
        }
        fr++ ;
        if(rear%100000==0) printf("%d\n",dis[rear-1]) ;
    }
    return -1;
}

main()
{
    int T;
    scanf("%d",&T) ;
    goal=(State){1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0} ;
    while(T--)
    {
        init() ;
        int ans=bfs() ;
        if(ans==-1) printf("This puzzle is not solvable.\n") ;
        else printf("%d\n",ans) ;
    }
}
