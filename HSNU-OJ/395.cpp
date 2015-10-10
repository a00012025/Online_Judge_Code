#include<bits/stdc++.h>
using namespace std;
const int maxn=100+10 ;
int a[maxn],b[maxn] ;
struct P{int x,y ;};
vector<P> v ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    for(int i=1;i<=n;i++) scanf("%d",&b[i]) ;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==b[i]) continue ;
        if(a[i]>b[i])
        {
            for(int j=i+1;a[i]!=b[i];j++) while(a[j]<b[j] && a[i]!=b[i])
                a[j]++ , a[i]-- , v.push_back((P){i,j}) ;
        }
        else
        {
            for(int j=i+1;a[i]!=b[i];j++) while(a[j]>b[j] && a[i]!=b[i])
                a[j]-- , a[i]++ , v.push_back((P){j,i}) ;
        }
    }
    printf("%d\n",v.size()) ;
    for(auto i : v) printf("%d %d\n",i.x,i.y) ;
}
