#include<bits/stdc++.h>
using namespace std;

int num[3000] ;

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        memset(num,0,sizeof(num)) ;
        int ans=0 ;
        for(int i=1;i<=n;i++)
        {
            if(num[i] < n/i-1)
                for(int j=2*i;j<=n;j+=i) num[j]++ ;
            else ans+=num[i] ;
        }
        printf("%d\n",ans) ;
    }
}
