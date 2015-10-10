#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10 ;

vector<int> v[maxn],v2[maxn] ;
int lev[maxn] ;
int bcnt ;
stack<int> st ;
vector<int> bcc[maxn] ;
int dfs(int x,int f,int l)
{
    int low ; lev[x]=low=l ;
    st.push(x) ;
    for(auto i : v[x]) if(i!=f)
    {
        if(lev[i]!=-1){low=min(low,lev[i]) ; continue ;}
        int t=dfs(i,x,l+1) ; low=min(low,t) ;
        if(t>=l)
        {
            bcnt++ ;
            while(1)
            {
                int top=st.top() ; st.pop() ;
                bcc[bcnt].push_back(top) ;
                if(top==i) break ;
            }
            bcc[bcnt].push_back(x) ;
        }
    }
    return low ;
}

int fa[maxn] ;
void dfs2(int x,int f)
{
    fa[x]=f ;
    for(auto i : v2[x]) if(i!=f) dfs2(i,x) ;
}

main()
{
    int n,m,A,B,C ;
    while(scanf("%d%d%d%d%d",&n,&m,&A,&B,&C)!=EOF)
    {
        for(int i=0;i<=2*n;i++) v[i].clear() , bcc[i].clear() , v2[i].clear() ;
        while(!st.empty()) st.pop() ;
        bcnt=0 ;

        while(m--)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            v[x].push_back(y) ;
            v[y].push_back(x) ;
        }
        fill(lev+1,lev+n+1,-1) ;
        dfs(A,A,0) ;
        if(lev[C]==-1){printf("NO\n") ; continue ;}
        for(int i=1;i<=bcnt;i++) for(auto j : bcc[i])
            v2[i+n].push_back(j) ,
            v2[j].push_back(i+n) ;
        dfs2(A,A) ;
        bool ok=0 ;
        for(int i=B;;i=fa[i])
        {
            if(i<=n)
            {
                if(i==A) break ;
                else continue ;
            }
            for(auto j : bcc[i-n]) if(j==C){ok=1 ; break ;}
        }
        printf("%s\n",ok?"YES":"NO") ;
    }
}
