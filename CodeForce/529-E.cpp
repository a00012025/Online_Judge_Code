#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int maxn=5000+10 ;

int a[maxn],t[maxn*20],val[maxn*20] ;
map<int,int> mp ;
main()
{
    int n,k ; scanf("%d%d",&n,&k) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    mp[0]=0 ;
    for(int i=k;i>=1;i--) for(int j=1;j<=n;j++)
        mp[i*a[j]]=i ;

    int cnt=0 ;
    for(auto it : mp)
        t[cnt]=it.F , val[cnt]=it.S , cnt++ ;

    int Q ; scanf("%d",&Q) ;
    while(Q--)
    {
        int x ; scanf("%d",&x) ;
        int ans=k+1 ;
        for(int i=0;t[i]<=x && i<cnt;i++)
        {
            auto it=mp.find(x-t[i]) ;
            if(it!=mp.end()) ans=min(ans,val[i]+it->S) ;
        }
        printf("%d\n",ans==k+1?-1:ans) ;
    }
}
