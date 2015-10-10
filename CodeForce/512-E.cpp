#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+10 ;
struct P{int x,y;};

bool b[maxn][maxn] ;
int n ;
P change(int x,int y)
{
    int x2=-1,y2 ;
    for(int i=1;i<=n;i++) if(b[i][x]&&b[i][y])
    {
        if(x2==-1) x2=i ;
        else {y2=i ; break ;}
    }
    b[x][y]=b[y][x]=0 ;
    b[x2][y2]=b[y2][x2]=1 ;
    return (P){x2,y2} ;
}

void solve(const vector<P> &p,vector<P> &ret,bool inv)
{
    memset(b,0,sizeof(b)) ;
    vector<P> tmp ;
    for(int i=1;i<=n;i++) b[i][i%n+1]=b[i%n+1][i]=1 ;
    for(auto i : p) b[i.x][i.y]=b[i.y][i.x]=1 ;
    for(int i=2;i<n;)
    {
        if(b[1][i+1]) {i++ ; continue ;}
        int j ;
        for(j=i+1;!b[1][j];j++) ;
        P np=change(i,j) ;
        tmp.push_back(inv ? np : (P){i,j}) ;
    }
    if(inv) reverse(tmp.begin(),tmp.end()) ;
    for(auto i : tmp) ret.push_back(i) ;
}

vector<P> p,q,ans ;
main()
{
    scanf("%d",&n) ;
    for(int i=1;i<=n-3;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        p.push_back((P){x,y}) ;
    }
    for(int i=1;i<=n-3;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        q.push_back((P){x,y}) ;
    }
    solve(p,ans,0) ; solve(q,ans,1) ;
    printf("%d\n",ans.size()) ;
    for(auto i : ans) printf("%d %d\n",i.x,i.y) ;
}
