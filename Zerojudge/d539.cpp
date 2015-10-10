#include<stdio.h>
int a[1000001];
main()
{
 int T,N,k,i,j,max[1001],m,x,y,x1,y1,ans;
 while(scanf("%d",&N)==1)
 {
 for(i=1;i<=1000;i++) max[i]=0 ;
 for(k=1;k*k<N;k++) ; k=k-1 ;
 for(i=1;i<=N;i++)
    {
    scanf("%d",&a[i]);
    if(a[i]>max[((i-1)/k)+1]) max[((i-1)/k)+1]=a[i];
    }
 scanf("%d",&T);
 for(i=1;i<=T;i++)
    {
    scanf("%d %d",&x,&y);
    if(x>y)
    	{
    	x1=x ;
    	x=y ;
    	y=x1 ;
    	}
    ans=0 ;
    x1=(((x-1)/k)+1)*k ;
    y1=(y/k)*k ;
    if(y1<=x1) {for(j=x;j<=y;j++) {if(a[j]>ans) ans=a[j];}}
    else
        {
        for(j=x;j<=x1;j++) if(a[j]>ans) ans=a[j];
        for(j=y;j>=y1;j--) if(a[j]>ans) ans=a[j];
        for(j=(x1/k)+1;j<=(y1/k);j++) if(max[j]>ans) ans=max[j];
        }
    printf("%d\n",ans);
    }
 }
}
