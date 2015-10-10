#include<stdio.h>
int a[1001],n,m ;

bool check(int k)
{
    int sum=0 , cnt=0 ;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>k) return 0 ;
        if(sum+a[i]>k) {sum=a[i] ; cnt++ ;}
        else sum+=a[i] ;
    }
    cnt++ ;
    if(cnt>m) return 0;
    else return 1 ;
}

main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int sum=0 ;
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]) ; sum+=a[i] ;}
        int l=0,r=sum ;
        while(r-l>1)
        {
            int mid=(r+l)/2 ;
            if(check(mid)) r=mid ;
            else l=mid ;
        }
        printf("%d\n",r) ;
    }
}
