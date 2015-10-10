#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
struct P {int w,h ;}p[20001];
bool cmp(P x,P y)
{
    if(x.w != y.w) return x.w>y.w ;
    else return x.h<y.h ;
}
vector<P> ans ;
int v_lower_bound(int val)
{
    if(ans.size() && ans[0].h>val) return 0 ;
    int l=0 , r=ans.size() ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(ans[mid].h>val) r=mid ;
        else l=mid ;
    }
    return r ;
}
main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int n;
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d%d",&p[i].w,&p[i].h) ;
        sort(p+1,p+n+1,cmp) ;
        ans.clear() ;
        for(int i=1;i<=n;i++)
        {
            int id=v_lower_bound(p[i].h) ;
            if(id!=ans.size()) ans[id].h=p[i].h ;
            else ans.push_back(p[i]) ;
        }
        printf("%d\n",ans.size()) ;
    }
}
