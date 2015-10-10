#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=500000+10 ;

int mu[maxn],di[maxn] ;
bool vis[maxn] ;
void getmu()
{
    for(int i=2;i*i<maxn;i++) if(!vis[i])
        for(int j=i*i;j<maxn;j+=i) vis[j]=1 , di[j]=i ;
    for(int i=2;i<maxn;i++)
    {
        if(!vis[i]){mu[i]=-1 ; continue ;}
        mu[i]= (i/di[i])%di[i] ? mu[i/di[i]]*-1 : 0 ;
    }
}

int a[maxn],num[maxn] ;
bool on[maxn] ;
vector<int> vd ;
void getdiv(int x)
{
    vd.clear() ;
    for(int i=1;i*i<=x;i++) if(x%i==0)
    {
        vd.push_back(i) ;
        if(i*i!=x) vd.push_back(x/i) ;
    }
}

int getval()
{
    int ret=num[1] ;
    for(auto i : vd) ret+=num[i]*mu[i] ;
    return ret ;
}

inline void add(int x)
{
    for(auto i : vd) num[i]+=x ;
}

main()
{
    getmu() ;
    int n,Q ; scanf("%d%d",&n,&Q) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    LL ans=0 ;
    while(Q--)
    {
        int x ; scanf("%d",&x) ;
        getdiv(a[x]) ;
        if(!on[x]) ans+=getval() , add(1) , on[x]=1 ;
        else add(-1) , ans-=getval() , on[x]=0 ;
        printf("%I64d\n",ans) ;
    }
}
