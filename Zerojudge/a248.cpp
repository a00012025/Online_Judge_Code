#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int f(int n)
{
 int m=1,ans=0;
 for(m=1;m<=n;m=m*10) ans+=1;
 return ans;
}
main()
{
 int a[20001],b[20001],r[20001],div[20001],quo[20001];
 int i,j,k,l,num,zzz=0,x,y,N;
 char s[100],t,u[100];
 while(scanf("%d %d %d",&x,&y,&N)!=EOF)
    {
    memset(a,0,sizeof(a)) ;
    memset(b,0,sizeof(b)) ;
    i=0 ;
    while(x!=0){
        i=i+1 ; a[i]=x%10 ; x=x/10 ;
        }
    i=0 ;
    while(y!=0){
        i=i+1 ; b[i]=y%10 ; y=y/10 ;
        }
    for(i=20000;(a[i]==0)&&(i>=1);i--);
    if(i==0){printf("0\n");continue;}
    memset(div,0,sizeof(div));
    memset(quo,0,sizeof(quo));
    for(num=20000;b[num]==0;num--);
    i=20000;
    while(i>num-1)
        {
        for(i=20000;a[i]==0;i--);
        for(k=1;k<=99;k++)
            {
            memset(div,0,sizeof(div));
            for(l=1;l<=num;l++) div[l]=b[l]*k;
            for(l=1;l<=num+2;l++)
                {
                if(div[l]>=10)
                    {
                    div[l+1]+=div[l]/10;
                    div[l]=div[l]%10;
                    }
                }
            for(l=num+1;(a[l-num-1+i]==div[l])&&(l>=1);l--);
            if((div[l]>a[l-num-1+i])||(l==0)) break;
            }
        if(l!=0) k=k-1;
        memset(div,0,sizeof(div));
        for(l=1;l<=num;l++) div[l]=b[l]*k;
        for(l=1;l<=num+2;l++)
            {
            if(div[l]>=10)
                {
                div[l+1]+=div[l]/10;
                div[l]=div[l]%10;
                }
            }
        for(l=i-num;l<=i;l++) a[l]=a[l]-div[l-i+num+1];
        for(l=i-num;l<=i+3;l++)
            {
            if(a[l]<0)
                {
                a[l]+=10;
                a[l+1]+=-1;
                }
            }
        quo[i-num+1]=k/10;
        quo[i-num]=k%10;
        for(i=20000;a[i]==0;i--);
        }
    for(k=20000;quo[k]==0;k--);
    for(l=k;l>=1;l--)printf("%d",quo[l]);
    printf("\n");
    }
}
