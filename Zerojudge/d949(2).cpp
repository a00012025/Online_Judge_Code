#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int n,a[605],b[605] ;

bool vis[605] ;
bool check(int x)
{
    memset(vis,0,sizeof(vis)) ;
    int num1=0,num2=0,w_num1=0,w_num2=0,w_day1=0,w_day2=0 ;
    for(int i=1;i<=n;i++)
    {
        num1 += a[i] ; num2 += b[i] ;
        if(num1>x)
        {
            while(num1>x)
            {
                while((!w_num1 || vis[w_day1]) && w_day1<=i && w_day1<n)
                {
                    w_num1 += a[w_day1+1] ;
                    w_day1++ ;
                    if(w_num1>x) return 0 ;
                }
                if(w_day1==i+1) return 0 ;
                w_num1-- ; num1-- ;
                vis[w_day1]=1 ;
            }
        }
        if(num2>x)
        {
            while(num2>x)
            {
                while((!w_num2 || vis[w_day2]) && w_day2<=i && w_day2<n)
                {
                    w_num2 += b[w_day2+1] ;
                    w_day2++ ;
                    if(w_num2>x) return 0 ;
                }
                if(w_day2==i+1) return 0 ;
                w_num2-- ; num2-- ;
                vis[w_day2]=1 ;
            }
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
        for(int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]) ;
        if(n==1) {printf("%d\n",max(a[1],b[1])) ; continue ;}
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

