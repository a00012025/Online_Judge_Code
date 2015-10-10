#include<stdio.h>
#include<string.h>
int a[200001],b[200001],ans[200001] ;

void mer(int l,int r)
{
    if(l==r) return ;
    int mid=(l+r)/2 ;
    mer(l,mid) ; mer(mid+1,r) ;
    int cnt=l ,i=l , j=mid+1;
    while(i!=mid+1 || j!=r+1)
    {
        if((i==mid+1) || (j!=r+1 && a[j]<a[i]))
        {
            b[cnt]=a[j] ; ans[a[j]]+=mid+1-i ;
            j++ ;
        }
        else
        {
            b[cnt]=a[i] ; ans[a[i]]+=j-mid-1 ;
            i++ ;
        }
        cnt++ ;
    }
    for(int i=l;i<=r;i++) a[i]=b[i] ;
}

main()
{
    int n,m ;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        memset(ans,0,sizeof(ans)) ;
        mer(1,n) ;
        int sum=0 ;
        for(int i=1;i<=n;i++) sum+=ans[i] , printf("%d,",ans[i]) ;
            printf("\n");
        while(m--)
        {
            int x;
            scanf("%d",&x) ;
            printf("%d\n",sum/2) ; sum-=2*ans[x] ;
        }
    }
}
