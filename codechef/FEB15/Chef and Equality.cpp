#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

int num[maxn] ;

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        memset(num,0,sizeof(num)) ;
        int M=0 ;
        for(int i=1;i<=n;i++)
        {
            int x ; scanf("%d",&x) ;
            num[x]++ ; M=max(M,num[x]) ;
        }
        printf("%d\n",n-M) ;
    }
}
