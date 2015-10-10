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
 int a[201],b[201],r[201],div[201],quo[201];
 int i,j,k,l,num,zzz=0;
 char s[100],t,u[100];
 while(gets(s))
    {
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(r,0,sizeof(r));
    for(i=0;(s[i]>='0')&&(s[i]<='9');i++);
    for(j=0;j<=i-1;j++) a[j+1]=s[i-1-j]-'0';
    gets(s);
    t=s[0];
    gets(s);
    for(i=0;(s[i]>='0')&&(s[i]<='9');i++);
    for(j=0;j<=i-1;j++) b[j+1]=s[i-1-j]-'0';
    if(t=='*')
    {
        for(i=200;(a[i]==0)&&(i>=1);i--);
        for(j=200;(b[j]==0)&&(j>=1);j--);
        if((i==0)||(j==0)) {printf("0\n");continue;}
        memset(r,0,sizeof(r));
        for(i=1;i<=200;i++)
            {
            for(j=i;j>=1;j--) r[i]+=a[j]*b[i+1-j];
            }
        for(j=150;r[j]==0;j--);
        for(i=1;i<=j+4;i++)
            {
            if(r[i]>=10)
                {
                r[i+1]+=r[i]/10;
                r[i]=r[i]%10;
                }
            }
        for(j=200;r[j]==0;j--);
        for(i=j;i>=1;i--) printf("%d",r[i]);
        printf("\n");
        }
    else if(t=='/')
        {
        for(i=200;(a[i]==0)&&(i>=1);i--);
        if(i==0){printf("0\n");continue;}
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
            quo[i-num+1]=k/10;
            quo[i-num]=k%10;
            for(i=200;a[i]==0;i--);
            }
        for(k=200;quo[k]==0;k--);
        for(l=k;l>=1;l--)printf("%d",quo[l]);
        printf("\n");
        }
    }
}
