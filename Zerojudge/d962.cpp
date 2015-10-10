#include<bits/stdc++.h>
#define LL long long
#define FOR_SET(x,y) for(set<int>::iterator x=(y).begin();x!=(y).end();x++)
using namespace std;
const int maxn=50000+10 ;
set<int> ax[maxn],ay[maxn],bx[maxn],bz[maxn],cy[maxn],cz[maxn] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        LL n,m,h,t ; scanf("%lld%lld%lld%lld",&n,&m,&h,&t) ;
        LL a=0LL,b=0LL,c=0LL,ab=0LL,bc=0LL,ac=0LL,abc=0LL ;
        for(int i=0;i<maxn;i++)
        {
            ax[i].clear() ; ay[i].clear() ; bx[i].clear() ;
            bz[i].clear() ; cy[i].clear() ; cz[i].clear() ;
        }
        for(int i=1;i<=t;i++)
        {
            int p,q,r ; scanf("%d%d%d",&p,&q,&r) ;
            if(!r) {a+=h ; ax[p].insert(q) ; ay[q].insert(p) ;}
            if(!q) {b+=m ; bx[p].insert(r) ; bz[r].insert(p) ;}
            if(!p) {c+=n ; cy[q].insert(r) ; cz[r].insert(q) ;}
        }
        for(int i=1;i<=n;i++) ab+=((LL)ax[i].size())*((LL)bx[i].size()) ;
        for(int i=1;i<=m;i++) ac+=((LL)ay[i].size())*((LL)cy[i].size()) ;
        for(int i=1;i<=h;i++) bc+=((LL)bz[i].size())*((LL)cz[i].size()) ;
        for(int i=1;i<=n;i++) FOR_SET(it1,ax[i]) FOR_SET(it2,bx[i])
            if(cy[*it1].count(*it2)) abc++ ;
        printf("%lld\n",n*m*h-a-b-c+ab+bc+ac-abc) ;
    }
}
