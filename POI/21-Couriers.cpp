#include<bits/stdc++.h>
using namespace std;
const int maxn=500000+10 ;

vector<int> v[maxn] ;
int sum[20][maxn],a[maxn] ;

bool check(int x,int l,int r)
{
    int id1=upper_bound(v[x].begin(),v[x].end(),r)-v[x].begin() ;
    int id2=lower_bound(v[x].begin(),v[x].end(),l)-v[x].begin() ;
    return ( 2*(id1-id2) > (r-l+1) ) ;
}

main()
{
    int n,Q ; scanf("%d%d",&n,&Q) ;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]) , v[a[i]].push_back(i) ;
    for(int i=0;(1<<i)<=n;i++) for(int j=1;j<=n;j++)
        sum[i][j]=sum[i][j-1]+  ( (a[j]&(1<<i)) ? 1 : 0 ) ;
    while(Q--)
    {
        int l,r ; scanf("%d%d",&l,&r) ;
        int x=0 ;
        for(int i=0;(1<<i)<=n;i++)
        {
            int num= sum[i][r]-sum[i][l-1] ;
            if(2*num > (r-l+1)) x|=(1<<i) ;
        }
        if(check(x,l,r)) printf("%d\n",x) ;
        else printf("0\n") ;
    }
}
