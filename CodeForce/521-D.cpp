#include<bits/stdc++.h>
#define DB double
#define pdi pair<DB,int>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
const int maxn=200000+10 ;

int type[maxn] ;
vector<pdi> v ;

int a[maxn],Set[maxn],id[maxn] ;
vector<pii> add[maxn] ;
vector<int> ans ;
main()
{
    int n,m,k ; scanf("%d%d%d",&n,&m,&k) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    memset(Set,-1,sizeof(Set)) ;
    for(int i=1;i<=m;i++)
    {
        int t,p,b ; scanf("%d%d%d",&t,&p,&b) ;
        type[i]=t ;
        if(t==1 && b>Set[p]) Set[p]=b , id[p]=i ;
        else if(t==2) add[p].push_back((pii){b,i}) ;
        else if(t==3) v.push_back((pdi){(DB)b,i}) ;
    }
    for(int i=1;i<=n;i++) if(Set[i]!=-1 && Set[i]>a[i])
        add[i].push_back((pii){Set[i]-a[i],id[i]}) ;
    for(int i=1;i<=n;i++) if(!add[i].empty())
    {
        sort(add[i].begin(),add[i].end(),greater<pii>()) ;
        DB now=a[i] ;
        for(auto j : add[i])
        {
            DB now2=now+j.F ;
            v.push_back((pdi){now2/now,j.S}) ;
            now=now2 ;
        }
    }

    sort(v.begin(),v.end(),greater<pdi>()) ;
    for(int i=0;i<k && i<v.size();i++)
        ans.push_back(v[i].S) ;

    printf("%d\n",ans.size()) ;
    int cnt=0 ;
    for(auto i : ans) if(type[i]==1)
        printf("%d%c",i,++cnt==ans.size()?'\n':' ') ;
    for(auto i : ans) if(type[i]==2)
        printf("%d%c",i,++cnt==ans.size()?'\n':' ') ;
    for(auto i : ans) if(type[i]==3)
        printf("%d%c",i,++cnt==ans.size()?'\n':' ') ;
}
