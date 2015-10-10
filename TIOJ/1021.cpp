#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL power[]={1,10,100,1000,10000,100000,
            1000000,10000000,100000000,1000000000} ;

LL cal(int x,int k)
{
    int ret=0 ;
    while(x)
    {
        if(x%10==k) ret++ ;
        x/=10 ;
    }
    return ret ;
}

LL solve(int x,int num,int k)
{
    printf("solve (%d,%d,%d) : ",x,num,k) ;
    LL tmp=cal(x,k)*power[num] ;
    if(k || x) tmp+= num==0 ? 0 : num*power[num-1] ;
    else
    {
        for(int i=1;i<num;i++) tmp+=((LL)i)*power[i-1] ;
        tmp*=9 ;
    }
    printf("%I64d\n",tmp) ;
    return tmp ;
}

int a[20] ;
main()
{
    int n,k ;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        int cnt=0,n2=n ;
        LL ans=0LL ;
        while(n) a[cnt++]=n%10 , n/=10 ;
        int x=0 ;
        for(int i=cnt-1;i>=0;i--)
        {
            int t=0 ;
            while(t<a[i]) ans+=solve(x++,i,k) , t++ ;
            x*=10 ;
        }
        ans+=solve(n2,0,k) ;
        printf("%I64d\n",ans) ;
    }
}
