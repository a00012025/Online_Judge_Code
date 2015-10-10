#include<string.h>
#include<stdio.h>
#define MOD 4999999 ;
#define LL long long
int a[4001],b[4001],c[4001],d[4001] ;
int data[16000007],next[16000007],head[4999999] ;

int h(int index)
{
    int ret=data[index]%MOD ;
    if(ret<0) ret+=MOD ;
    return ret ;
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int n;
        scanf("%d",&n) ;
        memset(head,0,sizeof(head)) ;
        memset(next,0,sizeof(next)) ;
        for(int i=1;i<=n;i++) scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]) ;
        int cnt=0 ;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        {
            cnt++ ;
            data[cnt]=a[i]+b[j] ;
            int val=h(cnt) ;
            if(head[val]==0) head[val]=cnt ;
            else
            {
                next[cnt]=head[val] ;
                head[val]=cnt ;
            }
        }
        LL ans=0 ;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        {
            int val=(-c[i]-d[j]) % MOD ; if(val<0) val+=MOD ;
            for(int now=head[val];now!=0;now=next[now])
                    if(data[now]+c[i]+d[j]==0) ans++ ;
        }
        printf("%lld\n",ans) ;
        if(T) printf("\n") ;
    }
}
