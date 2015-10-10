#include<stdio.h>
#include<string.h>
int a[10][10];
int correct()
{
 int i,j,P,p0,q0;
 for(i=1;i<=9;i++)
    {
    P=1;
    for(j=1;j<=9;j++) P*=a[i][j];
    if(P!=362880) return 0;
    P=1;
    for(j=1;j<=9;j++) P*=a[j][i];
    if(P!=362880) return 0;
    }
 for(i=1;i<=3;i++) for(j=1;j<=3;j++)
    {
    p0=((i-1)/3)*3+1 ; q0=((j-1)/3)*3+1 ;
    P=a[p0][q0]*a[p0+1][q0]*a[p0+2][q0]*a[p0][q0+1]*a[p0+1][q0+1]*a[p0+2][q0+1]*a[p0][q0+2]*a[p0+1][q0+2]*a[p0+2][q0+2];
    if(P!=362880) return 0;
    }
 return 1;
}
main()
{
 int n,i,j;
 while(scanf("%d",&a[1][1])==1)
 {
 for(i=1;i<=9;i++) for(j=1;j<=9;j++)
    {
    if((i==1)&&(j==1)) continue;
    scanf("%d",&n);
    a[i][j]=n;
    }
 if(correct()==1) printf("yes\n");
 else printf("no\n");
 }
}
