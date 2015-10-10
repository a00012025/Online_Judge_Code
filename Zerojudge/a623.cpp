#include<stdio.h>
#include<string.h>
int f(int n)
{
 int m=1,ans=0;
 for(m=1;m<=n;m=m*10) ans+=1;
 return ans;
}
main()
{
 int m,n,i,j,k,l,num,div,divv,no;
 int jj,kk;
 int N[10000],quo[10000];
 memset(N,0,sizeof(N));
 memset(quo,0,sizeof(quo));
 while(scanf("%d %d",&n,&m)==2)
 {
 memset(N,0,sizeof(N));
 memset(quo,0,sizeof(quo));
 N[1]=1;
 for(i=m+1;i<=n;i++)
    {
    for(j=9999;N[j]==0;j--);
    for(k=j;k>=1;k--) N[k]*=i;
    for(k=1;k<=j+2;k++)
        {
        if(N[k]>=10)
            {
            N[k+1]+=N[k]/10;
            N[k]=N[k]-((N[k]/10)*10);
            }
        }
    }
 for(i=2;i<=n-m;i++)
    {
    j=9999;
    num=f(i);
    no=1;
    while(j>=num)
        {
        if(no==1) {for(j=9999;N[j]==0;j--);no=0;}
        div=0;
        for(k=j;k>j-num;k--)
            {
            div=div*10;
            div+=N[k];
            }
        k=k+1; 
        if(div<i)
            {
            k=k-1;
            div=div*10;
            div+=N[k]; 
            }
        for(l=k;l<=j;l++) N[l]=0; 
        if(k==j-num+1)
            {
            quo[j-num+1]=div/i;
            div=div%i;
            divv=div;
            for(l=j-num+1;l<=j-num+f(div);l++)
                {
                N[l]=divv%10;
                divv=divv/10;
                }
            }
        else if(k==j-num)
            {
            quo[j-num]=div/i;
            div=div-((div/i)*i);
            divv=div;
            for(l=j-num;l<=j-num+f(div)-1;l++)
                {
                N[l]=divv%10;
                divv=divv/10;
                }
            }
    for(j=num+k+5;N[j]==0;j--);
    }
    for(j=9999;quo[j]==0;j--);
    for(k=j;k>=1;k--) N[k]=quo[k];
    memset(quo,0,sizeof(quo));
    }
 for(j=9999;N[j]==0;j--);
 for(k=j;k>=1;k--)printf("%d",N[k]);
 printf("\n");
 }
}
