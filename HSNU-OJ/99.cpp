#include<bits/stdc++.h>
using namespace std;
struct P{int from,to;};
vector<P> edge ;
vector<int> v[100001] ;
bool vis[1000001] ;
int euler[2000001],cnt=0 ;
int id[100001] ;

void dfs(int x)
{
    while(id[x]<v[x].size() && vis[v[x][id[x]]]) id[x]++ ;
    for(int i=id[x];i<v[x].size();i=id[x]) if(!vis[v[x][i]])
    {
        vis[v[x][i]]=1 ; while(id[x]<v[x].size() && vis[v[x][id[x]]]) id[x]++ ;
        if(x==edge[v[x][i]].from) dfs(edge[v[x][i]].to) ;
        else dfs(edge[v[x][i]].from) ;
    }
    euler[cnt++]=x ;
}

vector<int> ans[1000001] ;
bool inst[100001] ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    while(m--)
    {
        int x,y,t1,t2 ; scanf("%d%d%d%d",&x,&y,&t1,&t2) ;
        if(t1^t2)
        {
            edge.push_back((P){x,y}) ;
            int t=edge.size() ;
            v[x].push_back(t-1) ;
            v[y].push_back(t-1) ;
        }
    }

    for(int i=1;i<=n;i++) if(v[i].size()%2) { printf("NIE\n") ; return 0 ; }

    memset(vis,0,sizeof(vis)) ;
    memset(id,0,sizeof(id)) ;
    for(int i=1;i<=n;i++)
    {
        bool done=1 ;
        for(int j=0;j<v[i].size();j++) if(!vis[v[i][j]]) { done=0 ; break ; }
        if(!done) dfs(i) ;
    }

    stack<int> st ; memset(inst,0,sizeof(inst)) ;
    int acnt=0 ;
    for(int i=0;i<cnt;i++)
    {
        if(inst[euler[i]])
        {
            int t=euler[i] ; ans[acnt].push_back(t) ;
            while(1)
            {
                int e=st.top() ; st.pop() ; inst[e]=0 ;
                ans[acnt].push_back(e) ;
                if(e==t) break ;
            }
            st.push(t) , inst[t]=1 ;
            acnt++ ;
        }
        else st.push(euler[i]) , inst[euler[i]]=1 ;
    }
    printf("%d\n",acnt) ;
    for(int i=0;i<acnt;i++)
    {
        printf("%d",((int)ans[i].size())-1) ;
        for(int j=0;j<ans[i].size();j++) printf(" %d",ans[i][j]) ;
        printf("\n") ;
    }
}
