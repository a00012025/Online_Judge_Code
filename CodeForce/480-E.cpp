#include<bits/stdc++.h>
using namespace std;
const int maxn=2000+5 ;

struct P{int x,y;}p[maxn];

int n,m,a[maxn][maxn] ;
int ans[maxn] ;
char G[maxn][maxn] ;
set<int> st[maxn] ;
multiset<int,greater<int> > stl ;
multiset<int> str ;
int L[maxn],R[maxn] ;
bool check(int x,int y,int k)
{
    int up=max(0,x-k+1) , dn=min(n-1,x+k-1) ;
    for(int i=up;i<=dn;i++)
    {
        auto it=st[i].lower_bound(y) ;
        if(*it==y){L[i]=y+1 ; R[i]=y ; continue ;}
        R[i]=*it-1 ;
        it-- ; L[i]=*it+1 ;
    }
    stl.clear() ; str.clear() ;
    for(int i=up;i<=dn;i++)
    {
        if(i>=up+k)
            stl.erase(stl.find(L[i-k])) ,
            str.erase(str.find(R[i-k])) ;
        stl.insert(L[i]) ;
        str.insert(R[i]) ;
        if(i>=up+k-1 && *str.begin()-*stl.begin() >= k-1)
            return 1 ;
    }
    return 0 ;
}

main()
{
    int k ; scanf("%d%d%d",&n,&m,&k) ;
    for(int i=0;i<n;i++) scanf("%s",G[i]) ;
    for(int i=1;i<=k;i++)
        scanf("%d%d",&p[i].x,&p[i].y) ,
        p[i].x-- , p[i].y-- ,
        G[p[i].x][p[i].y]='X' ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
    {
        if(G[i][j]=='X') {st[i].insert(j) ; continue ;}
        if(!i || !j) a[i][j]=1 ;
        else a[i][j]=min(min(a[i-1][j],a[i][j-1]),a[i-1][j-1])+1 ;
        ans[k]=max(ans[k],a[i][j]) ;
    }
    for(int i=0;i<n;i++) st[i].insert(-1) , st[i].insert(m) ;

    for(int i=k-1;i>=1;i--)
    {
        int x=p[i+1].x , y=p[i+1].y ;
        st[x].erase(y) ;
        ans[i]=ans[i+1] ;
        while(check(x,y,ans[i]+1)) ans[i]++ ;
    }
    for(int i=1;i<=k;i++) printf("%d\n",ans[i]) ;
}
