#include<bits/stdc++.h>
using namespace std;

bool di[2001][2001] ;

main()
{
    for(int i=1;i<2000;i++) for(int j=1;j<=i;j++)
        if(i%j==0) di[i][j]=1 ;
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        int ans=0 ;
        vector<int> v ;
        for(int i=1;i<(1<<n);i++)
        {
            bool ok=1 ;
            for(int j=n/2+1;j<n;j++) if(!(i&(1<<j)))
                {ok=0 ; break ;}
            if(!ok) continue ;

            int val=0 ;
            for(int j=0;j<n;j++) if(i&(1<<j))
                for(int k=0;k<n;k++)
                if(!(i&(1<<k)) && di[j+1][k+1]) val++ ;
            if(val>ans) v.clear() , ans=val , v.push_back(i) ;
            else if(val==ans) v.push_back(i) ;
        }
        printf("ans = %d\n\n",ans) ;
        for(auto i : v)
        {
            for(int j=0;j<n;j++) if(!(i&(1<<j)))
                printf("%d,",j+1) ;
            printf("\n") ;
            for(int j=0;j<n;j++) if(i&(1<<j))
                printf("%d,",j+1) ;
            printf("\n\n") ;
        }
    }
}
