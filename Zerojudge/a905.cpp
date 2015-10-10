#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
const int maxn=200000 ;
int a[maxn+10],tmp[maxn+10] ;
main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int n,m ;
        scanf("%d %d",&n,&m) ;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[2*i]) ;
            a[(2*i)-1]=2*a[2*i] ;
        }
        memset(tmp,0,sizeof(tmp)) ;  int num=0 ;
        for(int i=1;i<=2*n;i++)
        {
            if(a[i]<m) continue ;
            if(num==0){num++ ; tmp[1]=a[i] ; continue ;}
            if(a[i]>=tmp[num]) {num++ ; tmp[num]=a[i] ; continue;}
            int l=0,r=num ;
            while(r-l>1)
            {
                int mid=(l+r)/2 ;
                if(tmp[mid]>a[i]) r=mid ;
                else l=mid ;
            }
            tmp[l+1]=min(tmp[l+1],a[i]) ;
        }
        printf("%d\n",num) ;

    }
}
