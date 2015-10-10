#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct seg{int r,num;};
int n,a[605],b[605],suma[605],sumb[605] ;

bool check(int x)
{
    vector<seg> sa,sb ;
    for(int i=1;i<n;i++)
    if(a[i+1] && suma[i+1]>x)
    {
        if(i < suma[i+1]-x) return 0 ;
        sa.push_back((seg){i,suma[i+1]-x}) ;
            //if(x==28)printf("sa : %d,%d\n",i,suma[i+1]-x);
    }
    for(int i=1;i<n;i++)
    if(b[i+1] && sumb[i+1]>x)
    {
        if(i < sumb[i+1]-x) return 0 ;
        sb.push_back((seg){i,sumb[i+1]-x}) ;
            //if(x==28)printf("sb : %d,%d\n",i,sumb[i+1]-x);
    }
    int nowa=0,nowb=0,i=0,j=0 ;
    while(i<sa.size() || j<sb.size())
    {
        if(j==sb.size() || (i!=sa.size() && sa[i].r<=sb[j].r))
        {
            if(nowa+(sa[i].r - (nowa+nowb)) < sa[i].num) return 0 ;
            nowa = sa[i].num ; i++ ;
        }
        else
        {
            if(nowb+(sb[j].r - (nowa+nowb)) < sb[j].num) return 0 ;
            nowb = sb[j].num ; j++ ;
        }
    }
    return 1 ;
}

main()
{
    int T ;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d",&n) ;
        suma[0]=sumb[0]=0 ;
        for(int i=1;i<=n;i++) {scanf("%d%d",&a[i],&b[i]) ; suma[i]=suma[i-1]+a[i] ; sumb[i]=sumb[i-1]+b[i] ;}
        if(n==1) {printf("%d\n",max(a[1],b[1])) ; continue ;}
        int i,j ;
        for(i=1;i<=n && !a[i];i++) ; i-- ;
        for(j=1;j<=n && !b[j];j++) ; j-- ;
        if(i || j)
        {
            if(i<j)
            {
                for(int k=1;k+j<=n;k++) a[k]= k==1 ? suma[j+1]-(j-i) : a[k+j] ;
                for(int k=1;k+j<=n;k++) b[k]=b[k+j] ;
                n-=j ;
            }
            else if(i>j)
            {
                for(int k=1;k+i<=n;k++) b[k]= k==1 ? sumb[i+1]-(i-j) : b[k+i] ;
                for(int k=1;k+i<=n;k++) a[k]=a[k+i] ;
                n-=i ;
            }
            else
            {
                for(int k=1;k+i<=n;k++) {a[k]=a[k+i] ; b[k]=b[k+i] ;}
                n-=i ;
            }
        }
        if(n==1) {printf("%d\n",max(a[1],b[1])) ; continue ;}
        //for(int i=1;i<=n;i++) printf("%d,%d\n",a[i],b[i]) ;
        for(int i=1;i<=n;i++) {suma[i]=suma[i-1]+a[i] ; sumb[i]=sumb[i-1]+b[i] ;}
        int l=0 , r=7000 ;
        while(r-l>1)
        {
            int mid=(r+l)/2 ;
            if(check(mid)) r=mid ;
            else l=mid ;
        }
        printf("%d\n",r) ;
    }
}
