#include<bits/stdc++.h>
#define LL long long
#define MOD 1000000000
#define pii pair<int,int>
#define F first
#define S second
#define mkp(x,y) make_pair(x,y)
using namespace std;
const int maxn=100000+10 , dx[]={1,-1,0,0} , dy[]={0,0,1,-1} ;

vector<int> v[maxn] ;
vector<pii> tmp ;
map<pii,int> mp ;
queue<int> q ;
pii a[maxn] ;
int deg[maxn],num[maxn] ;
main()
{
    int n ;
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].F,&a[i].S) ;
        mp[a[i]]=i ;
        num[i]=1 ;
    }
    for(int i=1;i<=n;i++) for(int z=0;z<4;z++)
    {
        int nx=a[i].F+dx[z] , ny=a[i].S+dy[z] ;
        if(mp.count(mkp(nx,ny)))
            v[i].push_back(mp[mkp(nx,ny)]) ,
            deg[i]++ ;
    }

    for(int i=1;i<=n;i++) if(deg[i]==1) q.push(i) ;

    LL ans=0LL ;
    int n2=n ;
    while(n2)
    {
        while(!q.empty())
        {
            int u=q.front() ; q.pop() ;
            deg[u]-- ; n2-- ;
            mp.erase(a[u]) ;
            ans+=((LL)num[u])*((LL)n-num[u]) ; ans%=MOD ;
            for(int i=0;i<v[u].size();i++)
            {
                num[v[u][i]]+=num[u] ;
                if((--deg[v[u][i]])==1) q.push(v[u][i]) ;
            }
        }
        if(!n2) break ;
        tmp.clear() ;
        map<pii,int>::iterator it1=mp.begin() , it2 ;
        LL sum=0LL ;
        for(it2=it1;it2!=mp.end() && it2->F.F==it1->F.F;it2++)
        {
            sum+=num[it2->S] ;
            deg[it2->S]=0 ;
            for(int i=0;i<v[it2->S].size();i++)
                if(a[v[it2->S][i]].F != it2->F.F)
            {
                if((--deg[v[it2->S][i]])==1) q.push(v[it2->S][i]) ;
                num[v[it2->S][i]]+=num[it2->S] ;
            }
            tmp.push_back(it2->F) ;
            n2-- ;
        }
        ans+=sum*((LL)n-sum) ; ans%=MOD ;
        for(int i=0;i<tmp.size();i++) mp.erase(tmp[i]) ;
    }
    printf("%I64d\n",ans) ;
}
