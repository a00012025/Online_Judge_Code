#include<bits/stdc++.h>
using namespace std;

int a[2001] ;
main()
{
    memset(a,0,sizeof(a)) ;
    int n ; scanf("%d",&n) ;
    while(n--)
    {
        int x ; scanf("%d",&x) ;
        a[x]++ ;
    }
    int ans=0 ;
    for(int i=1;i<=500;i++) if(a[i])
    {
        int sum=0,j ;
        for(j=i;j<=min(500,2*i-1);j++) sum+=a[j] ;
        if(a[i]>1) ans=max(ans,sum) ;
        else ans=max(ans,sum+a[2*i]) ;
        for(;j<=500;j++)
        {
            if(j==2*i) sum-=a[j-i]-1 ;
            else sum-=a[j-i] ;
            sum+=a[j] ;
            ans=max(ans,sum) ;
        }
    }
    printf("%d\n",ans) ;
}
