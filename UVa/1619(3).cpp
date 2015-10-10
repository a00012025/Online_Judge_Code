#include<stdio.h>
#include<stack>
#include<string.h>
#include<stdlib.h>
#define LL long long
using namespace std;
int n,right[100011],ansl,ansr ;
bool vis[100011] ;
LL a[100011],sum[100011],ans ;

bool better(LL val,int l,int r)
{
    if(ans==-1) return 1;
    else if(val != ans) return val>ans ;
    else if(r-l != ansr-ansl) return r-l<ansr-ansl ;
    else return l<ansl ;
}

main()
{
        //freopen("1.txt","r",stdin) ;
    bool fir=1 ;
    while(~scanf("%d",&n))
    {
        sum[0]=0LL ;
        bool all_zero=1 ;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]) ;
            sum[i]=sum[i-1]+a[i] ;
            right[i]=n+1 ;
            if(a[i]) all_zero=0 ;
        }
        stack<int> st ;
        for(int i=1;i<=n;i++)
        {
            while(!st.empty() && a[st.top()]>a[i])
            {
                right[st.top()]=i ;
                st.pop() ;
            }
            st.push(i) ;
        }
        ans=-1 ;
        memset(vis,0,sizeof(vis)) ;
        for(int i=1;i<=n;i++) if(!vis[i])
        {
            for(int j=i;j!=n+1;j=right[j])
            {
                LL val=a[j]*(sum[right[j]-1]-sum[i-1]) ;
                if(better(val,i,right[j]-1))
                    {ans=val ; ansl=i ; ansr=right[j]-1 ;}
                vis[j]=1 ;
            }
        }
        if(fir) fir=0 ;
        else printf("\n") ;
        if(all_zero) {ansl=1 ; ansr=1 ;}
        printf("%lld\n%d %d\n",ans,ansl,ansr) ;
    }
}
