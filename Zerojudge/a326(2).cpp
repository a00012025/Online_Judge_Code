#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
struct P {int x,y;};
char tmp[30] ;
int G[30][30] ;
vector<P> v ;

int bit_cnt(int x)
{
    if(!x) return 0 ;
    return x%2 ? 1+bit_cnt(x/2) : bit_cnt(x/2) ;
}

int n,m,k ;
bool solve()
{
    bool cant[50] ;
    for(int s=0;s<(1<<m);s++) if(bit_cnt(s)==k)
    {
        memset(cant,0,sizeof(cant)) ;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(G[i][j]>=0)
        {
            if(!(s & (1<<G[i][j])))
                cant[i]=cant[j+n]=1 ;
        }
        bool ok=1 ;
        for(int i=0;i<v.size();i++)
        {
            if(cant[v[i].x] && cant[v[i].y+n]) {ok=0 ; break ;}
        }
        if(ok) return 1;
    }
    return 0;
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&k) ;
        memset(G,-1,sizeof(G)) ;
        v.clear() ;
        for(int i=0;i<n;i++)
        {
            scanf("%s",tmp) ;
            for(int j=0;j<n;j++)
            {
                if(tmp[j]=='*')
                    v.push_back((P){i,j}) ;
                else if(tmp[j]!='.')
                    G[i][j]=tmp[j]-'A' ;
            }
        }
        if(solve()) printf("yes\n") ;
        else printf("no\n");
    }
}
