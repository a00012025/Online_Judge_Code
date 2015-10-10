#include<bits/stdc++.h>
using namespace std;
struct P{int val,id;}a[4000];
bool cmp(P x,P y){return x.val<y.val ;}
int p[4000] ;
bool vis[4000]={0} ;
vector<P> ans ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=0;i<n;i++) scanf("%d",&a[i].val) , a[i].id=i ;
    sort(a,a+n,cmp) ;
    for(int i=0;i<n;i++) p[i]=a[i].id ;
    for(int i=0;i<n;i++) if(!vis[i] && p[i]!=i)
    {
        for(int j=i;p[j]!=i;j=p[j])
            {vis[p[j]]=1 ; ans.push_back((P){j,p[j]}) ;}
    }
    printf("%d\n",ans.size()) ;
    for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].val,ans[i].id) ;
}
