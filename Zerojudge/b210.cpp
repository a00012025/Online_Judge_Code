#include<bits/stdc++.h>
using namespace std;
struct P {int ed,dis;};
vector<P> v[30001] ;
int d[30001] ;
main()
{
    int n,m ;
    while(scanf("%d%d",&n,&m)==2 && n+m)
    {
        for(int i=0;i<=n;i++) v[i].clear() ;
        while(m--)
        {
            int x,y,z ; scanf("%d%d%d",&x,&y,&z) ;
            if(x>y) swap(x,y) ;
            v[y].push_back((P){x,z}) ;
        }
        memset(d,0,sizeof(d)) ;
        for(int i=1;i<n;i++)
        {
            d[i]=d[i-1] ;
            for(int j=0;j<v[i].size();j++)
                d[i]=max(d[i],d[v[i][j].ed]+v[i][j].dis) ;
        }
        printf("%d\n",d[n-1]) ;
    }
}
