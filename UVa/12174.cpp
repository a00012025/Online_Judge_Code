#include<stdio.h>
#include<string.h>
int a[100001],cnt[100001] ;
bool fir[100001],last[100001],mid[100001] ;
main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int s,n ;
        scanf("%d%d",&s,&n) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        fir[0]=1 ; memset(cnt,0,sizeof(cnt)) ;
        for(int i=1;i<=n && i<=s;i++)
        {
            fir[i]=fir[i-1]&&(!cnt[a[i]]) ;
            cnt[a[i]]=1 ;
                //printf("fir[%d]=%d\n",i,fir[i]);
        }
        last[0]=1 ; memset(cnt,0,sizeof(cnt)) ;
        for(int i=1;i<=n && i<=s;i++)
        {
            last[i]=last[i-1]&&(!cnt[a[n+1-i]]) ;
            cnt[a[n+1-i]]=1 ;
                //printf("last[%d]=%d\n",i,last[i]);
        }
        memset(cnt,0,sizeof(cnt)) ;
        int num=0 ;
        if(s<=n)
        {
            for(int i=1;i<=s;i++) cnt[a[i]]++ ;
            for(int i=1;i<=s;i++) if(cnt[i]==1) num++ ;
            mid[1]= num==s ? 1 : 0 ; //printf("mid[1]=%d\n",mid[1]);
            for(int i=2;i+s-1<=n;i++)
            {
                if(cnt[a[i-1]]==1) num-- ;
                cnt[a[i-1]]-- ;
                if(cnt[a[i-1]]==1) num++ ;
                if(cnt[a[i+s-1]]==1) num-- ;
                cnt[a[i+s-1]]++ ;
                if(cnt[a[i+s-1]]==1) num++ ;
                mid[i]= num==s ? 1 : 0 ;
                    //printf("mid[%d]=%d\n",i,mid[i]);
            }
        }
        int ans=0 ;
        for(int i=1;i<=s && i<=n;i++)
        {
            bool ok=fir[i] ;
            int j ;
            for(j=i+1;j+s-1<=n;j+=s) ok &= mid[j] ;
            ok &= last[n-j+1] ;
            ans+=ok ;
        }
        if(s>n && fir[n]) ans+=s-n ;
        printf("%d\n",ans) ;
    }
}
