#include<stdio.h>
#include<string.h>
main()
{
 bool r[101][101][101];
 int N,NN,a,b,c,i,j,k,ans;
 char s;
 while(scanf("%d",&NN)==1)
 {
 for(N=1;N<=NN;N++)
 {
 memset(r,0,sizeof(r));
 ans=0;
 scanf("%d %d %d",&a,&b,&c);
 for(i=1;i<=b;i++) for(j=1;j<=a;j++)
    {
    scanf("%c",&s); while(s==10) scanf("%c",&s);
    if(s=='.') for(k=1;k<=c;k++)r[a+1-j][i][k]=1 ;
    }
 for(i=1;i<=c;i++) for(j=1;j<=b;j++)
    {
    scanf("%c",&s); while(s==10) scanf("%c",&s);
    if(s=='.') for(k=1;k<=a;k++) r[k][j][c+1-i]=1 ;
    }
 for(i=1;i<=c;i++) for(j=1;j<=a;j++)
    {
    scanf("%c",&s); while(s==10) scanf("%c",&s);
    if(s=='.') for(k=1;k<=b;k++) r[a+1-j][k][c+1-i]=1 ;
    }
 for(i=1;i<=a;i++) for(j=1;j<=b;j++) for(k=1;k<=c;k++)
    {
    if(r[i][j][k]==0) ans+=1;
    }
 printf("%d\n",ans);
 }
 }
}
