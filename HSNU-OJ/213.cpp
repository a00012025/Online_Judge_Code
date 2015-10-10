#include<bits/stdc++.h>
#define LL long long
using namespace std;

int num[1000010] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        memset(num,0,sizeof(num)) ;
        int n,a,b,c ; LL x ; scanf("%d%d%d%d%I64d",&n,&a,&b,&c,&x) ;
        int i,t1=-1,t2=-1 ;
        for(i=1;i<=n;i++)
        {
            if(num[x]==1 && t1==-1) t1=i ;
            else if(num[x]==2 && t2==-1) { t2=i ; break ; }
            num[x]++ ;
            x=(a*x+b)%c ;
        }

        if(i!=n+1)
        {
            int res=n-i+1 , len=t2-t1 ;
            int q=res/len , r=res-q*len ;
            for(LL y=x ; r-- ; y= (a*y+b)%c )
                num[y]++ ;
            for(LL y=(a*x+b)%c ;  ; y= (a*y+b)%c )
                { num[y]+=q ; if(y==x) break ; }
        }

        LL sum=0LL ; int M=0 ;
        for(int i=0;i<=1000000;i++)
        {
            sum+=((LL)i)*((LL)num[i]) ;
            if(num[i]) M=max(M,i) ;
        }
        printf("%I64d\n",sum+((LL)n-2)*((LL)M)) ;
    }
}
