#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{
 int a[2001],b[2001],r[2001],div[2001],quo[2001];
 int i,j,k,l,num,m,n,neg;
 char s[2001];
 while(gets(s))
    {
    neg=0;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(r,0,sizeof(r));
    for(m=0;s[m]!=' ';m++);
    for(n=m+3;s[n]!='\0';n++);
    for(i=0;i<=m-1;i++) a[m-i]=s[i]-'0';
    for(i=m+3;i<=n-1;i++) b[n-i]=s[i]-'0';
    if(s[m+1]=='+')
        {
        for(i=1;i<=2000;i++) r[i]=a[i]+b[i];
        for(i=1;i<=1999;i++)
            {
            if(r[i]>=10)
                {
                r[i+1]+=r[i]/10;
                r[i]=r[i]%10;    
                }
            }
        for(i=2000;r[i]==0;i--);
        for(j=i;j>=1;j--)printf("%d",r[j]);
        printf("\n");
        }
    else if(s[m+1]=='-')
        {
        for(i=1;i<=2000;i++) r[i]=a[i]-b[i];
        for(i=1;i<=1999;i++)
            {
            if(r[i]<0)
                {
                r[i+1]-=1;
                r[i]=r[i]+10;    
                }
            }

        if(r[2000]<0)
            {
            for(i=2;i<=1999;i++) r[i]=9-r[i];
            r[1]=10-r[1];
            r[2000]=0;
            neg=1;
            }
        if(neg==1) printf("-");
        for(i=2000;r[i]==0;i--);
        for(j=i;j>=1;j--)printf("%d",r[j]);
        printf("\n");
        }
    else if(s[m+1]=='*')
        {
        for(i=1;i<=2000;i++)
            {
            for(j=i;j>=1;j--) r[i]+=a[j]*b[i+1-j];
            }
        for(j=1999;r[j]==0;j--);
        for(i=1;i<=j+4;i++)
            {
            if(r[i]>=10)
                {
                r[i+1]+=r[i]/10;
                r[i]=r[i]%10;
                }
            }
        for(j=2000;r[j]==0;j--);
        for(i=j;i>=1;i--) printf("%d",r[i]);
        printf("\n");
        }
    else if(s[m+1]=='/')
        {
        memset(div,0,sizeof(div));
        memset(quo,0,sizeof(quo));
        for(num=200;b[num]==0;num--);
        i=200;
        while(i>num-1)
            {
            for(i=200;a[i]==0;i--);
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
            for(i=200;a[i]==0;i--);
            }
        for(k=200;(quo[k]==0)&&(k>=1);k--);
        if(k==0)printf("0\n");
        else 
            {
            for(l=k;l>=1;l--)printf("%d",quo[l]);
            printf("\n");
            }
        }
    }
}
