#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[2001],up[2001],down[2001],dp1[3001],dp2[3001] ;
main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int n;
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        int len1=1 , len2=1 ;

        dp1[1]=dp2[1]=a[n] ;
        up[n]=down[n]=1 ;
        for(int i=n-1;i>=1;i--)
        {
            int l=0,r=len1+1 ;
            while(r-l>1)
            {
                int mid=(r+l)/2 ;
                if(dp1[mid]<a[i]) r=mid ;
                else l=mid ;
            }
            if(l==len1) {dp1[len1+1]=a[i] ; len1++ ;}
            else dp1[l+1]=max(dp1[l+1],a[i]) ;
            up[i]=l+1 ;

            l=0,r=len2+1 ;
            while(r-l>1)
            {
                int mid=(r+l)/2 ;
                if(dp2[mid]>a[i]) r=mid ;
                else l=mid ;
            }
            if(l==len2) {dp2[len2+1]=a[i] ; len2++ ;}
            else dp2[l+1]=min(dp2[l+1],a[i]) ;
            down[i]=l+1 ;
        }
        int ans=0 ; if(n) ans=1 ;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
            if(a[i]>a[j]) ans=max(ans,up[i]+down[j]) ;
        printf("%d\n",ans) ;
    }
}
