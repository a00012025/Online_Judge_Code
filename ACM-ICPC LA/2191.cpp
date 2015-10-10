#include<stdio.h>
#define low(x) (x&-x)
int a[200001],sum[200001],bit[200001] ;

int cnt(int x)
{
    if(!x) return 0 ;
    return bit[x]+cnt(x-low(x)) ;
}

main()
{
    int n,tc=0;
    while(scanf("%d",&n)==1 && n)
    {
        sum[0]=0 ;
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]); sum[i]=sum[i-1]+a[i] ;}
        for(int i=1;i<=n;i++) bit[i]=sum[i]-sum[i-low(i)] ;
        if(tc) printf("\n") ;
        printf("Case %d:\n",++tc) ;
        while(1)
        {
            char s[100] ;
            scanf("%s",s) ;
            if(s[0]=='E') break ;
            if(s[0]=='S')
            {
                int x,y,add ;
                scanf("%d %d",&x,&y) ;
                add=y-a[x] ; a[x]=y ;
                while(x<=n) {bit[x]+=add ; x+=low(x) ;}
            }
            else
            {
                int x,y ;
                scanf("%d %d",&x,&y) ;
                printf("%d\n",cnt(y)-cnt(x-1)) ;
            }
        }
    }
}
