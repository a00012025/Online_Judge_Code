#include<stdio.h>
int wei[100001],all,n ;

bool check(int x,int num)
{
    int sum=0,cnt=0 ;
    for(int i=0;i<n;i++)
    {
        if(wei[i]>x) return false ;
        sum+=wei[i] ;
        if(sum>x) {if(!num) return false ; num-- ; sum=wei[i] ;}
    }
    if(sum && !num) return false ;
    return true ;
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int k ; all=0 ;
        scanf("%d %d",&n,&k) ;
        for(int i=1;i<=n;i++)
        {
            int a,b ;
            scanf("%d %d",&a,&b) ;
            wei[a]=b ; all+=b ;
        }
        int l=0 , r=all+1 ;
        while(r-l>1)
        {
            int mid=(l+r)/2 ;
            if(check(mid,k)) r=mid ;
            else l=mid ;
        }
        printf("%d\n",r) ;
    }
}
