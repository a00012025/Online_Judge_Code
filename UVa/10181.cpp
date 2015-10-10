#include<stdio.h>
#include<string.h>
#include<map>
#include<queue>
#include<vector>
using namespace std;
const int maxn=10000000 ;
int g[maxn],h[maxn],fa[maxn],type[maxn],cnt ;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1} ;
char ch[]={'D','U','R','L'} ;
vector<int> ANS ;
struct P
{
    int a[16] ;
    bool operator < (const P &rhs) const
    {
        for(int i=0;i<16;i++) if(a[i]!=rhs.a[i]) return a[i]<rhs.a[i] ;
        return 0;
    }
}start,goal ;
map<P,int> mp ;
struct Q
{
    int a[16] ;
    bool operator < (const Q &rhs) const
    {
        struct P x,y ;
        for(int i=0;i<16;i++) {x.a[i]=a[i] ; y.a[i]=rhs.a[i] ;}
        int p=mp[x] , q=mp[y] ;
        return 3*g[p]+5*h[p] > 3*g[q]+5*h[q] ;
    }
};

Q ptoq(P x)
{
    Q ret ;
    for(int i=0;i<16;i++) ret.a[i]=x.a[i] ;
    return ret ;
}

P qtop(Q x)
{
    P ret ;
    for(int i=0;i<16;i++) ret.a[i]=x.a[i] ;
    return ret ;
}

bool solvable()
{
    int num=0 ;
    for(int x1=0;x1<4;x1++) for(int y1=0;y1<4;y1++)
        for(int x2=0;x2<4;x2++) for(int y2=0;y2<4;y2++)
    {
        int z1=4*x1+y1 , z2=4*x2+y2 ;
        if(z2<=z1) continue ;
        if(start.a[z2]==0){num+=x2+1 ; continue ;}
        if(start.a[z1]==0){num+=x1+1 ; continue ;}
        if(start.a[z1]>start.a[z2]) num++ ;
    }
    return 1-(num%2) ;
}

void mp_insert(P now,int dis)
{
    mp[now]=cnt ; g[cnt]=dis ;
    int ret=0 ;
    for(int i=0;i<16;i++)
    {
        int x,y ;
        for(x=0;now.a[x]!=i;x++) ;
        y= i==0 ? 15 : i-1 ;
        int x1=x/4 , y1=x%4 , x2=y/4 , y2=y%4 ;
        ret += x1>x2 ? x1-x2 : x2-x1 ;
        ret += y1>y2 ? y1-y2 : y2-y1 ;
    }
    h[cnt]=ret/2 ; cnt++ ;
}

main()
{
    priority_queue<Q> pq ;
    goal=(P){1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0} ;
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        for(int i=0;i<16;i++) scanf("%d",&start.a[i]) ;
        if(!solvable()) {printf("This puzzle is not solvable.\n") ; continue ;}
        mp.clear() ; cnt=0 ; mp_insert(start,0) ;
        while(!pq.empty()) pq.pop() ;
        pq.push(ptoq(start)) ; int ans ;
        while(!pq.empty())
        {
            Q u=pq.top() ; pq.pop() ;
            P v=qtop(u) ;
            if(memcmp(&v,&goal,sizeof(v))==0) {ans=mp[v] ; break ;}
            int z ;
            for(z=0;u.a[z];z++) ;
            int x=z/4 , y=z%4 ;
            P nu ; memcpy(&nu,&u,sizeof(u)) ;
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i] , ny=y+dy[i] ;
                if(nx<0||nx>3||ny<0||ny>3) continue ;
                int nz=4*nx+ny ;
                nu.a[z]=nu.a[nz] ; nu.a[nz]=0 ;
                if(!mp.count(nu))
                {
                    type[cnt]=i ; fa[cnt]=mp[v] ;
                    mp_insert(nu,g[mp[v]]+1) ;
                    pq.push(ptoq(nu)) ;
                }
                nu.a[nz]=nu.a[z] ; nu.a[z]=0 ;
            }
            //if(g[mp[qtop(u)]]%30==0) printf("%d\n",g[mp[qtop(u)]]) ;
            if(cnt%100000==0) printf("%d\n",cnt) ;
        }
        ANS.clear() ;
        for(int i=ans;i!=0;i=fa[i]) ANS.push_back(type[i]) ;
        for(int i=ANS.size()-1;i>=0;i--) printf("%c",ch[ANS[i]]) ;
        printf("\n") ;
    }
}
