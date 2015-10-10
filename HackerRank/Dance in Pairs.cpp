#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

int a[maxn],b[maxn] ;
int main()
{
    int n,k ; scanf("%d%d",&n,&k) ;
    for(int i=0;i<n;i++) scanf("%d",&a[i]) ;
    for(int i=0;i<n;i++) scanf("%d",&b[i]) ;
    sort(a,a+n) ; sort(b,b+n) ;
    int ans=0 ;
    for(int i=0,j=0;i<n && j<n;i++)
    {
        if(b[j]>a[i]+k) continue ;
        while(j<n && b[j]<a[i]-k) j++ ;
        if(j<n && b[j]<=a[i]+k) j++ , ans++ ;
    }
    printf("%d\n",ans) ;
}
