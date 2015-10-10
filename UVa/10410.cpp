#include<stdio.h>
#include<vector>
using namespace std;
vector<int> v[1001] ;
int b[1001],d[1001],bid[1001],did[1001],n ;

void solve(int l,int r)
{
        //printf("solve(%d,%d)\n",l,r) ;
    if(l==r) return ;
    int k=bid[d[l+1]]+1 ;
    while(k<=n && did[b[k]]<=r && did[b[k]]>did[b[k-1]]) k++ ;
    k-- ;
    for(int i=bid[d[l+1]];i<=k;i++) v[d[l]].push_back(b[i]) ;
    for(int i=bid[d[l+1]];i<k;i++) solve(did[b[i]],did[b[i+1]]-1) ;
    solve(did[b[k]],r) ;
}

main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<=n;i++) v[i].clear() ;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&b[i]) ;
            bid[b[i]]=i ;
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&d[i]);
            did[d[i]]=i ;
        }
        solve(1,n) ;
        for(int i=1;i<=n;i++)
        {
            printf("%d:",i) ;
            for(int j=0;j<v[i].size();j++) printf(" %d",v[i][j]);
            printf("\n");
        }
    }
}
