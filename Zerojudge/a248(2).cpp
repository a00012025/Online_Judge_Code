#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
 int a[10011],b[10011],r[10011],div[10011],quo[10011];
 int i,j,k,l,num,m,n,neg,x,y,N;
 while(scanf("%d %d %d",&x,&y,&N)==3)
    {
    memset(a,0,sizeof(a)) ;
    memset(b,0,sizeof(b)) ;
    i=N ;
    while(x!=0){
        i=i+1 ; a[i]=x%10 ; x=x/10 ;
        }
    i=0 ;
    while(y!=0){
        i=i+1 ; b[i]=y%10 ; y=y/10 ;
        }
    memset(div,0,sizeof(div));
    memset(quo,0,sizeof(quo));
    for(num=10010;b[num]==0;num--);    
    i=10010;
    while(i>num-1)
        {
        for(i=10010;a[i]==0;i--);
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
        if(k>=10) quo[i-num+1]=k/10;
        quo[i-num]=k%10;
        for(i=10010;a[i]==0;i--);
        }
    for(k=10010;(quo[k]==0)&&(k>=1);k--);
    if(k==0)printf("0\n");
    else 
        {
        if(N>=k) printf("0.") ;
        for(int r=1;r<=N-k;r++) printf("0") ;
        for(l=k;l>=1;l--){printf("%d",quo[l]) ; if(l==N+1)printf(".");}
        printf("\n");
        }    
    }
}
