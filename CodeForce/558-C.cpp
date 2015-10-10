#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

int ans[maxn] ;
int cnt[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int z=1;z<=n;z++)
    {
        int x ; scanf("%d",&x) ;
        for(int i=0,last=2*x+1;;x/=2,i++)
        {
            for(int y=x,j=0;y<=maxn;y*=2,j++)
            {
//                printf("get %d\n",y) ;
                cnt[y]++ ; ans[y]+=i+j ;
                if(!y || last==2*x) break ;
            }
            if(!x) break ;
            last=x ;
        }
    }
    int ANS=1e9 ;
    for(int i=0;i<maxn;i++) if(cnt[i]==n)
        ANS=min(ANS,ans[i]) ;
    printf("%d\n",ANS) ;
}
