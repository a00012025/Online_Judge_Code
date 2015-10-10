#include<stdio.h>
#include<math.h>
#include<set>
#define ULL unsigned long long
#define PWR(a) ((a)*(a))
using namespace std;
int x[1010],y[1010] ;
ULL dis[1010][1010] ;
ULL d(int a,int b)
{
    return PWR((ULL)(x[a]-x[b]))+PWR((ULL)(y[a]-y[b])) ;
}
main()
{
    int T;
    set<int> s1,s2 ;
    set<int>::iterator it1,it2;
    scanf("%d",&T) ;
    while(T--)
    {
        int n ;
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d %d",&x[i],&y[i]) ;
        for(int i=1;i<=n;i++) for(int j=i;j<=n;j++)
        {
            if(j==i) {dis[i][i]=0 ; continue ;}
            dis[i][j]=d(i,j) ;
            dis[j][i]=dis[i][j] ;
        }
        s1.clear() ; s2.clear() ;
        s1.insert(1) ; for(int i=2;i<=n;i++) s2.insert(i) ;
        ULL edgemax=0 ;
        for(int num=1;num<n;num++)
        {
            ULL m=1LL<<63 ;
            int minx,miny ;
            for(it1=s1.begin();it1!=s1.end();it1++)
                for(it2=s2.begin();it2!=s2.end();it2++)
            {
                if(dis[*it1][*it2]<m)
                {
                    m=dis[*it1][*it2] ;
                    minx=*it1 ;
                    miny=*it2 ;
                }
            }
            s1.insert(miny) ;
            s2.erase(miny) ;
            if(m>edgemax) edgemax=m ;
        }
        printf("%llu\n",(ULL)ceil(sqrtl(edgemax)/2)) ;
        }
}
