#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=2000000+10 ;

struct P
{
    int from,to ; LL t,p ;
    bool operator < (const P &rhs) const
    {
        return p==rhs.p ? t<rhs.t : p<rhs.p ;
    }
};

vector<P> edge ;
LL d[maxn] ;
int id[maxn] ;
LL val[maxn] ;
main()
{
    int n,m,st,ed ;
    scanf("%d%d%d%d",&n,&m,&st,&ed) ;
    memset(d,-1,sizeof(d)) ; d[st]=0 ;
    while(m--)
    {
        int x,y ; LL t,p ; scanf("%d%d%lld%lld",&x,&y,&t,&p) ;
        edge.push_back((P){x,y,t,p}) ;
    }
    sort(edge.begin(),edge.end()) ;
    for(int i=0;i<edge.size();i++)
    {
        int j ;
        for(j=i;j<edge.size() && edge[j].p==edge[i].p;j++) ; j-- ;
        int cnt=0 ;
        for(int k=i;k<=j;k++)
        {
            int x=edge[k].from , y=edge[k].to ;
            LL t=edge[k].t ;
            if(d[y]!=-1 && (d[x]==-1 || d[x]>d[y]+t))
                id[cnt]=x , val[cnt]=d[y]+t , cnt++ ;
            if(d[x]!=-1 && (d[y]==-1 || d[y]>d[x]+t))
                id[cnt]=y , val[cnt]=d[x]+t , cnt++ ;
        }
        for(int k=0;k<cnt;k++)
            d[id[k]]= d[id[k]]==-1 ? val[k] : min(d[id[k]],val[k]) ;
        i=j ;
    }
    if(d[ed]==-1) printf("Pipi how way!!!\n") ;
    else printf("%lld\n",d[ed]) ;
}
