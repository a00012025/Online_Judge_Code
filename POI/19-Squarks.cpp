#include<bits/stdc++.h>
using namespace std;
const int maxn=50000+10 ;

multiset<int> s0,s ;
int a[maxn],n,m ;
vector<int> tmp ;
vector< vector<int> > ans ;

void solve(int x,int y,int z)
{
    if((x+y+z)%2) return ;
    if(x+y<=z || y+z<=x || z+x<=y) return ;
    tmp[0]=(x+y-z)/2 , tmp[1]=(x-y+z)/2 , tmp[2]=(-x+y+z)/2 ;
    s=s0 ;
    s.erase(s.find(x)) ;
    s.erase(s.find(y)) ;
    s.erase(s.find(z)) ;
    int cnt=3 ;
    while(!s.empty())
    {
        int u=(*s.begin()) ; s.erase(s.begin()) ;
        if(u<=tmp[0]) return ;
        for(int i=1;i<cnt;i++)
        {
            multiset<int>::iterator it=s.find(u-tmp[0]+tmp[i]) ;
            if(it==s.end()) return ;
            s.erase(it) ;
        }
        tmp[cnt++]=u-tmp[0] ;
    }
    ans.push_back(tmp) ;
}

main()
{
    scanf("%d",&n) ; m=n*(n-1)/2 ;
    for(int i=1;i<=m;i++)
        scanf("%d",&a[i]) , s0.insert(a[i]) ;
    sort(a+1,a+m+1) ;
    tmp.resize(n) ;
    for(int i=3;i<=n;i++) if(i==3 || a[i]!=a[i-1])
        solve(a[1],a[2],a[i]) ;

    printf("%d\n",ans.size()) ;
    for(int i=0;i<ans.size();i++) for(int j=0;j<n;j++)
        printf("%d%c",ans[i][j],j==n-1?'\n':' ') ;
}
