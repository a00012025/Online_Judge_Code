#include<stdio.h>
#include<iostream>
using namespace std;
const int maxn=100000 ;
int n,tc=0,a[maxn+10] ;
main()
{
while(scanf("%d",&a[1])==1)
{
    if(a[1]==-1) break ;
    for(n=1;scanf("%d",&a[n+1])==1 && a[n+1]!=-1;n++) ;
    for(int i=1;i<=n;i++) a[i]=-a[i] ;
    int tmp[maxn+10]={0},length=1 ;
    for(int i=1;i<=n;i++)
    {
        if(i==1){tmp[1]=a[1] ; continue ;}
        if(tmp[length]<a[i]) {length++ ; tmp[length]=a[i] ; continue ;}
        int l=0,r=length ;
        while(r-l>1)
        {
            int mid=(l+r)/2 ;
            if(tmp[mid]>=a[i]) r=mid ;
            else l=mid ;
        }
        tmp[l+1]=min(tmp[l+1],a[i]) ;
    }
    if(tc) printf("\n\n") ;
    printf("Test #%d:\n  maximum possible interceptions: %d",++tc,length) ;
 }
}

