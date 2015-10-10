#include<stdio.h>
#include<string.h>
using namespace std;
int a[1000001],b[1000001],fir[1000001],yes[1000001] ;
bool c[1000001] ;
bool check(int n)
{
 memset(c,0,sizeof(c)) ;
 if(n==1) {c[a[1]]=1 ; return 1;}
 bool exit=0 ;
 for(int r=1;r<=n;r++)
    {
    if(c[a[r]]==1) exit=1;
    else c[a[r]]=1 ;
    }
 if(exit==1) return 0;
 else return 1;
}
main()
{
 int T;
 scanf("%d",&T);
 while(T--)
 {
 memset(a,0,sizeof(a)) ;
 memset(b,0,sizeof(b)) ;
 memset(yes,0,sizeof(yes)) ;
 int n,m ;
 scanf("%d %d",&n,&m) ;
 for(int i=0;i<=m+1;i++) fir[i]=-1 ;
 for(int i=1;i<=n;i++) {scanf("%d",&a[i]) ; yes[a[i]]=1 ;}
 for(int i=1;i<=m;i++)
    {
    if(yes[i]==0) continue ;
    int j;
    for(j=(i%m)+1;(j!=i)&&(yes[j]==1);j=(j%m)+1) ;
    if(j!=i) fir[i]=j ;
    }
            /*for(int i=1;i<=m;i++) printf("%d,",yes[i]) ;
            printf("\n") ;
            for(int i=1;i<=m;i++) printf("%d,",fir[i]) ;
            printf("\n\n") ;*/
 int num=0 ;
 while(1)
    {
    if(fir[a[n-num]]>a[n-num])
        {
                    //printf("chech(%d)=%d\n",n-num-1,check(n-num-1));
        if(check(n-num-1)==0) {
            if(c[a[n-num]]==1) {num++ ; continue ;}
            yes[a[n-num]]=0 ;
            fir[a[n-num]]=-1 ;
            int i;
            if(a[n-num]==1) i=m ;
            else i=a[n-num]-1 ;
            for(; yes[i]==1 ; i=i-1) 
                    {fir[i]=a[n-num]; if(i==1) i=m+1 ;}
            num++ ; 
                    /*for(int r=1;r<=m;r++) printf("%d,",yes[r]) ;
                    printf("\n") ;
                    for(int r=1;r<=m;r++) printf("%d,",fir[r]) ;
                    printf("\nnum=%d\n\n",num) ;*/
            continue ;
            }
        if(c[a[n-num]]==0) yes[a[n-num]]=0 ;
        else yes[a[n-num]]=1 ;
        for(int z=1;z<=n-num-1;z++) b[z]=a[z] ;
        b[n-num]=fir[a[n-num]] ;
        yes[fir[a[n-num]]]=1 ;
        for(int j=1;j<=m;j++) {
            if(yes[j]==1) continue ;
            b[n-num+1]=j ;
            num-- ;
            if(num==0) break;
            }
        break ;
        }
    else
        {
        yes[a[n-num]]=0 ;
        fir[a[n-num]]=-1 ;
        int i;
        if(a[n-num]==1) i=m ;
        else i=a[n-num]-1 ;
        for(; yes[i]==1 ; i=i-1) 
                {fir[i]=a[n-num]; if(i==1) i=m+1 ;}
        num+=1 ;
            /*for(int r=1;r<=m;r++) printf("%d,",yes[r]) ;
            printf("\n") ;
            for(int r=1;r<=m;r++) printf("%d,",fir[r]) ;
            printf("\nnum=%d\n\n",num) ;*/
        }
    }
 for(int i=1;i<=n;i++) printf("%d ",b[i]) ;
 printf("\n") ;
 }
}
