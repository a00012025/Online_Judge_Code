#include<stdio.h>
#include<iostream>
using namespace std;
const int maxn=100000 ;
int n,a[maxn+10],b[maxn+10],inv[maxn+10] ;
main()
{
 scanf("%d",&n) ;
 for(int i=1;i<=n;i++)
 {
     int x;
     scanf("%d",&x) ;
     inv[x]=i ;
 }
 while(1)
 {
    if(scanf("%d",&b[1])==EOF) break ;
    for(int i=2;i<=n;i++) scanf("%d",&b[i]) ;
    for(int i=1;i<=n;i++) a[i]=b[inv[i]] ;
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
    printf("%d\n",length) ;
 }
}
