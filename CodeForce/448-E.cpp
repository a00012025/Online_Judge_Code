#include<bits/stdc++.h>
#define LL long long
#define INF (1LL<<60)
using namespace std;
const int maxn=1000000 ;

int dcnt ;
LL di[maxn] ;
int getid(LL x)
{
    return lower_bound(di,di+dcnt,x)-di ;
}

vector<int> v[maxn] ;
int cnt=0 ;
bool dfs(int id,LL num)
{
    if(num==0 || id==0)
    {
        printf("%lld ",di[id]) ;
        return ++cnt==100000 ? 1 : 0 ;
    }
    for(auto i : v[id]) if(dfs(i,num-1)) return 1 ;
    return 0 ;
}

main()
{
    LL x,k ; scanf("%lld%lld",&x,&k) ;
    for(LL i=1;i*i<=x;i++) if(!(x%i))
    {
        di[dcnt++]=i ;
        if(i*i!=x) di[dcnt++]=x/i ;
    }
    sort(di,di+dcnt) ;
    for(int i=0;i<dcnt;i++) for(int j=0;j<dcnt;j++) if(!((x/di[i])%di[j]))
        v[getid(di[i]*di[j])].push_back(i) ;
    dfs(dcnt-1,k) ;
    printf("\n") ;
}
