#include<bits/stdc++.h>
using namespace std;

int sum(int x)
{
    int ret=0 ;
    while(x)
    {
        ret+=(x%10)*(x%10) ;
        x/=10 ;
    }
    return ret ;
}

int ans[80000] ;

int f(int x)
{
    if(x==1) return 1 ;
    if(ans[x]==-1) return 2 ;
    ans[x]=-1 ; ans[x]=f(sum(x)) ;
}

main()
{
    for(int i=1;i<80000;i++) if(!ans[i])
        ans[i]=f(i) ; /// 1 : yes , 2 : no ;
    int cnt=0 ;
    for(int i=1;i<80000;i++) if(ans[i]==1)
    {
        cnt++ ;
        if(cnt==10 || cnt==50 || cnt==100 || cnt==1000 || cnt==10000) printf("%d\n",i) ;
    }
}
