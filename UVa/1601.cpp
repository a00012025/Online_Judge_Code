#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<set>
#include<vector>
using namespace std;
struct P
{
    int a[3];
    bool operator < (const P &rhs) const
    {
        for(int i=0;i<3;i++) if(a[i]!=rhs.a[i]) return a[i]<rhs.a[i] ;
        return 0;
    }
} st,ed,state[8000000];

int m,n,num ;
bool ok(P x,P y)
{
    for(int i=0;i<3;i++) for(int j=i+1;j<3;j++)
        if(y.a[i]==y.a[j] && y.a[i]!=-1) return 0;
    if(num>=2 && x.a[0]==y.a[1] && x.a[1]==y.a[0]) return 0;
    if(num==3 && x.a[0]==y.a[2] && x.a[2]==y.a[0]) return 0;
    if(num==3 && x.a[1]==y.a[2] && x.a[2]==y.a[1]) return 0;
    return 1;
}

char G[20][20] ;
vector<int> v[1000] ;
set<P> s ;
int dis[8000000],dx[]={1,-1,0,0},dy[]={0,0,1,-1} ;
main()
{
    while(scanf("%d%d%d",&m,&n,&num)==3 && m+n+num)
    {
        gets(G[0]) ;
        for(int i=0;i<n;i++) gets(G[i]) ;
        for(int i=0;i<=n*m;i++) v[i].clear() ;
        st=(P){-1,-1,-1} ; ed=(P){-1,-1,-1} ;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(G[i][j]!='#')
        {
            if(G[i][j]>='a' && G[i][j]<='c') st.a[G[i][j]-'a']=i*m+j ;
            if(G[i][j]>='A' && G[i][j]<='C') ed.a[G[i][j]-'A']=i*m+j ;
            v[i*m+j].push_back(i*m+j) ;
            for(int k=0;k<4;k++)
            {
                int nx=i+dx[k] , ny=j+dy[k] ;
                if(G[nx][ny]!='#') v[i*m+j].push_back(nx*m+ny) ;
            }
        }
        int fr=1,rear=2 ;
        s.clear() ; s.insert(st) ; state[1]=st ; dis[1]=0 ;
        while(fr<rear)
        {
            P u=state[fr] ;
                //printf("%2d : %2d,%2d,%2d\n",fr,u.a[0],u.a[1],u.a[2]) ;
                //system("pause") ;
            if(memcmp(&u,&ed,sizeof(u))==0) {printf("%d\n",dis[fr]) ; break ;}
            for(int i=0;i<v[u.a[0]].size();i++)
            {
                if(u.a[1]!=-1) for(int j=0;j<v[u.a[1]].size();j++)
                {
                    if(u.a[2]!=-1) for(int k=0;k<v[u.a[2]].size();k++)
                    {
                        P& t=state[rear] ;
                        t.a[0]=v[u.a[0]][i] ; t.a[1]=v[u.a[1]][j] ; t.a[2]=v[u.a[2]][k] ;
                        if(ok(u,t) && !s.count(t))
                        {
                            s.insert(t) ;
                            dis[rear]=dis[fr]+1 ;
                            rear++ ;
                        }
                    }
                    else
                    {
                        P& t=state[rear] ;
                        t.a[0]=v[u.a[0]][i] ; t.a[1]=v[u.a[1]][j] ; t.a[2]=-1 ;
                        if(ok(u,t) && !s.count(t))
                        {
                            //printf("%2d,%2d,%2d\n",t.a[0],t.a[1],t.a[2]) ;
                            //system("pause") ;
                            s.insert(t) ;
                            dis[rear]=dis[fr]+1 ;
                            rear++ ;
                        }
                    }
                }
                else
                {
                    P& t=state[rear] ;
                    t.a[0]=v[u.a[0]][i] ; t.a[1]=-1 ; t.a[2]=-1 ;
                    if(ok(u,t) && !s.count(t))
                    {
                        s.insert(t) ;
                        dis[rear]=dis[fr]+1 ;
                        rear++ ;
                    }
                }
            }
            fr++ ;
            //if(fr%100000==0) printf("%d\n",fr) ;
        }
    }
}
