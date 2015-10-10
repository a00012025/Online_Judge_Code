#include<stdio.h>
#include<string.h>
using namespace std;
int a[1000010];
main()
{
 int n,m,i,j,pow,lengh,div,pow2,I,zz;
 int A;
 char s[1000100];
 scanf("%d",&n);
 for(zz=1;zz<=n;zz++)
 {
 gets(s);
 if(s[0]==0) gets(s);
    {
    memset(a,-1,sizeof(a));
    for(i=0;s[i]!=0;i++);
    for(j=i-1;j>=0;j--) 
        {
        a[-j+i]=s[j]-'0' ;
        /*printf("%d,",a[-j+i]);*/
        }
    m=360;
    pow=3;
    lengh=i;
    /*printf("lengh=%d,pow=%d\n",lengh,pow);*/
    /*for(lengh=1;a[lengh]!=-1;lengh++) ;
    lengh+=-1;*/
    while(lengh>pow)
        {
        /*printf("%d,%d\n",lengh,pow);*/
        A=0;
        for(j=1;j<=pow+1;j++)
            {
            A=A*10;
            A+=a[lengh-j+1];
            /*printf("%d,",a[lengh-j+1]);*/
            }
        /*printf("A=%d,\n",A);*/
        for(i=1;i<=99;i++)
            {
            div=m*i;
            if(A<div) break;
            }
        i=i-1;
        A=A-(m*i);
        /*printf("- %d\n",m*i);*/
        /*if(i==8)printf("\n\n%d\n\n",A);*/
        j=lengh-pow-1;
        while(A!=0)
            {
            j+=1;
            a[j]=A-A/10*10;
            A=A/10;
            }
        for(i=j+1;a[i]!=-1;i++) a[i]=-1;
        for(lengh=1;a[lengh]!=-1;lengh++);
        lengh=lengh-1;
        }
    A=0;
    for(i=lengh;i>=1;i--)
        {
        A=A*10;
        A+=a[i];
        }
    if(a[1]==-1)printf("0\n");
    else printf("%d\n",A%m);
    }
}
}
