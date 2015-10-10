#include<stdio.h>
int a[1000001],left[1000001],right[1000001];
main()
{
 int N,NN,n,i,j,ans;
 ans=0 ;
 scanf("%d",&n) ;
 for(i=1;i<=n;i++) scanf("%d",&a[i]);
 a[0]=1000000001 ; a[n+1]=1000000001 ;
 for(i=1;i<=n;i++)
    {
     if(a[i-1]>a[i]) left[i]=i-1 ;
     else if(a[left[i-1]]>a[i]) left[i]=left[i-1] ;
     else 
        {
        for(j=left[i-1];a[j]<=a[i];j--);
        left[i]=j ;
        }
    if(a[n+2-i]>a[n+1-i]) right[n+1-i]=n+2-i ;
    else if(a[right[n+2-i]]>a[n+1-i]) right[n+1-i]=right[n+2-i] ;
    else
        {
        for(j=right[n+2-i];a[j]<=a[n+1-i];j++);
        right[n+1-i]=j ;
        }
    }
 for(i=1;i<=n;i++)
    {
    for(j=i+1;(j<=right[i])&&(j<=n);j++) if(left[j]<=i) ans+=1 ;
    }
 printf("%d\n",ans*2);
}
