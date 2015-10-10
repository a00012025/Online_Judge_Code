#include<bits/stdc++.h>
using namespace std;
const int maxn=500+10 ;

int G[maxn][maxn],n,m ;
int cal(int x)
{
    int ret=0 ;
    for(int i=1,j=0;i<=m;i++)
        if(G[x][i]==1) j++ , ret=max(ret,j) ;
        else j=0 ;
    return ret ;
}

multiset<int,greater<int> > st ;
int val[maxn] ;
main()
{
    int Q ; scanf("%d%d%d",&n,&m,&Q) ;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) scanf("%d",&G[i][j]) ;
        st.insert(val[i]=cal(i)) ;
    }
    while(Q--)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        st.erase(st.find(val[x])) ;
        G[x][y]^=1 ;
        st.insert(val[x]=cal(x)) ;
        printf("%d\n",*st.begin()) ;
    }
}
