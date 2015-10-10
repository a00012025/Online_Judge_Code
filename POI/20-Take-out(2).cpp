#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;

int st[maxn],sum[maxn] ;
char s[maxn] ;
vector<int> v[maxn] ;

int S(int x,int y)
{
    return x ? sum[y]-sum[x-1] : sum[y] ;
}

main()
{
    int n,k ; scanf("%d%d%s",&n,&k,s+1) ;
    int sz=0 , now=1 ;
    for(int i=1;i<=n;i++)
    {
        st[sz]=i ;
        if(s[i]=='c') sum[sz]=(sz ? sum[sz-1] : 0) + 1 ;
        else sum[sz]= ( sz ? sum[sz-1] : 0 ) ;
        sz++ ;
        if(sz>=k+1 && S(sz-k-1,sz-1)==1)
        {
            for(int j=sz-k-1;j<=sz-1;j++) v[now].push_back(st[j]) ;
            sz-=k+1 ;
            now++ ;
        }
    }
    for(int i=n/(k+1);i>=1;i--)
        for(int j=0;j<v[i].size();j++) printf("%d%c",v[i][j],j+1==v[i].size()?'\n':' ') ;
}
