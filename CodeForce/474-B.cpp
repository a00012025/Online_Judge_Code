#include<stdio.h>
main()
{
    int a[100001],s[100001] ;
    int n;
    s[0]=0 ;
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        s[i]=s[i-1]+a[i] ;
    }
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        int a,ans;
        scanf("%d",&a) ;
        int l=1 , r=n ;
        if(a<=s[1]) {printf("1\n") ; continue ;}
        else while(r-l>1)
        {
            int mid=(r+l)/2 ;
            if(s[mid]>=a) r=mid ;
            else l=mid ;
        }
        printf("%d\n",r) ;
    }
}
