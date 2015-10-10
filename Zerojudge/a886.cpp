#include<stdio.h>
#include<string.h>
main()
{
 int NN,N,a,b,h,i,j,x,ans;
 bool noeat[51][51] ;
 while(scanf("%d",&NN)==1)
 {
 for(N=1;N<=NN;N++)
 {
 memset(noeat,0,sizeof(noeat));
 ans=0;
 scanf("%d %d %d",&a,&b,&h);
 for(i=1;i<=a;i++) for(j=1;j<=b;j++)
    {
    scanf("%d",&x);
    if(x==1)
        {
        if(noeat[i][j]==0) {noeat[i][j]=1 ; ans+=1;}
        if((i+1<=a)&&(noeat[i+1][j]==0)) {noeat[i+1][j]=1 ; ans+=1;}
        if((i-1>=1)&&(noeat[i-1][j]==0)) {noeat[i-1][j]=1 ; ans+=1;}
        if((j+1<=b)&&(noeat[i][j+1]==0)) {noeat[i][j+1]=1 ; ans+=1;}
        if((j-1>=1)&&(noeat[i][j-1]==0)) {noeat[i][j-1]=1 ; ans+=1;}
        }
    }
 printf("%d\n",(a*b*h)-(ans*3)) ;
 }
 }
}
