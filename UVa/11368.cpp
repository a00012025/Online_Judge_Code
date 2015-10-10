#include<stdio.h>
#include<stack>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
struct P {int w,h ;};
struct Q {int h,id ;};
bool cmp(P x,P y)
{
    if(x.w != y.w) return x.w<y.w ;
    else return x.h>y.h ;
}
P p[20001] ;
stack<P> st ;
vector<Q> v[10001] ;
int last[20001],done[20001] ;
int v_lower_bound(int a,int val)
{
    int l=0 , r=v[a].size() ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(v[a][mid].h>=val) r=mid ;
        else l=mid ;
    }
    return r ;
}
main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d%d",&p[i].w,&p[i].h) ;
        sort(p+1,p+n+1,cmp) ;
        for(int i=1;i<=10000;i++) v[i].clear() ;
        for(int i=n;i>=1;i--) v[p[i].w].push_back((Q){p[i].h,i}) ;
        while(!st.empty()) st.pop() ;
        for(int i=1;i<=n;i++)
        {
            while(!st.empty() && st.top().h>=p[i].h) st.pop() ;
            if(st.empty()) last[i]=i ;
            else
            {
                int w=st.top().w ;
                int id=v_lower_bound(w,p[i].h)  ;
                id-- ;
                last[i]=v[w][id].id ;
            }
            st.push(p[i]) ;
        }
            for(int i=1;i<=n;i++) printf("%d,",last[i]);
            printf("\n");
        int ans=0 ;
        memset(done,0,sizeof(done)) ;
        for(int i=n;i>=1;i--)
        {
            if(done[i]) continue ;
            int j=i ;
            while(1)
            {
                done[j]=1 ;
                if(j==last[j]) break ;
                j=last[j] ;
            }
            ans++ ;
        }
        printf("%d\n",ans) ;
    }
}
