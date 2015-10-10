#include<bits/stdc++.h>
#define pii pair<int,int>
#define MKP(x,y) make_pair(x,y)
#define F first
#define S second
#define FORSET(x,y) for(set<pii>::iterator x=(y).begin();x!=(y).end();x++)
using namespace std;

char s[200][200] ;

bool check(int col,int x,int y)
{
    for(int i=x+1;i<=y;i++) if(s[i][col]<s[i-1][col]) return 0 ;
    return 1 ;
}

set<pii> st,tmp ;
int n,m ;
int solve(int x)
{
    if(x==m+1) return 0 ;
    FORSET(it,st)
        if(!check(x,it->F,it->S)) return 1+solve(x+1) ;
    tmp.clear() ;
    FORSET(it,st)
    {
        int now=it->F , i ;
        while(now<=it->S)
        {
            for(i=now;i<=it->S && s[now][x]==s[i][x];i++) ;
            if(i!=now+1) tmp.insert(MKP(now,i-1)) ;
            now=i ;
        }
    }
    st=tmp ;
    return solve(x+1) ;
}

main()
{
    scanf("%d%d",&n,&m) ;
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1) ;
    st.insert(MKP(1,n)) ;
    printf("%d\n",solve(1)) ;
}
