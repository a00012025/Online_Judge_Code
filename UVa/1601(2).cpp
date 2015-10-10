#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<queue>
using namespace std;
struct P{int a[3];} st,ed;

bool ok(P x,P y)
{
    for(int i=0;i<3;i++) for(int j=i+1;j<3;j++)
        if(y.a[i]==y.a[j]) return 0;
    if(x.a[0]==y.a[1] && x.a[1]==y.a[0]) return 0;
    if(x.a[0]==y.a[2] && x.a[2]==y.a[0]) return 0;
    if(x.a[1]==y.a[2] && x.a[2]==y.a[1]) return 0;
    return 1;
}

char G[20][20] ;
vector<int> v[150] ;
int dis[150][150][150],dx[]={1,-1,0,0,0},dy[]={0,0,1,-1,0} ;
int id[20][20] , id_inv[150] ;

int bfs()
{
    memset(dis,-1,sizeof(dis)) ;
    dis[st.a[0]][st.a[1]][st.a[2]]=0 ;
    queue<P> q ; q.push(st) ;
    while(!q.empty())
    {
        P u=q.front() ; q.pop() ;
        for(int i=0;i<v[u.a[0]].size();i++)
            for(int j=0;j<v[u.a[1]].size();j++)
                for(int k=0;k<v[u.a[2]].size();k++)
        {
            P t ;
            t.a[0]=v[u.a[0]][i] ;
            t.a[1]=v[u.a[1]][j] ;
            t.a[2]=v[u.a[2]][k] ;
            if(!ok(u,t) || dis[t.a[0]][t.a[1]][t.a[2]]!=-1) continue ;
            dis[t.a[0]][t.a[1]][t.a[2]]=dis[u.a[0]][u.a[1]][u.a[2]]+1 ;
            q.push(t) ;
            if(memcmp(&t,&ed,sizeof(t))==0) return dis[t.a[0]][t.a[1]][t.a[2]] ;
        }
    }
}

main()
{
        //freopen("1.txt","r",stdin) ;
        //freopen("2.txt","w",stdout) ;
    int m,n,num ;
    while(scanf("%d%d%d",&m,&n,&num)==3 && m+n+num)
    {
        fgets(G[0],20,stdin) ;
        for(int i=0;i<n;i++) fgets(G[i],20,stdin);
        for(int i=0;i<150;i++) v[i].clear() ;

        int cnt=0 ;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(G[i][j]!='#')
        {
            id[i][j]=cnt ; id_inv[cnt]=i*m+j ;
            if(G[i][j]>='a' && G[i][j]<='c') st.a[G[i][j]-'a']=cnt ;
            if(G[i][j]>='A' && G[i][j]<='C') ed.a[G[i][j]-'A']=cnt ;
            cnt++ ;
        }
        for(int z=0;z<cnt;z++) for(int k=0;k<5;k++)
        {
            int nx=(id_inv[z]/m)+dx[k] , ny=(id_inv[z]%m)+dy[k] ;
            if(G[nx][ny]!='#') v[z].push_back(id[nx][ny]) ;
        }
        if(num<=2) {st.a[2]=cnt ; ed.a[2]=cnt ; v[cnt].push_back(cnt) ; cnt++ ;}
        if(num==1) {st.a[1]=cnt ; ed.a[1]=cnt ; v[cnt].push_back(cnt) ; cnt++ ;}
        printf("%d\n",bfs()) ;
    }
}
