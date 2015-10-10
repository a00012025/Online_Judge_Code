#include<stdio.h>
int a[1000],n,k ;

bool check(int val)
{
    int sum=0 , num=0 ;
    for(int i=1;i<=n+1;i++)
    {
        if(a[i]>val) return 0;
        if(sum+a[i]>val) {num++ ; sum=a[i] ;}
        else sum+=a[i] ;
    }
        //printf("val=%d , num=%d\n",val,num) ;
    if(num<=k) return 1;
    else return 0 ;
}

main()
{
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        int sum=0 ;
        for(int i=1;i<=n+1;i++) {scanf("%d",&a[i]); sum+=a[i] ;}
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
