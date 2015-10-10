#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10 ;

void print(const vector<int> &u)
{
    printf("%d",u.size()) ;
    for(auto i : u) printf(" %d",i) ;
    printf("\n") ;
}

vector<int> v[maxn] ;
int fa[maxn] ;
int lev[maxn] ;
int up[maxn],dn[maxn] ;
int A,B,C,D ; /// back edge : B->A & D->C

bool dfs(int x,int l)
{
    lev[x]=l ;
    for(auto i : v[x]) if(i!=fa[x])
    {
        if(lev[i]==-1)
        {
            fa[i]=x ;
            if(dfs(i,l+1)) return 1 ;
        }
        else if(lev[i]>lev[x]) continue ;
        else for(int j=x;j!=i;j=fa[j])
        {
            if(up[j])
            {
                A=up[j] ; B=dn[j] ;
                C=i ; D=x ;
                return 1 ;
            }
            up[j]=i ; dn[j]=x ;
        }
    }
    return 0 ;
}

int LCA(int x,int y)
{
    while(lev[x]<lev[y]) y=fa[y] ;
    while(lev[x]>lev[y]) x=fa[x] ;
    while(x!=y) x=fa[x] , y=fa[y] ;
    return x ;
}

vector<int> tmp ;
void getpath(int x,int y,vector<int> &ret)
{
    tmp.clear() ;
    if(x==y) tmp.push_back(x) ;
    else if(lev[x]>lev[y])
        for(int i=x;;i=fa[i])
    {
        tmp.push_back(i) ;
        if(i==y) break ;
    }
    else for(int i=y;;i=fa[i])
    {
        tmp.push_back(i) ;
        if(i==x)
        {
            reverse(tmp.begin(),tmp.end()) ;
            break ;
        }
    }
    for(auto i : tmp) ret.push_back(i) ;
}

vector<int> ans ;
bool solve(int x)
{
    fa[x]=-1 ;
    if(dfs(x,1))
    {
        printf("YES\n") ;
        int st=LCA(B,D) , ed= (lev[C]>lev[A] ? C : A) ;
        getpath(st,ed,ans) ;
        print(ans) ; ans.clear() ;
        getpath(st,B,ans) ;
        getpath(A,ed,ans) ;
        print(ans) ; ans.clear() ;
        getpath(st,D,ans) ;
        getpath(C,ed,ans) ;
        print(ans) ; return 1 ;
    }
    return 0 ;
}

main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    while(m--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }
    memset(lev,-1,sizeof(lev)) ;
    for(int i=1;i<=n;i++) if(lev[i]==-1 && solve(i))
        return 0 ;
    printf("NO\n") ;
}
