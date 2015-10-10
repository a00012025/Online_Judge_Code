#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v[100001] ;
int a[100001],n ;
main()
{
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        sort(a+1,a+n+1) ;
        int ans=0,cnt=1 ;
        for(int i=2;i<=n;i++)
        {
            if(a[i]==a[i-1]) cnt++ ;
            else {ans=max(ans,cnt) ; cnt=1 ;}
        }
        ans=max(ans,cnt) ;
        for(int i=0;i<=ans;i++) v[i].clear() ;
        for(int i=1;i<=n;i++)
            v[((i-1)%ans)+1].push_back(a[i]) ;
        printf("%d\n",ans) ;
        for(int i=1;i<=ans;i++)
            for(int j=0;j<v[i].size();j++)
            printf("%d%c",v[i][j],j==v[i].size()-1?'\n':' ');
        printf("\n") ;
    }
}
