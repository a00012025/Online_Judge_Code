#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+10 ;

int G[maxn][maxn] ;
int L,n,m,ans ;
int mi[maxn] , ma[maxn] ;
map<int,int> mp ;

int solve(int x,int y)
{
    for(int i=1;i<=m;i++)
    {
        mi[i]= x==y ? G[x][i] : min(mi[i],G[y][i]) ;
        ma[i]= x==y ? G[x][i] : max(ma[i],G[y][i]) ;
    }
    int ret=0 ;
    mp.clear();
    for(int i=1,j=0;i<=m;i++)
    {
        if((y-x+1)*(m-i+1)<ans) break ;
        if(j<m && ma[j+1]>mi[j+1]+L)
        {
            i=j+1 ; j++ ;
            mp.clear() ;
            continue ;
        }
        while(j<m)
        {
            j++ ;
            if( max(mp.empty() ? ma[j] : mp.rbegin()->first,ma[j]) -
               min(mp.empty() ? mi[j] : mp.begin()->first,mi[j]) > L )
                { j-- ; break ; }
            mp[mi[j]]++ ; mp[ma[j]]++ ;
        }
        ret=max(ret,j-i+1) ;
        if(j==i-1) j++ ;
        else
        {
            auto it=mp.find(mi[i]) ;
            if(!(--it->second)) mp.erase(it) ;
            it=mp.find(ma[i]) ;
            if(!(--it->second)) mp.erase(it) ;
        }
    }
    return ret ;
}

main()
{
    scanf("%d%d%d",&n,&m,&L) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        scanf("%d",&G[i][j]) ;
    ans=0 ;
    for(int i=1;i<=n;i++) for(int j=i;j<=n;j++)
        ans=max(ans,(j-i+1)*solve(i,j)) ;
    printf("%d\n",ans) ;
}
