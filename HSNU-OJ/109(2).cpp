#include<bits/stdc++.h>
#define INF 1000000000
#define MKP(x,y) make_pair(x,y)
#define F first
#define S second
using namespace std;

pair<int,int> p[30] ;
vector<int> v[30] ;
int n,m,tmp[30] ;

int cal()
{
    int ret=0 ;
    for(int i=1;i<=n*m;i++) for(int x=0;x<v[i].size();x++)
    {
        int j=v[i][x] ;
        ret+=(p[i].F-p[j].F)*(p[i].F-p[j].F)+(p[i].S-p[j].S)*(p[i].S-p[j].S) ;
    }
    return ret/2 ;
}

void get_rand(int &x,int &y)
{
    while(1)
    {
        x=(rand()%(n*m))+n*m ; x%=n*m ; x++ ;
        y=(rand()%(n*m))+n*m ; y%=n*m ; y++ ;
        if(x!=y) break ;
    }
}

main()
{
    srand(time(NULL)) ;
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d%d",&n,&m) ;
        for(int i=1;i<=n*m;i++) v[i].clear() ;
        for(int i=1;i<n*m;i++)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            v[x].push_back(y) ; v[y].push_back(x) ;
        }
        int num1=10 , num2=1000 , ans=INF ;
        for(int x1=1;x1<=num1;x1++)
        {
            for(int i=1;i<=n*m;i++) tmp[i]=i ;
            random_shuffle(tmp+1,tmp+n*m+1) ;
            for(int i=1;i<=n*m;i++)
                p[i]=MKP(((tmp[i]-1)/m)+1,((tmp[i]-1)%m)+1) ;
            for(int x2=1;x2<=num2;x2++)
            {
                int val1=cal() ; ans=min(ans,val1) ;
                int x,y ; get_rand(x,y) ;
                swap(p[x],p[y]) ;
                int val2=cal() ; ans=min(ans,val2) ;
                if(val2>val1) swap(p[x],p[y]) ;
            }
        }
        printf("%d\n",ans) ;
    }
}
