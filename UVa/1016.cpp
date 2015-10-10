#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#define pii pair<int,int>
#define mkp(x,y) make_pair(x,y) ;
using namespace std;
int a[2000],per[2000] ;
bool vis[2000] ;
pii p[2000] ;
main()
{
    int n,tc=0;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=1;i<=n;i++)
        {
            int x ; scanf("%d",&x) ;
            p[i]=mkp(x,i) ;
        }
        sort(p+1,p+n+1) ;
        for(int i=1;i<=n;i++) {per[p[i].second]=i ; a[i]=p[i].first ;}
        memset(vis,0,sizeof(vis)) ;
        int ans=0 ;
        vector<int> v;
        for(int i=1;i<=n;i++) if(!vis[i] && per[i]!=i)
        {
            v.clear() ;
            v.push_back(i) ; vis[i]=1 ;
            for(int j=per[i];j!=i;j=per[j]) {v.push_back(j) ; vis[j]=1 ;}
            sort(v.begin(),v.end()) ;

            int m;
            for(m=0;m<v.size() && v[m]==m+1;m++) ;
            m++ ;

            int add1=0,add2= m==n+1 ? 1000000000 : 0 ;
            for(int j=0;j<v.size();j++) {add1+=a[v[j]] ; add2+=a[v[j]] ;}
            add1 += a[v[0]]*(v.size()-2) ;
            add2 += a[m]*(v.size()+1)+a[v[0]] ;
            ans+=min(add1,add2) ;
        }
        printf("Case %d: %d\n\n",++tc,ans) ;
    }
}
