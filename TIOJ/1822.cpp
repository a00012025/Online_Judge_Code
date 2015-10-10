#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int maxn=300000+10 ;
int now[maxn] ;
map<int,int> mp ;
main()
{
    int n,m ; scanf("%d%d",&n,&m) ;
    while(m--)
    {
        int x ; scanf("%d",&x) ;
        mp[x]++ ;
    }
    for(auto i : mp) if(i.S%2)
    {
        for(int j=i.F;j<=n;j+=i.F) now[j]^=1 ;
    }
    printf("%d\n",count(now+1,now+n+1,1)) ;
    for(int i=1;i<=n;i++) if(now[i]) printf("%d\n",i) ;
}
