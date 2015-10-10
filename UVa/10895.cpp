#include<stdio.h>
#include<vector>
using namespace std;
struct P {int row,val ;};
vector<P> v[20101] ;
int tmp1[20101],tmp2[20101] ;
main()
{
    int n,m ;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=m;i++) v[i].clear() ;
        for(int i=1;i<=n;i++)
        {
            int k ;
            scanf("%d",&k) ;
            for(int j=1;j<=k;j++) scanf("%d",&tmp1[j]) ;
            for(int j=1;j<=k;j++) scanf("%d",&tmp2[j]) ;
            for(int j=1;j<=k;j++)
                if(tmp2[j]) v[tmp1[j]].push_back((P){i,tmp2[j]}) ;
        }
        printf("%d %d\n",m,n) ;
        for(int i=1;i<=m;i++)
        {
            printf("%d",v[i].size()) ;
            for(int j=0;j<v[i].size();j++) printf(" %d",v[i][j].row) ;
            printf("\n") ;
            for(int j=0;j<v[i].size();j++) printf("%d%c",v[i][j].val,j==v[i].size()-1?'\n':' ') ;
            if(v[i].size()==0) printf("\n") ;
        }
    }
}
