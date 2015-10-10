#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
//#include<stdlib.h>
using namespace std;
struct P {int a,b,c,d;};
vector<P> v ;
bool G[400][400] ;
int last[400] ;
main()
{
        //freopen("1.txt","r",stdin) ;
        //freopen("2.txt","w",stdout) ;
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        v.clear() ;
        v.push_back((P){0,0,0,1}) ;
        int x=0 , y=1 ;
        for(int z=1;z<=n;z++)
        {
            int k=v.size() ;
            for(int i=0;i<k;i++)
            {
                int x1=v[i].a,y1=v[i].b,x2=v[i].c,y2=v[i].d ;
                v.push_back((P){x+(y1-y),y-(x1-x),x+(y2-y),y-(x2-x)}) ;
            }
            int nx=x-y , ny=x+y ;
            x=nx ; y=ny ;
        }
        int minx=10000,miny=10000 ;
        //for(int i=0;i<v.size();i++) printf("(%d,%d),(%d,%d)\n",v[i].a,v[i].b,v[i].c,v[i].d) ;
        for(int i=0;i<v.size();i++)
        {
            minx=min(minx,v[i].a) ; minx=min(minx,v[i].c) ;
            miny=min(miny,v[i].b) ; miny=min(miny,v[i].d) ;
        }
        for(int i=0;i<v.size();i++)
        {
            v[i].a -= minx ; v[i].c -= minx ;
            v[i].b -= miny ; v[i].d -= miny ;
        }

        memset(G,0,sizeof(G)) ;
        memset(last,-1,sizeof(last)) ;
        for(int i=0;i<v.size();i++)
        {
            G[max(v[i].a,v[i].c)][v[i].b+v[i].d]=1 ;
            if(last[max(v[i].a,v[i].c)]==-1 || last[max(v[i].a,v[i].c)]<v[i].b+v[i].d)
                last[max(v[i].a,v[i].c)]=v[i].b+v[i].d ;
        }


        int st1=0 , st2=1 ;
        if(last[0]==-1) st1=1 ;
        for(int i=st1;last[i]!=-1;i++) if(G[i][0]) {st2=0 ; break ;}

        for(int i=st1;last[i]!=-1;i++) for(int j=st2;j<=last[i];j++)
        {
            if(!G[i][j]) printf(" ") ;
            else if(j%2==0) printf("|") ;
            else printf("_") ;
            if(j==last[i]) printf("\n") ;
        }
        printf("^\n") ;
    }
}
