#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

vector<int> v ;
int a[maxn] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        v.clear() ;
        int n,m ; scanf("%d%d",&n,&m) ;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]) ;

        for(int i=2;i<=n+1;i++)
            if(i==n+1 || a[i]!=a[i-1]) v.push_back(i-1) ;
        while(m--)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            int id1=lower_bound(v.begin(),v.end(),x)-v.begin() ;
            int id2=lower_bound(v.begin(),v.end(),y)-v.begin() ;
            if(id1==id2) printf("Y") ;
            else printf("N") ;
        }
        printf("\n") ;
    }
}
